
//
//  GameScene.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/1.
//
//

#ifndef __RedProject__GameScene__
#define __RedProject__GameScene__

#include <stdio.h>
#include "cocos2d.h"

#include "ControllerLayer.h"
#include "Player.h"
#include "Global.h"
using namespace cocos2d;
class GameScene:public Layer
{
   
public:
    //  GameScene();
    //  there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onEnter();
    
    // a selector callback
   
    CREATE_FUNC(GameScene);
    TMXTiledMap * map;
    Vec2 transitionPosition;
    void updateEvent(float dt);
};

#endif /* defined(__RedProject__GameScene__) */
