
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
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

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

	// NOTE(brett): do this once right now as we only have one shader;
	GLint ProjectionLocation = glGetUniformLocation(shader, "projection");
	GLint ViewLocation = glGetUniformLocation(shader, "view");
	GLint ModelLocation = glGetUniformLocation(shader, "model");
	GLint LightLocation = glGetUniformLocation(shader, "lightpos");

	float angle = 90.0f;

	GameState gameState = {};
	int counter = 0;
	for(int i = -5; i < 5; i++)
	{
		for(int j = -5; j < 5; j++)
		{
			Mesh m = {};
			prefab_cube(&m, glm::vec3(j*50.f+25.f, 0.f, i*50.f+25.f), ZERO, glm::vec3(50.f, 50.f, 50.f), &shader);
			gameState.world[counter].mesh = m;
			counter += 1;
		}
	}


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
					LightLocation = glGetUniformLocation(shader, "lightpos");

					#ifdef DEBUG_BUILD
					std::cout << "ProjectionLocation: " << ProjectionLocation 	<< std::endl;
					std::cout << "ViewLocation: " 		<< ViewLocation 		<< std::endl;
					std::cout << "ModelLocation: " 		<< ModelLocation 		<< std::endl;
					std::cout << "LightLocation: " 		<< LightLocation 		<< std::endl;
					#endif
				}

				if(event.key.keysym.sym == SDLK_w)
				{
					masterGame.camera_position.y += 1;
					if(masterGame.camera_position.y > 8)
						masterGame.camera_position.y = 8;
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

			if(event.type == SDL_MOUSEMOTION)
			{
				glm::vec3 ray = glm::unProject(glm::vec3(event.motion.x, 600 - event.motion.y, 0.f),
											   masterGame.View(),
											   masterGame.projection,
											   glm::vec4(0, 0, 800, 600));

				glm::vec3 ray2 = glm::unProject(glm::vec3(event.motion.x, 600 - event.motion.y, 1.f),
											   masterGame.View(),
											   masterGame.projection,
											   glm::vec4(0, 0, 800, 600));


				glm::vec3 ip = intersectionPlanePoint(NY,
													  glm::vec3(1.f, 25.0f, 1.f),
													  ray,
													  glm::normalize(ray2 - ray));

				static int last_index = -1;

				float sx = ip.x / 50.f;
				float sz = ip.z / 50.f;
				sx = floor(sx + 5);
				sz = floor(sz + 5);
				int index = (int)(sx + sz*10);


				std::cout << "INDEX: " << index << std::endl;
				if(last_index != index)
				{
					if(index >= 0 && index < 100)
					{
						if(last_index >= 0)
							set_color(&gameState.world[last_index].mesh, BLUE);

						set_color(&gameState.world[index].mesh, CYAN);
						last_index = index;
					}
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
														  glm::vec3(1.f, 25.0f, 1.f),
														  ray,
														  glm::normalize(ray2 - ray));

					#ifdef DEBUG_BUILD
					std::cout << "point: " << ip.x << ", " << ip.y  << ", " << ip.z << std::endl;
					#endif


					float sx = ip.x / 50.f;
					float sz = ip.z / 50.f;
					sx = floor(sx + 5);
					sz = floor(sz + 5);
					int index = (int)(sx + sz*10);

					if(index < 0 || index > 100)
						break;

					#ifdef DEBUG_BUILD
					std::cout << "INDEX: " << index << std::endl;
					std::cout << "sx: " << sx << " , sz: " << sz << std::endl;
					std::cout << "POSITION: " << gameState.world[index].mesh.position.x << std::endl;
					#endif

					// set_color(&(gameState.world[index].mesh), YELLOW);

					float ox = gameState.world[index].mesh.position.x;
					float oz = gameState.world[index].mesh.position.z;

					prefab_diamond(&gameState.entities[gameState.entity_sz].mesh, glm::vec3(ox, 55.f, oz), ZERO, glm::vec3(50.f, 50.f, 50.f), &shader);
					gameState.entities[gameState.entity_sz].phys.rotate_vel = glm::vec3(0.f, 2.f, 0.f);
					gameState.entity_sz += 1;

					// TODO(brett): Check the collision of the meshes just to test. Then give D some new meshes for the ai and towers.
				}
			}

		}
		
		glClearColor(0.2, 0.0, 0.2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, (GLfloat *)&masterGame.projection[0]);
		glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, (GLfloat *)&masterGame.View()[0]);
		glUniform3fv(LightLocation, 1, (GLfloat *)&masterGame.camera_position[0]);

		// note(Brett): world size is 100
		for(int i = 0; i < 100; i++)
		{
			glBindVertexArray(gameState.world[i].mesh.VAO);

			glm::mat4 model = glm::mat4();
			model = glm::translate(model, gameState.world[i].mesh.position);
			model = glm::scale(model, gameState.world[i].mesh.scale);

			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, (GLfloat *)&model[0]);

			glDrawArrays(GL_TRIANGLES, 0, gameState.world[i].mesh.vertice_sz);
		}

		for(int i = 0; i < gameState.entity_sz; i++)
		{
			glBindVertexArray(gameState.entities[i].mesh.VAO);

			glm::mat4 model = glm::mat4();
			gameState.entities[i].phys.rotate += gameState.entities[i].phys.rotate_vel;
			gameState.entities[i].mesh.rotation = gameState.entities[i].phys.rotate;

			model = glm::translate(model, gameState.entities[i].mesh.position);
			model = glm::scale(model, gameState.entities[i].mesh.scale);

			model = glm::rotate(model, gameState.entities[i].mesh.rotation.y, gameState.entities[i].mesh.rotation);
			

			glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, (GLfloat *)&model[0]);

			glDrawArrays(GL_TRIANGLES, 0, gameState.entities[i].mesh.vertice_sz);
		}

		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}