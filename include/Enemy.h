#pragma once
#include "GameObject.h"

class Player;
class Enemy:public GameObject{
public:
    float speed;
    int hp;
    int maxHp;
    int damage;

    Enemy(float x,float y,float speed=80.0f, int hp=3);
    void updateChase(float dt,const Player* player);
    void takeDamage(int dmg);
};
