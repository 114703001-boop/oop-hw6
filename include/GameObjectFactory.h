#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include <memory>

class GameObjectFactory{
public:
    static std::unique_ptr<Player> createPlayer(float x, float y);
    static std::unique_ptr<Enemy> createEnemy(float x, float y);
    static std::unique_ptr<Projectile> createProjectile(float fromX, float fromY,float targetX, float targetY);
};
