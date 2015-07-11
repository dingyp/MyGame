
//
//  Role.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/3.
//
//

#ifndef __RedProject__Role__
#define __RedProject__Role__

#include "cocos2d.h"
#include "Bomber.h"
using namespace cocos2d;

enum State{idle,walk,dead};
class Role : public Node
{
    
public:
    virtual void onEnter();
    SpriteFrame * frameup;
    SpriteFrame * framedown;
    SpriteFrame * frameleft;
    SpriteFrame * frameright;
    int speed;
    enum Destination{up,down,left,right};
    void updateCollision(float dt);
    
    Sprite *sprite;
    Texture2D * texture;
    void changeState(State s);
    Destination nowDestination;
    void setNowDestination(Destination d);
    Destination getNowDestination();
    CC_SYNTHESIZE(Animation *, leftwalkAni,LeftwalkAni);
    CC_SYNTHESIZE(Animation *, rightwalkAni,RightwalkAni);
    CC_SYNTHESIZE(Animation *, upwalkAni,UpwalkAni);
    CC_SYNTHESIZE(Animation *,downwalkAni,DownwalkAni);
    CC_SYNTHESIZE(State,state,NowState);
//    CC_SYNTHESIZE(Destination,destination,NowDestination);
};

#endif /* defined(__RedProject__Role__) */
