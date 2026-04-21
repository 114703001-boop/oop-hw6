#include "Bubble.h"
#include <cstdlib>
#include <string>

Bubble::Bubble(int screenW, int screenH) {
    radius = (float)(rand() % 30 + 20);
    x = (float)(rand() % (screenW - (int)radius * 2) + (int)radius);
    y = (float)(rand() % (screenH - (int)radius * 2) + (int)radius);
    score = (int)(50 / radius * 10);
    active = true;
    Color colors[] = { RED, BLUE, GREEN, PURPLE, ORANGE, PINK };
    color = colors[rand() % 6];
}

void Bubble::Draw() {
    if (!active) return;
    DrawCircle((int)x, (int)y, radius, color);
    DrawCircleLines((int)x, (int)y, radius, WHITE);
    std::string s = std::to_string(score);
    DrawText(s.c_str(),
        (int)x - MeasureText(s.c_str(), 18) / 2,
        (int)y - 9, 18, WHITE);
}

bool Bubble::IsClicked(Vector2 mousePos) {
    if (!active) return false;
    float dx = mousePos.x - x;
    float dy = mousePos.y - y;
    return (dx * dx + dy * dy) <= (radius * radius);
}

void Bubble::Pop() { active = false; }
bool Bubble::IsActive() const { return active; }
int Bubble::GetScore() const { return score; }