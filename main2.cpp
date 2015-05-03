#ifdef _WINDOWS_
#include <Windows.h>
//#pragma message ("using windows")
#endif

#ifndef _WINDOWS_
#include <sys/mman.h>
#endif

#include <SDL2/sdl.h>
#include <GL/glew.h>
#include <SDL2/sdl_opengl.h>
#include <stddef.h>
#include <unordered_map>
#include <iostream>
#include <string>
#include <list>

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "opengl_stuff.h"
#include "opengl_stuff.cpp"

#define KILOBYTE(n) ((n)*1024)
#define MEGABYTE(n) ((n)*1024)
#define GIGABYTE(n) ((n)*1024)
#define TERABYTE(n) ((n)*1024)

typedef void (*updateFn)(void *, float dt);
typedef void (*renderFn)(void *, float dt);

typedef void (*instantiateEntityFn)(Entity *);

typedef struct
{
	void *memory;
	int memory_sz;

	Entity *entities;
	int entities_sz;

	std::list<Entity *> entity_pool_alive;
	std::list<Entity *> entity_pool_limbo;
	std::list<Entity *> entity_pool_dead;

	glm::mat4 projection;
	glm::mat4 view;
	glm::vec3 camera_pos;
	glm::vec3 camera_dir;

	updateFn update;
	renderFn render;

	bool running;

	std::unordered_map<SDL_Keycode, bool> keyboard_state;
	std::unordered_map<SDL_Keycode, bool> keyboard_pressed;

	glm::vec2 mouse_pos;

} GameState;


// NOTE(brett): this method can fail and if it does it returns NULL
static Entity *GetEntity(GameState *game_state)
{
	#if DEBUG_BUILD

	if(!game_state)
		return NULL;

	if(game_state->entity_pool_limbo.size() == 0)
		return NULL;

	#endif

	Entity *e = game_state->entity_pool_limbo.back();
	game_state->entity_pool_limbo.pop_back();
	game_state->entity_pool_alive.push_back(e);
	return e;
}

