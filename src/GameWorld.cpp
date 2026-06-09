#include "GameWorld.h"
#include <algorithm>

GameWorld::GameWorld(int screenW,int screenH):screenWidth(screenW), screenHeight(screenH),spawner(screenW,screenH,2.0f),autoAttack(0.6f){
    player=GameObjectFactory::createPlayer(screenW/2.0f,screenH/2.0f);
}
void GameWorld::update(float dt){
    if(gameOver){
        return;
    }
    survivalTime+=dt; //存活時間
    player->update(dt);
    for(auto& e:enemies){ //敵人追蹤
        e->updateChase(dt,player.get());
    }
    for(auto& p:projectiles){ //子彈飛行
        p->update(dt);
    }
    auto newEnemy=spawner.update(dt);
    if(newEnemy){
        enemies.push_back(std::move(newEnemy));
    }
    auto newProj=autoAttack.update(dt,player.get(),enemies);
    if(newProj){
        projectiles.push_back(std::move(newProj));
    }
    collisionSystem.checkProjectileEnemy(projectiles,enemies,killCount); //玩家打敵人
    collisionSystem.checkEnemyPlayer(enemies,player.get()); //敵人碰玩家
    removeDeadObjects();

    if(!player->isAlive()){
        gameOver=true; //遊戲結束
    }
}
void GameWorld::removeDeadObjects(){
    enemies.erase(std::remove_if(enemies.begin(),enemies.end(),[](const std::unique_ptr<Enemy>& e){return e->isDead;}),enemies.end());
    projectiles.erase(std::remove_if(projectiles.begin(),projectiles.end(),[](const std::unique_ptr<Projectile>& p){return p->isDead;}),projectiles.end());
}
