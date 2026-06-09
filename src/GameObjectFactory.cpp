#include "GameObjectFactory.h"
#include <cmath>

std::unique_ptr<Player> GameObjectFactory::createPlayer(float x,float y){
    return std::make_unique<Player>(x,y,200.0f,5);
}
std::unique_ptr<Enemy> GameObjectFactory::createEnemy(float x,float y){
    return std::make_unique<Enemy>(x,y,80.0f,3);
}
std::unique_ptr<Projectile> GameObjectFactory::createProjectile(float fromX,float fromY,float targetX,float targetY){
    float dx=targetX-fromX;
    float dy=targetY-fromY;
    float dist=std::sqrt(dx*dx+dy*dy);
    if(dist>0.0f){
        dx/=dist; 
        dy/=dist; 
    }
    return std::make_unique<Projectile>(fromX,fromY,dx,dy,350.0f,1);
}
