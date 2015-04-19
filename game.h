#ifndef GAME_H
#define GAME_H
#include <SDL2/sdl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

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
    unsigned int count;
    EnemyType EType;
    glm::vec3* path;
} EnemyCount;

typedef struct
{
    EnemyCount* enemies;
    float   spawnDelay;
} Round;
    
typedef struct
{
    EnemyType enemyType;
    unsigned int curHealth;
    glm::vec3* path;
    Phys physics;
} Enemy;

typedef struct
{
    AmmoType ammoType;  //Indicates ammo type, AKA what kind of bullet to put into the world.
    Phys physics;
} Bullet;

typedef struct
{
    TowerType type; //Type of tower, AKA what kind of tower to put into the world
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

    public:
        glm::vec3 camera_position;
        glm::vec3 camera_lookat;

        // NOTE(brett): camera always points at 0,0,0
        glm::mat4 projection;
        glm::mat4 View();

    private:
        World* curWorld;
        Round* rounds;
        unsigned int curRound;
        MouseState curMouse;
        Round* generateRound();
        void update();
        void startRound();
        bool running;
        glm::mat4 view;
};

#endif