
#include <SDL2/sdl.h>
#include <SDL2/sdl_opengl.h>

#include "game.h"

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


	bool running = true;
	SDL_Event event;


	while(masterGame.IsRunning())
	{
		SDL_PollEvent(&event);
        
        masterGame.HandleEvent(event);
        
		glClearColor(1.0, 0.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();

	return 0;
}