#include "AutoAttack.h"
#include "Player.h"
#include <cmath>
#include <limits>

AutoAttack::AutoAttack(float interval):attackInterval(interval){}
std::unique_ptr<Projectile> AutoAttack::update(float dt,const Player* player,const std::vector<std::unique_ptr<Enemy>>& enemies){
    timer+=dt; //子彈cd
    if(timer<attackInterval){
        return nullptr; //攻擊間隔
    }
    const Enemy* target=findNearest(player,enemies); //找最近敵人
    if(!target){
        return nullptr;
    }
    timer=0.0f;  
    float fromX=player->x+player->width/2;
    float fromY=player->y+player->height/2;
    float toX=target->x+target->width/2;
    float toY=target->y+target->height/2;

    return GameObjectFactory::createProjectile(fromX,fromY,toX,toY);
}
const Enemy* AutoAttack::findNearest(const Player* player,const std::vector<std::unique_ptr<Enemy>>& enemies){
    const Enemy* nearest=nullptr;
    float minDist=std::numeric_limits<float>::max();
    float px=player->x+player->width/2;
    float py=player->y+player->height/2;
    for(const auto& e : enemies){
        if(e->isDead){跳過已死敵人死敵人
            continue;
        }
        float dx=(e->x+e->width/2)-px;
        float dy=(e->y+e->height/2)-py;
        float dist=std::sqrt(dx*dx+dy*dy); //畢氏定理
        if(dist<minDist){ 
            minDist=dist; 
            nearest=e.get(); 
        }
    }
    return nearest;
}
