#pragma once
#include "raylib.h"

class GameObject{
public:
    float x,y;
    float width,height;
    Color color;
    bool isDead=false; 
    GameObject(float x,float y,float width,float height,Color color);
    virtual ~GameObject()=default;
    virtual void update(float dt)=0;
    Rectangle getRect() const;
};
