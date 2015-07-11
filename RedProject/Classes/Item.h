//
//  Item.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/29.
//
//

#ifndef __RedProject__Item__
#define __RedProject__Item__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class Item : public Node
{
public:
    Sprite * sprite;
    virtual void onEnter();
    CC_SYNTHESIZE(bool,isCollision,IsCollision);
    CC_SYNTHESIZE(bool,isCanRemove ,IsCanRemove);
    int tag;
};
#endif /* defined(__RedProject__Item__) */
