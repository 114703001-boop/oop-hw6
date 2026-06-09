#pragma once
#include "GameWorld.h"

class HUDRenderer{
public:
    void draw(const GameWorld& world) const;
    void drawGameOver(const GameWorld& world) const;
};
