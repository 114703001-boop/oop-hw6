#include "raylib.h"
#include <iostream>
#include "GameController.h"

int main(){
    InitWindow(800,450,"Raylib OOP");
    SetTargetFPS(60);
    GameController controller(800,450);
    while(!controller.shouldClose()){
        controller.update();
        controller.render();
    }
    CloseWindow();
    return 0;
}
