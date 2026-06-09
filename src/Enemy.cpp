#include "Enemy.h"
#include "Player.h"
#include <cmath>

Enemy::Enemy(float x, float y, float speed, int hp)
    :GameObject(x,y,30.0f,30.0f,RED),speed(speed),hp(hp),maxHp(hp),damage(1){}

void Enemy::updateChase(float dt,const Player* player){
    if(!player){
        return;
    }
    float dx=(player->x+player->width/2)-(x+width/2); //距離差
    float dy=(player->y+player->height/2)-(y+height/2);
    float dist=std::sqrt(dx*dx+dy*dy);
    if(dist>0.0f){
        x+=(dx/dist)*speed*dt;
        y+=(dy/dist)*speed*dt;
    }
}
void Enemy::takeDamage(int dmg){
    hp-=dmg;
    if(hp<=0){ 
        hp=0; 
        isDead=true; 
    }
}
