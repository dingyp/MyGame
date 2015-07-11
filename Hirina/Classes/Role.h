
//
//  Role.h
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#ifndef __KaziProject__Role__
#define __KaziProject__Role__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;
class Role:public Node
{
public:
    
    enum State{idle,rightwalk,leftwalk,jump};
    enum Destination{left,right};
    virtual void onEnter();
    Sprite * mSprite;
    Texture2D * walkTexture;
    Texture2D * idleTexture;
    Texture2D * jumpTexture;
    // Texture2D * walkTexture;
    virtual Size getContentSize();
    CC_SYNTHESIZE(Animation *, walkAni,WalkAni);
    CC_SYNTHESIZE(Animation *, jumpAni,JumpAni);
    CC_SYNTHESIZE(Animation *, idleAni,IdleAni);
    CC_SYNTHESIZE(Destination , nowDestination,NowDestination);
    void updateState(float dt); //下落判断
    void updateDown(float dt); //用于下落时人物碰到地面停止
    void updateGravity(float dt); //重力模拟
    void setDown();
    void downOverCallBack();
    void changeState(State s);
    void JumpOverCallBack();
    void setViewpointCenter(CCPoint p);
  //  void updateViewPointer(float dt);
    bool isDown,isJump,isRun;
    
    ActionInterval * moveAction;
    ActionInterval * downAction;
    ActionInterval * idleAction;
    float scales;
    
    Point _velocity;
    
    int yIndexPlatForm;
    
    State nowState;
    State formState;
    
};
#endif /* defined(__KaziProject__Role__) */
