//
//  Global.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#ifndef __KaziProject__Global__
#define __KaziProject__Global__

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
    Animation * createAni(Texture2D * texture,int row,int col,int frames);
    Point  tileCoordForPosition(Point pos);//用于游戏坐标换算到地图坐标
    Point  positionCoordForTile(Point pos);//用于地图坐标换算到游戏坐标

    double fps;
    Player * player;
    TMXTiledMap *map;
};

#define global Global::instance()

#define DECLARE_SINGLETON_MEMBER(_Ty)	\
template <> _Ty* Singleton<_Ty>::_instance = NULL;



#endif /* defined(__RedProject__SingleTon__) */
