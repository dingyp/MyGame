//
//  Player.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/9.
//
//

#ifndef __RedProject__Player__
#define __RedProject__Player__

#include <stdio.h>
#include "Role.h"
class Player: public Role
{
public:
    virtual bool init();
    CREATE_FUNC(Player);
    Player();
    void bomb();
};
#endif /* defined(__RedProject__Player__) */
