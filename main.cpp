
#include <SDL2/sdl.h>
#include <GL/glew.h>
#include <SDL2/sdl_opengl.h>

#include "opengl_stuff.h"
#include "opengl_stuff.cpp"
#include "game.h"
#include "game.cpp"

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

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	GLuint shader = load_shader_program("shaders/simple.vertex.glsl", "shaders/simple.fragment.glsl");

	float square[] = {
		-0.5f,  0.5f, 0.f,
		-0.5f, -0.5f, 0.f, 
		 0.5f,  0.5f, 0.f,
		 0.5f,  0.5f, 0.f,
		-0.5f, -0.5f, 0.f,
		 0.5f, -0.5f, 0.f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, (void *)0);

	while(masterGame.IsRunning())
	{
		SDL_PollEvent(&event);
        
        masterGame.HandleEvent(event);
        
		glClearColor(1.0, 0.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}