
//
//  Bomber.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/7.
//
//

#ifndef __RedProject__Bomber__
#define __RedProject__Bomber__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
class Bomber: public Node
{
public:
    Sprite * sprite;
    virtual void onEnter();
    void updateBomb(float dt);
    void remove();
};


#endif /* defined(__RedProject__Bomber__) */
