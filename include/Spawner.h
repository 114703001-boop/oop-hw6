#pragma once
#include "Enemy.h"
#include "GameObjectFactory.h"
#include <memory>
#include <vector>

class Spawner{
public:
    float spawnInterval;   
    float timer=0.0f;
    int   screenWidth,screenHeight;

    Spawner(int screenW,int screenH,float interval=2.0f);
    std::unique_ptr<Enemy> update(float dt);
};
