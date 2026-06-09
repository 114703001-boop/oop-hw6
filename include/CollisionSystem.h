#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include <vector>
#include <memory>

class CollisionSystem{
public:
    void checkProjectileEnemy(std::vector<std::unique_ptr<Projectile>>& projectiles,std::vector<std::unique_ptr<Enemy>>& enemies,int& killCount);
    void checkEnemyPlayer(std::vector<std::unique_ptr<Enemy>>& enemies,Player* player);
};
