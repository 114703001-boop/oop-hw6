#include "GameObject.h"

GameObject::GameObject(float x,float y,float width,float height,Color color):x(x),y(y),width(width),height(height),color(color){}
Rectangle GameObject::getRect() const{
    return{x,y,width,height};
}
