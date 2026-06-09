#pragma once
#include "GameObject.h"

class Projectile:public GameObject{
public:
    float dx,dy;   
    float speed;
    int damage;

    Projectile(float x,float y,float dx,float dy,float speed=350.0f,int damage=1);
    void update(float dt) override;
};
