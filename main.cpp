
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

	glEnable(GL_DEPTH_TEST);

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	GLuint shader = load_shader_program("shaders/simple.vertex.glsl", "shaders/simple.fragment.glsl");
	glUseProgram(shader);

	Mesh m = {};
	prefab_cube(&m, ZERO, ZERO, glm::vec3(50.f, 50.f, 50.f), &shader);


	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*m.vertice_sz, (GLfloat *)&m.vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, normal)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(offsetof(Vertex, color)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);


	// NOTE(brett): do this once right now as we only have one shader;
	GLint ProjectionLocation = glGetUniformLocation(shader, "projection");
	GLint ViewLocation = glGetUniformLocation(shader, "view");
	GLint ModelLocation = glGetUniformLocation(shader, "model");

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
				}

				if(event.key.keysym.sym == SDLK_a)
				{
					masterGame.camera_position.x -= 1;
				}

				if(event.key.keysym.sym == SDLK_d)
				{
					masterGame.camera_position.x += 1;
				}

			}
		}
        
		glClearColor(0.2, 0.0, 0.2, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, (GLfloat *)&masterGame.projection[0]);
		glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, (GLfloat *)&masterGame.View()[0]);

		glm::mat4 model = glm::mat4();
		model = glm::scale(model, m.scale);

		glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, (GLfloat *)&model[0]);

		glDrawArrays(GL_TRIANGLES, 0, m.vertice_sz);

		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}