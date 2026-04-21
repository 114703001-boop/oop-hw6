#pragma once
#include "raylib.h"

class Bubble {
private:
    float x, y;
    float radius;
    int score;
    bool active;
    Color color;

public:
    Bubble(int screenW, int screenH);
    void Draw();
    bool IsClicked(Vector2 mousePos);
    void Pop();
    bool IsActive() const;
    int GetScore() const;
};