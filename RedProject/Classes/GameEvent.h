//
//  GameEvent.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/23.
//
//

#ifndef __RedProject__GameEvent__
#define __RedProject__GameEvent__

#include <stdio.h>
#include "cocos2d.h"
using namespace cocos2d;
enum EventType{transitionEvent,talkEvent};
class GameEvent
{
public:
    Vec2 position;
    EventType type;
    GameEvent(Vec2 position,
              EventType type);
};
#endif /* defined(__RedProject__GameEvent__) */
