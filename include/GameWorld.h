#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Spawner.h"
#include "AutoAttack.h"
#include "CollisionSystem.h"
#include "GameObjectFactory.h"
#include <vector>
#include <memory>

class GameWorld {
public:
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<Projectile>> projectiles;

    int killCount=0;
    float survivalTime=0.0f;
    bool gameOver=false;
    int screenWidth,screenHeight;

    GameWorld(int screenW,int screenH);
    void update(float dt);

private:
    Spawner spawner;
    AutoAttack autoAttack;
    CollisionSystem collisionSystem;
    void removeDeadObjects();
};
