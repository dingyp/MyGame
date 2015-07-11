//
//  Global.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/4.
//
//

#ifndef __RedProject__Global__
#define __RedProject__Global__

#include <stdio.h>
#include "cocos2d.h"
#include "Singleton.h"
#include "Player.h"
using namespace cocos2d;

class Global:public Singleton<Global>
{
public:
    Global(void);
    ~Global(void);
    void createRandPosition(Vec2 * a,int n,TMXTiledMap * map);
    Player * player;
    TMXTiledMap *map;
    bool isTransition;
    Point  tileCoordForPosition(Point pos);//用于游戏坐标换算到地图坐标
    Point  positionCoordForTile(Point pos);//用于地图坐标换算到游戏坐标
    bool isCanWalk();
    
    
    Animation * createAni(Texture2D * texture,int row,int col,int frames);
    Animation * createAni(Texture2D * texture,int index);
};

#define global Global::instance()
#endif /* defined(__RedProject__Global__) */
