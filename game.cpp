#include "game.h"


Game::Game()
{
    this->running = true;
    this->curWorld = NULL;

    projection = glm::ortho(-400.f, 400.f, -300.f, 300.f, -500.f, 500.f);
    camera_position = glm::vec3(0.0f, 0.0f, 5.0f);
    camera_lookat = ZERO;
    view = View();

    return;
}

Game::~Game()
{

}

void Game::HandleEvent(SDL_Event& event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN:
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_q:
                {
                    this->running = false;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case SDL_QUIT:
        {
            this->running = false;
            break;
        }
        default:
            break;
    }
    
    return;
}

bool Game::IsRunning()
{
    return this->running;
}

void Game::DoUpdate()
{
    return;
}

void Game::update()
{
    return;
}

glm::mat4 Game::View()
{
    view = glm::lookAt(camera_position, camera_lookat, glm::vec3(0.0f, 1.0f, 0.0f));
    return view;
}