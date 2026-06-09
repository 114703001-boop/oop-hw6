#include "Player.h"

Player::Player(float x,float y,float speed,int hp):GameObject(x,y,36.0f,36.0f,BLUE),speed(speed),hp(hp),maxHp(hp){}

void Player::update(float dt){
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
        y-=speed*dt;
    }
    if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
        y+=speed*dt;
    } 
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        x-=speed*dt;
    }
    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        x+=speed*dt;
    }

    if(x<0){
        x=0;
    }           
    if(y<0){
        y=0;
    } 
    if(x+width>800){
        x=800-width;
    }
    if(y+height>450){
        y=450-height;
    } 

    if(invincibleTimer>0.0f){
        invincibleTimer-=dt; //無敵時間
    } 
}

void Player::takeDamage(int dmg){ //被敵人碰到
    if(invincibleTimer>0.0f){
        return;
    }
    hp-=dmg;
    invincibleTimer=1.0f;       
    if(hp<=0){ 
        hp=0; 
        isDead=true; 
    }
}

bool Player::isAlive() const{
    return hp>0;
}
