//
//  GameEvent.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/23.
//
//

#include "GameEvent.h"
GameEvent::GameEvent(Vec2 position,
                     EventType type)
{
    this->position=position;
    this->type=type;
}