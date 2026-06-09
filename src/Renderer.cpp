#include "Renderer.h"

void Renderer::drawWorld(const GameWorld& world) const{
    for(const auto& p : world.projectiles){
        drawProjectile(p.get());
    }
    for(const auto& e : world.enemies){
        drawEnemy(e.get());
    }  
    drawPlayer(world.player.get());
}

void Renderer::drawPlayer(const Player* p) const{
    if(p->invincibleTimer>0 && (int)(p->invincibleTimer*10)%2==0){
       return;
    }
    DrawRectangle((int)p->x,(int)p->y,(int)p->width,(int)p->height,p->color);
    DrawRectangleLinesEx(p->getRect(),2.0f,WHITE);
    drawHpBar(p->x,p->y-10,p->width,p->hp,p->maxHp,GREEN);
}

void Renderer::drawEnemy(const Enemy* e) const{
    DrawRectangle((int)e->x,(int)e->y,(int)e->width,(int)e->height,e->color);
    drawHpBar(e->x,e->y-8,e->width,e->hp,e->maxHp,ORANGE);
}

void Renderer::drawProjectile(const Projectile* p) const{
    DrawRectangle((int)p->x,(int)p->y,(int)p->width,(int)p->height,p->color);
}

void Renderer::drawHpBar(float x,float y,float w,int hp,int maxHp,Color fill) const{
    float ratio=(maxHp>0) ? (float)hp/maxHp : 0.0f;
    DrawRectangle((int)x,(int)y,(int)w,5,DARKGRAY);
    DrawRectangle((int)x,(int)y,(int)(w*ratio),5,fill);
}
