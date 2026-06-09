#include "Projectile.h"

Projectile::Projectile(float x,float y,float dx,float dy,float speed,int damage):GameObject(x,y,8.0f,8.0f,YELLOW),dx(dx),dy(dy),speed(speed),damage(damage){}

void Projectile::update(float dt){
    x+=dx*speed*dt;
    y+=dy*speed*dt;
    if(x<-20 || x>820 || y<-20 || y>470){
        isDead=true;
    }
}
