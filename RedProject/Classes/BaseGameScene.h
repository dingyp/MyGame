//
//  BaseGameScene.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/24.
//
//

#ifndef __RedProject__BaseGameScene__
#define __RedProject__BaseGameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "Global.h"
using namespace cocos2d;
class BaseGameScene:public Layer
{
public:
    virtual void onEnter();
    TMXTiledMap * map;
    Vec2 transitionPosition;
};
#endif /* defined(__RedProject__BaseGameScene__) */
