#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"
USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio::timeline;
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void initGame();
    
    void startCallBack(Ref * ref,Widget::TouchEventType type);
    
    void updateMove(float dt);
    
    void updateVec(float dt);
    
    Sprite * hero;
    
    Vec2 herovecolity;
};

#endif // __HELLOWORLD_SCENE_H__
