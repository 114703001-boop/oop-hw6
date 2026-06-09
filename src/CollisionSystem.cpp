#include "CollisionSystem.h"

void CollisionSystem::checkProjectileEnemy(std::vector<std::unique_ptr<Projectile>>& projectiles,std::vector<std::unique_ptr<Enemy>>& enemies,int& killCount){
    for(auto& proj : projectiles){
        if(proj->isDead){
            continue;
        }
        for(auto& enemy : enemies){
            if(enemy->isDead){
                continue;
            }
            if(CheckCollisionRecs(proj->getRect(),enemy->getRect())){
                enemy->takeDamage(proj->damage);
                proj->isDead=true; //標記死亡
                if(enemy->isDead){
                    killCount=killCount+1;
                }
                break;
            }
        }
    }
}

void CollisionSystem::checkEnemyPlayer(std::vector<std::unique_ptr<Enemy>>& enemies,Player* player){
    for(auto& enemy : enemies){
        if(enemy->isDead){
            continue;
        }
        if(CheckCollisionRecs(enemy->getRect(),player->getRect())){
            player->takeDamage(enemy->damage); //扣血
        }
    }
}
