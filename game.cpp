#include "game.h"


Game::Game()
{

    projection = glm::ortho(-400.f, 400.f, -300.f, 300.f, -500.f, 500.f);
    camera_position = glm::vec3(0.0f, 0.0f, 5.0f);
    camera_lookat = ZERO;

    view = View();

    running = true;
    curWorld = NULL;
    curMouse.x = 0;
    curMouse.y = 0;
    curMouse.button = 0;
    curMouse.isDown = false;
    curRound = 0;
    
    rounds = (Round*)malloc(sizeof(Round) * 10);
    Round* tmpRound = rounds;
    
    for(int i = 0; i < 10; i++)
    {
        tmpRound = generateRound();
        tmpRound++;
    }
    
    return;
}

Game::~Game()
{

}

Round* Game::generateRound()
{
    //Initialize some dummy rounds
    //Enemy count will only be one right now
    Round* tmpRound = (Round*)malloc(sizeof(Round));
    tmpRound->enemies = (EnemyCount*)malloc(sizeof(EnemyCount));
    EnemyCount* curEn = tmpRound->enemies;
    curEn->count = 5;
    curEn->EType = GOON;
    curEn->path = (glm::vec3*)malloc(sizeof(glm::vec3) * 3);
    glm::vec3* tmpVec3 = curEn->path;
    tmpVec3->x = 0;     //Path just includes a spawn point, middle point and a goal point, a path should always have two elements;
    tmpVec3->y = 0;
    tmpVec3++;
    tmpVec3->x = 400;
    tmpVec3->y = 300;
    tmpVec3++;
    tmpVec3->x = 800;
    tmpVec3->y = 600;
    return tmpRound;
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

glm::mat4 Game::View()
{
    view = glm::lookAt(camera_position, camera_lookat, glm::vec3(0.0f, 1.0f, 0.0f));
    return view;
}

