#include <SDL2/sdl.h>
#include <glm/glm.hpp>
#ifndef GAME_H
#define GAME_H


enum EnemyType { GOON, GOBLIN, ASSHOLE };
enum TowerType { SHOOTER, SHOTTER, FLOCKA };
enum AmmoType { SHOT, SLOW, FIRE, ROCKET };

typedef struct
{
    glm::vec3 pos;
    glm::vec3 dir;
    glm::vec3 vel;
} Phys;

typedef struct
{
    unsigned int enemyType;
    unsigned int curHealth;
    Phys physics;
} Enemy;

typedef struct
{
    unsigned int ammoType;  //Indicates ammo type, AKA what kind of bullet to put into the world.
    Phys physics;
} Bullet;

typedef struct
{
    unsigned int id;
    unsigned int type; //Type of tower, AKA what kind of tower to put into the world
    AmmoType ammo;     //Ammo type this tower shoots.
    Enemy* target;     //Enemy this tower targets, careful as it can be NULL
    Phys physics;
} Tower;

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

typedef struct
{
    unsigned int x;
    unsigned int y;
    unsigned char button;
    bool isDown;
} MouseState;

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
        MouseState curMouse;
        void update();
        bool running;
};

#endif