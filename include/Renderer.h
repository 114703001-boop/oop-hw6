#pragma once
#include "GameWorld.h"

class Renderer{
public:
    void drawWorld(const GameWorld& world) const;

private:
    void drawPlayer(const Player* player) const;
    void drawEnemy(const Enemy* enemy) const;
    void drawProjectile(const Projectile* proj) const;
    void drawHpBar(float x,float y,float w,int hp,int maxHp,Color fill) const;
};
