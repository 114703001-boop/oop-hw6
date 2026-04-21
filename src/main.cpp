#include "raylib.h"
#include "Bubble.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

int main() {
    const int SCREEN_W = 800;
    const int SCREEN_H = 600;

    InitWindow(SCREEN_W, SCREEN_H, "Bubble Pop!");
    SetTargetFPS(60);
    srand((unsigned int)time(nullptr));

    std::vector<Bubble> bubbles;
    int totalScore = 0;
    float spawnTimer = 0.0f;
    float spawnInterval = 1.5f;

    for (int i = 0; i < 5; i++)
        bubbles.push_back(Bubble(SCREEN_W, SCREEN_H));

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();

        spawnTimer += delta;
        if (spawnTimer >= spawnInterval) {
            bubbles.push_back(Bubble(SCREEN_W, SCREEN_H));
            spawnTimer = 0.0f;
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            for (auto& b : bubbles) {
                if (b.IsClicked(mouse)) {
                    totalScore += b.GetScore();
                    b.Pop();
                    break;
                }
            }
        }

        bubbles.erase(
            std::remove_if(bubbles.begin(), bubbles.end(),
                [](const Bubble& b) { return !b.IsActive(); }),
            bubbles.end()
        );

        BeginDrawing();
            ClearBackground({ 20, 20, 40, 255 });
            for (auto& b : bubbles) b.Draw();
            std::string scoreText = "Score: " + std::to_string(totalScore);
            DrawText(scoreText.c_str(), 10, 10, 30, YELLOW);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}