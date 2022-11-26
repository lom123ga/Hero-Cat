#include "CollisionManager.h"

void CollisionManager::addObj(HitBox* hitBox)
{
    m_listObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
    return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

void CollisionManager::Update()
{
    //int contC = 0;
    int contF = 0;
    int contJ = 0;
    int contL = 0;
    int contR = 0;
    //auto a = m_listObj.back();
    for (auto a : m_listObj) {
        if (a->isAlive() == false || a->getTag() == MAPBLOCK || a->getTag() == COIN) continue;
        for (auto b : m_listObj) {

            if (b->isAlive() == false) continue;

            if (a->getTag() == b->getTag()) continue;
            
            if (!checkCollision(a, b)) continue;

            if (a->getTag() == PLAYER && b->getTag() == CREEP) {
                a->setAlive(false);
                b->setAlive(false);
            }

            if (a->getTag() == PLAYER && b->getTag() == BOSS) {
                a->setAlive(false);
            }

            if (a->getTag() == CREEP && b->getTag() == ROCK) {
                a->setAlive(false);
                b->setAlive(false);
            }

            if (a->getTag() == ROCK && b->getTag() == MAPBLOCK) {
                a->setAlive(false);
            }

            if (a->getTag() == PLAYER && b->getTag() == COIN) {
                //contC += 1;
                b->setAlive(false);
            }
            //else a->setCoin(false);

            if (a->getTag() == PLAYER && b->getTag() == MAPBLOCK) {
                if (a->getPosition().y  <= b->getPosition().y - 14 && (a->getPosition().x  <= b->getPosition().x  || a->getPosition().x  >= b->getPosition().x )) contF += 1;
                if (a->getPosition().y >= b->getPosition().y  && (a->getPosition().x <= b->getPosition().x || a->getPosition().x >= b->getPosition().x)) contJ += 1;
                if (a->getPosition().x <= b->getPosition().x - 14  && a->getPosition().y >= b->getPosition().y - 14 ) contR += 1;
                if (a->getPosition().x >= b->getPosition().x + 14  && a->getPosition().y >= b->getPosition().y - 14 ) contL += 1;
            }
        }
   
    }
    //m_listObj.back()->setCoin(contC);
    if(contF == 0) {
       
        m_listObj.back()->setCanFall(true);
    }
    else {
       
        m_listObj.back()->setCanFall(false);
    }
    if (contJ == 0) {
        
       
        m_listObj.back()->setCanJump(true);
    }
    else {
        
        m_listObj.back()->setCanJump(false);
    }
    if (contL == 0) {
       
        m_listObj.back()->setCanL(true);
    }
    else {
       
        m_listObj.back()->setCanL(false);
    }
    if (contR == 0) {
       
        m_listObj.back()->setCanR(true);
    }
    else {
       
        m_listObj.back()->setCanR(false);
    }
}
