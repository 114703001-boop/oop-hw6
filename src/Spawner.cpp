#include "Spawner.h"
#include <cstdlib>

Spawner::Spawner(int screenW,int screenH,float interval):screenWidth(screenW),screenHeight(screenH),spawnInterval(interval){}

std::unique_ptr<Enemy> Spawner::update(float dt){
    timer+=dt;
    if(timer<spawnInterval){
        return nullptr;
    }
    timer=0.0f;
    float x,y;
    int edge=rand()%4;
    switch(edge){
        case 0: x=(float)(rand()%screenWidth);y=-30.0f;break;
        case 1: x=(float)(rand()%screenWidth);y=(float)screenHeight;break; 
        case 2: x=-30.0f;y=(float)(rand()%screenHeight);break; 
        default:x=(float)screenWidth;y=(float)(rand()%screenHeight);break;
    }

    return GameObjectFactory::createEnemy(x,y);
}