int main(int argc, char *argv[])
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		exit(1);
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	SDL_Window *window = SDL_CreateWindow("A Game Window",
										  SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED,
										  800,
										  600,
										  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	SDL_GLContext gl_context = SDL_GL_CreateContext(window);

	glewExperimental = GL_TRUE;
	glewInit();

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);

	std::vector<Vertex> grid;

	// GameState setup
	GameState game = {};
	game.memory_sz = MEGABYTE(512);

	#ifndef _WINDOWS_
	game.memory = mmap(0, game.memory_sz,
						  PROT_READ | PROT_WRITE,
						  MAP_ANON | MAP_PRIVATE,
						  -1, 0);
	#endif

	#ifdef _WINDOWS_
	game.memory = VirtualAlloc(NULL,
							   game.memory_sz,
							   MEM_COMMIT | MEM_RESERVE,
							   PAGE_READWRITE );
	#endif

	game.running = true;

	game.projection = glm::ortho(-400.f, 400.f, -300.f, 300.f, -500.f, 500.f);
	game.camera_pos = glm::vec3(0.f, 0.8f, 1.f);
	game.camera_dir = glm::vec3(0.f, 0.f, 0.f);
	game.view = glm::lookAt(game.camera_pos, game.camera_dir, PY);

	game.entities_sz = 512;
	game.entities = (Entity *)game.memory;
	for(int i = 0; i < game.entities_sz; ++i)
	{
		game.entity_pool_limbo.push_back(&game.entities[i]);
	}

	// Shader Setup
	Shader shader = {};
	std::string u[] = { "projection", "view", "model", "lightpos" }; 
	create_shader(&shader, 
				  "shaders/simple.vertex.glsl",
				  "shaders/simple.fragment.glsl",
				  u,
				  4);

	glUseProgram(shader.id);

	// Create an entity
	Entity *e = GetEntity(&game);
	e->position = glm::vec3(0.f, 0.f, 0.f);
	e->scale = 	 glm::vec3(550.f, 550.f, 550.f);
	e->rotation = glm::vec3(0.f, 0.f, 0.f);
	prefab_sphere(&e->mesh, &shader);

	// create a grid
	Entity *e2 = GetEntity(&game);
	e2->position = glm::vec3(0.f, 0.f, 0.f);
	e2->scale =	  glm::vec3(1.f, 1.f, 1.f);
	e2->rotation = glm::vec3(0.f, 0.f, 0.f);

	std::vector<Vertex> verts;
	float size = 100.f;
	float line_dist_scale = 50.f;
	for(int z = 0; z <= size; ++z)
	for(int x = 0; x <= size; ++x)
	{
		// left to right
		verts.push_back({ glm::vec3( -(size*line_dist_scale/2.f), 0.f, (z*line_dist_scale)-(size*line_dist_scale/2.f)), ZERO, WHITE, glm::vec2(0.f, 0.f) });
		verts.push_back({ glm::vec3(  (size*line_dist_scale/2.f), 0.f, (z*line_dist_scale)-(size*line_dist_scale/2.f)), ZERO, WHITE, glm::vec2(0.f, 0.f) });

		// back to front
		verts.push_back({ glm::vec3( (x*line_dist_scale)-(size*line_dist_scale/2.f), 0.f, -(size*line_dist_scale/2.f)), ZERO, WHITE, glm::vec2(0.f, 0.f) });
		verts.push_back({ glm::vec3( (x*line_dist_scale)-(size*line_dist_scale/2.f), 0.f,  (size*line_dist_scale/2.f)), ZERO, WHITE, glm::vec2(0.f, 0.f) });
	}

	// custom_mesh(&e2->mesh, &verts, GL_LINES, &shader);


	SDL_Event event;

	double current_ticks = SDL_GetTicks();
	double previous_ticks = current_ticks;
	double elapsed_ticks = 0;

	while(game.running)
	{
		previous_ticks = current_ticks;
		current_ticks = SDL_GetTicks();
		elapsed_ticks = current_ticks - previous_ticks;

		while(SDL_PollEvent(&event))
		{	
			switch(event.type)
			{
				case SDL_KEYDOWN:
				{
					game.keyboard_state[event.key.keysym.sym] = true;

					if(event.key.keysym.sym == SDLK_w)
					{
						game.camera_pos.z += 1.f;
						game.camera_dir.z += 1.f;

						#ifdef DEBUG_BUILD
						std::cout << "Camera Position: ";
						std::cout << game.camera_pos.x << ", " << game.camera_pos.y << ", " << game.camera_pos.z << std::endl;
						#endif
					}

					if(event.key.keysym.sym == SDLK_s){
						game.camera_pos.z -= 1.f;
						game.camera_dir.z -= 1.f;

						#ifdef DEBUG_BUILD
						std::cout << "Camera Position: ";
						std::cout << game.camera_pos.x << ", " << game.camera_pos.y << ", " << game.camera_pos.z << std::endl;
						#endif
					}

					if(event.key.keysym.sym == SDLK_UP)
					{
						game.camera_pos.y += 0.1f;

						#ifdef DEBUG_BUILD
						std::cout << "Camera Position: ";
						std::cout << game.camera_pos.x << ", " << game.camera_pos.y << ", " << game.camera_pos.z << std::endl;
						#endif
					}

					if(event.key.keysym.sym == SDLK_DOWN)
					{
						game.camera_pos.y -= 0.1f;

						#ifdef DEBUG_BUILD
						std::cout << "Camera Position: ";
						std::cout << game.camera_pos.x << ", " << game.camera_pos.y << ", " << game.camera_pos.z << std::endl;
						#endif
					}

					if(event.key.keysym.sym == SDLK_RIGHT)
					{
						glm::vec3 look = game.camera_pos - game.camera_dir;

						look = glm::rotate({ look.x, 0.f, look.z }, 1.5f, PY);
						game.camera_pos = { look.x, game.camera_pos.y, look.z };

						// game.camera_pos.x -= 0.1f;

						#ifdef DEBUG_BUILD
						std::cout << "Camera Position: ";
						std::cout << game.camera_pos.x << ", " << game.camera_pos.y << ", " << game.camera_pos.z << std::endl;
						#endif
					}

					if(event.key.keysym.sym == SDLK_LEFT)
					{
						glm::vec3 look = game.camera_pos - game.camera_dir;

						look = glm::rotate({ look.x, 0.f, look.z }, -1.5f, PY);
						game.camera_pos = { look.x, game.camera_pos.y, look.z };

						#ifdef DEBUG_BUILD
						std::cout << "Camera Position: ";
						std::cout << game.camera_pos.x << ", " << game.camera_pos.y << ", " << game.camera_pos.z << std::endl;
						#endif
					}

					if(event.key.keysym.sym == SDLK_l)
					{
						reload_shader(&shader, {}, 0);
					}

					if(event.key.keysym.sym == SDLK_g)
					{
						glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
					}


					if(event.key.keysym.sym == SDLK_f)
					{
						glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
					}


					break;
				}
				case SDL_KEYUP:
				{
					game.keyboard_state[event.key.keysym.sym] = false;
					break;
				}
				case SDL_MOUSEMOTION:
				{
					game.mouse_pos.x = event.motion.x;
					game.mouse_pos.y = event.motion.y;
					break;
				}
				case SDL_WINDOWEVENT:
				{
					switch(event.window.event)
					{
						case SDL_WINDOWEVENT_FOCUS_GAINED:
						{
							break;
						}
					}
					break;
				}
				case SDL_QUIT:
				{
					game.running = false;
					break;
				}
			}
		}

		// NOTE(brett): Update code goes here
		

		// NOTE(brett): Render code goes here
		glClearColor(0.1f, 0.0f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw a grid in the x/z coord

		game.view = glm::lookAt(game.camera_pos, game.camera_dir, PY);

		glUniformMatrix4fv(shader.uniforms["projection"], 1, GL_FALSE, (GLfloat *)&game.projection[0]);
		glUniformMatrix4fv(shader.uniforms["view"]		, 1, GL_FALSE, (GLfloat *)&game.view[0]);

		glm::vec3 light = game.camera_pos-game.camera_dir;
		glUniform3fv(shader.uniforms["lightpos"], 1, (GLfloat *)&light);

		for(std::list<Entity *>::iterator it = game.entity_pool_alive.begin();
			it != game.entity_pool_alive.end();
			++it)
		{
			glBindVertexArray((*it)->mesh.VAO);

			glm::mat4 model = glm::mat4();
			model = glm::translate(model, (*it)->position);
			model = glm::scale(model, (*it)->scale);

			glUniformMatrix4fv(shader.uniforms["model"], 1, GL_FALSE, (GLfloat *)&model[0]);

			glDrawArrays((*it)->mesh.draw_method, 0, (*it)->mesh.vertices.size());
		}

		glBindVertexArray(0);

		SDL_GL_SwapWindow(window);
	}

	SDL_Quit();
	return 0;
}