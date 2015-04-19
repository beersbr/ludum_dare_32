
#include <SDL2/sdl.h>
#include <GL/glew.h>
#include <SDL2/sdl_opengl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "opengl_stuff.h"
#include "opengl_stuff.cpp"
#include "game.h"
#include "game.cpp"

#include <stddef.h>

int main(int argc, char *argv[])
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		exit(1);
	}
	
	Game masterGame;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);

	SDL_Window *window = SDL_CreateWindow("ludum dare 32",
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  800,
										  600,
										  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	SDL_GLContext gl_context = SDL_GL_CreateContext(window);

	glewExperimental = GL_TRUE;
	glewInit();

	bool running = true;
	SDL_Event event;

	glEnable(GL_MULTISAMPLE);

	glEnable(GL_DEPTH_TEST);

	GLuint shader = load_shader_program("shaders/simple.vertex.glsl", "shaders/simple.fragment.glsl");
	glUseProgram(shader);

	std::vector<Mesh> mesh_list;

	Mesh *mesh_map[10][10];

	for(int i = -5; i < 5; i++)
	{
		for(int j = -5; j < 5; j++)
		{
			Mesh m = {};
			prefab_cube(&m, glm::vec3(i*50.f+25.f, 0.f, j*50.f+25.f), ZERO, glm::vec3(50.f, 50.f, 50.f), &shader);
			mesh_list.push_back(m);
		}
	}

	#ifdef DEBUG_BUILD
	std::cout << "Mesh List Size: " << mesh_list.size() << std::endl;
	#endif

	// NOTE(brett): do this once right now as we only have one shader;
	GLint ProjectionLocation = glGetUniformLocation(shader, "projection");
	GLint ViewLocation = glGetUniformLocation(shader, "view");
	GLint ModelLocation = glGetUniformLocation(shader, "model");

	float angle = 90.0f;

	while(masterGame.IsRunning())
	{
		while(SDL_PollEvent(&event))
		{
			masterGame.HandleEvent(event);

			if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_l)
				{
					shader = load_shader_program("shaders/simple.vertex.glsl", "shaders/simple.fragment.glsl");
					glUseProgram(shader);
					ProjectionLocation = glGetUniformLocation(shader, "projection");
					ViewLocation = glGetUniformLocation(shader, "view");
					ModelLocation = glGetUniformLocation(shader, "model");

					#ifdef DEBUG_BUILD
					std::cout << "ProjectionLocation: " << ProjectionLocation 	<< std::endl;
					std::cout << "ViewLocation: " 		<< ViewLocation 		<< std::endl;
					std::cout << "ModelLocation: " 		<< ModelLocation 		<< std::endl;
					#endif
				}

				if(event.key.keysym.sym == SDLK_w)
				{
					masterGame.camera_position.y += 1;
				}

				if(event.key.keysym.sym == SDLK_s)
				{

					masterGame.camera_position.y -= 1;
					if(masterGame.camera_position.y < 0)
						masterGame.camera_position.y = 0;
				}

				if(event.key.keysym.sym == SDLK_a)
				{
					// masterGame.camera_position.x -= 1;

					angle += 4.5f;
					masterGame.camera_position.x = cos(angle * PI/180.f) * 5.f;
					masterGame.camera_position.z = sin(angle * PI/180.f) * 5.f;
				}

				if(event.key.keysym.sym == SDLK_d)
				{
					// masterGame.camera_position.x += 1;

					angle -= 4.5f;
					masterGame.camera_position.x = cos(angle * PI/180.f) * 5.f;
					masterGame.camera_position.z = sin(angle * PI/180.f) * 5.f;
				}
			}

			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				if( event.button.button == SDL_BUTTON_RIGHT )
				{

					// NOTE(brett): figured it out. Basically we need to unproject two vectors because we are using an ortho NOT
					// a perspective. So the starting point of our ray is NOT at the camera. so we cast a ray at the minimum depth of
					// our view and one at the max length of our view and take the difference. This gives us a vector going from the front
					// to the back. i assume it will work with a perspective as well, though we dont really need to unproject twice for
					// a perspective matrix. The trick was remembering that the depth is a value from 0.0-1.0

					std::cout << "x: " << event.button.x << " y: " << event.button.y << std::endl;
					glm::vec3 ray = glm::unProject(glm::vec3(event.button.x, 600 - event.button.y, 0.f),
												   masterGame.View(),
												   masterGame.projection,
												   glm::vec4(0, 0, 800, 600));

					#ifdef DEBUG_BUILD
					std::cout << "ray: " << ray.x << ", " << ray.y << ", " << ray.z << std::endl;
					#endif

					glm::vec3 ray2 = glm::unProject(glm::vec3(event.button.x, 600 - event.button.y, 1.f),
												   masterGame.View(),
												   masterGame.projection,
												   glm::vec4(0, 0, 800, 600));

					#ifdef DEBUG_BUILD
					std::cout << "ray2: " << ray2.x << ", " << ray2.y << ", " << ray2.z << std::endl;
					#endif

					glm::vec3 ip = intersectionPlanePoint(NY,
														  glm::vec3(1.0f, 0.0f, 1.f),
														  ray,
														  glm::normalize(ray2 - ray));

					#ifdef DEBUG_BUILD
					std::cout << "point: " << ip.x << ", " << ip.y  << ", " << ip.z << std::endl;
					#endif



					// TODO(brett): Check the collision of the meshes just to test. Then give D some new meshes for the ai and towers.
				}
			}

		}
		
		glClearColor(0.2, 0.0, 0.2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for(int i = 0; i < mesh_list.size(); i++)
		{
			glBindVertexArray(mesh_list[i].VAO);

			glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, (GLfloat *)&masterGame.projection[0]);
			glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, (GLfloat *)&masterGame.View()[0]);

			glm::mat4 model = glm::mat4();
			model = glm::translate(model, mesh_list[i].position);
			model = glm::scale(model, mesh_list[i].scale);

			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, (GLfloat *)&model[0]);

			glDrawArrays(GL_TRIANGLES, 0, mesh_list[i].vertice_sz);
		}

		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}