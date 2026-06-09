#pragma once
#include "GameWorld.h"
#include "Renderer.h"
#include "HUDRenderer.h"

class GameController{
public:
    GameController(int screenW,int screenH);
    void update();
    void render();
    bool shouldClose() const;

private:
    int screenWidth, screenHeight;
    GameWorld world;
    Renderer renderer;
    HUDRenderer hudRenderer;
};
