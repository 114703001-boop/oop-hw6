#include "GameController.h"

GameController::GameController(int screenW,int screenH):screenWidth(screenW),screenHeight(screenH),world(screenW,screenH){}
void GameController::update(){
    float dt=GetFrameTime();
    if(world.gameOver && IsKeyPressed(KEY_R)){
        world=GameWorld(screenWidth,screenHeight);
        return;
    }
    world.update(dt);
}

void GameController::render(){
    BeginDrawing();
    ClearBackground({20,20,35,255});
    renderer.drawWorld(world);
    hudRenderer.draw(world);
    if(world.gameOver){
        hudRenderer.drawGameOver(world);
    }
    EndDrawing();
}

bool GameController::shouldClose() const {
    return WindowShouldClose();
}
