#pragma once
#include "Projectile.h"
#include "Enemy.h"
#include "GameObjectFactory.h" 
#include <memory>
#include <vector>

class AutoAttack{
public:
    float attackInterval;  
    float timer=0.0f;
    AutoAttack(float interval=0.6f);
    std::unique_ptr<Projectile> update(float dt,const class Player* player,const std::vector<std::unique_ptr<Enemy>>& enemies);
private:
    const Enemy* findNearest(const class Player* player,const std::vector<std::unique_ptr<Enemy>>& enemies);
};
