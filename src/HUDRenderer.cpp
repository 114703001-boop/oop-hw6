#include "HUDRenderer.h"

void HUDRenderer::draw(const GameWorld& world) const{
    DrawText(TextFormat("HP: %d / %d",world.player->hp,world.player->maxHp),10,10,20,WHITE);
    DrawText(TextFormat("Time: %.1f s",world.survivalTime),10,36,20,WHITE); //存活秒數
    DrawText(TextFormat("Kills: %d",world.killCount),10,62,20,WHITE); //擊殺數
    DrawText("WASD to move",10,420,14,GRAY);
}
void HUDRenderer::drawGameOver(const GameWorld& world) const{
    int sw=world.screenWidth;
    int sh=world.screenHeight;
    DrawRectangle(0,0,sw,sh,{0,0,0,160});
    const char* msg="GAME OVER";
    int fontSize=60;
    int tw=MeasureText(msg,fontSize);
    DrawText(msg,(sw-tw)/2,sh/2-60,fontSize,RED);
    DrawText(TextFormat("Survived: %.1f s",world.survivalTime),(sw-MeasureText("Survived: 000.0 s",24))/2,sh/2+10,24,WHITE);
    DrawText(TextFormat("Kills: %d",world.killCount),(sw-MeasureText("Kills: 000",24))/2,sh/2+42,24,WHITE);
    const char* hint="Press R to restart";
    DrawText(hint,(sw-MeasureText(hint,20))/2,sh/2+90,20,LIGHTGRAY);
}
