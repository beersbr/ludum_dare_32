#include "game.h"


Game::Game()
{
    this->running = true;
    this->curWorld = NULL;
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

