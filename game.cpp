#include "game.h"


Game::Game()
{
    this->running = true;
    this->curWorld = NULL;
    this->curMouse.x = 0;
    this->curMouse.y = 0;
    this->curMouse.button = 0;
    this->curMouse.isDown = false;
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
        case SDL_MOUSEMOTION:
        {
            //TODO: Cast mouse-ray and check for object intersection
            //Set game's "target object" to whatever we're hovering over
            curMouse.x = event.button.x;
            curMouse.y = event.button.y;
            
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            if( curMouse.isDown )
            {
                break;
            }
            //TODO: Perform action based on target object and game state ( place tower, select object, click UI, etc..)
            if( event.button.button == SDL_BUTTON_LEFT )
            {
                //We have a left mouse click.
                std::cout << "[=] Left mouse click" << std::endl;
                curMouse.isDown = true;
            }
            if( event.button.button == SDL_BUTTON_RIGHT )
            {
                std::cout << "[=] Right mouse click" << std::endl;
                curMouse.isDown = true;
            }
            break;
        }
        case SDL_MOUSEBUTTONUP:
            if(curMouse.isDown)
            {
                curMouse.isDown = false;
            }
            break;
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

