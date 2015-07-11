//
//  BaseGameScene.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/3/31.
//
//

#ifndef __KaziProject__BaseGameScene__
#define __KaziProject__BaseGameScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ControllerLayer.h"
#include "Player.h"
#include "Global.h"
using namespace cocos2d;
class BaseGameScene :public Layer
{
public:
    virtual void onEnter();
    static Scene * createScene();
    TMXTiledMap * map;
};
#endif /* defined(__KaziProject__BaseGameScene__) */
