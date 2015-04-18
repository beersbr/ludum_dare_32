#include <SDL2/sdl.h>
#ifndef GAME_H
#define GAME_H

typedef struct
{
    
    unsigned int objectCount;
    unsigned int towerCount;
    void* towerPtrs;
    unsigned int bulletCount;
    void* bulletPtrs;
    unsigned int enemyCount;
    void* enemyPtrs;
} World;

class Game
{
    public:
        Game();
        ~Game();
        void HandleEvent(SDL_Event& event);
        void DoUpdate();
        bool IsRunning();
    private:
        World* curWorld;
        void update();
        bool running;
       
};

#endif