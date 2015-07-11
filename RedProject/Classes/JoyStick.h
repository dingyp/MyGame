//
//  JoyStick.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/21.
//
//

#ifndef __RedProject__JoyStick__
#define __RedProject__JoyStick__

#include <stdio.h>
#include "cocos2d.h"
#include "Global.h"
using namespace cocos2d;
using namespace std;
class Joystick : public Sprite
{
public:
  
    virtual bool init();
    virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
    virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
    virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
    void setJoystick(Vec2 point);
    CREATE_FUNC(Joystick);
private:
    void showJoystick();
    void hideJoystick();
    void updateJoystick(Touch* touch);
    int m_pJoystickr;
    int m_pJoystickR;
    Sprite *m_pJoystick;
    Sprite *m_pJoystickBg;
    Vec2 start;
};
#endif /* defined(__RedProject__JoyStick__) */
