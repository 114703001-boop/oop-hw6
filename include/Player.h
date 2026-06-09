#pragma once
#include "GameObject.h"

class Player:public GameObject{
public:
    float speed;
    int hp;
    int maxHp;
    float invincibleTimer=0.0f;
    Player(float x,float y,float speed=200.0f,int hp=5);
    void update(float dt) override;
    void takeDamage(int dmg);
    bool isAlive() const;
};
