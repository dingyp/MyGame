//
//  GameScene1.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/23.
//
//

#ifndef __RedProject__GameScene1__
#define __RedProject__GameScene1__


#include "BaseGameScene.h"
#include "ControllerLayer.h"
#include "GameScene.h"
#include "Item.h"
class MyGameScene:public BaseGameScene
{
public:
    static cocos2d::Scene* createScene();

    MyGameScene();
    void updateEvent(float dt);
    virtual void onEnter();

};
#endif /* defined(__RedProject__GameScene1__) */
