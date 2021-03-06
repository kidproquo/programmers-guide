#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include <iostream>

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();  
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    inline void setPhyWorld(cocos2d::PhysicsWorld* world){ m_world = world; };
    
    cocos2d::Layer* getLayer() { return layer; };
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    void addNewSpriteAtPosition(const cocos2d::Point& p);
    
    void update(float dt);
    
    void addEnemyToLayer(float dt);
    
    inline bool getAddEnemy() { return addEnemy; };
    inline void setAddEnemy(bool b) { addEnemy = b; };
    
    inline cocos2d::Label* getScoreLabel() { return scoreLabel; };
    inline void setScoreLabel() { scoreLabel->setString(std::to_string(score)); };
        
private:
    cocos2d::PhysicsWorld* m_world;
    cocos2d::Layer* layer;
    
    int score = 0;
    cocos2d::Label* scoreLabel;
    bool addEnemy = false;
    
};

#endif // _GAMESCENE_H_
