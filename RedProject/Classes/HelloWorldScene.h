#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "MyGameScene.h"
#include "cocostudio/Cocostudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
using namespace cocos2d;
using namespace cocos2d::ui;
class HelloWorld : public cocos2d::Layer,public cocostudio::WidgetCallBackHandlerProtocol
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void touch(Ref * ref,Widget::TouchEventType type);
    void onClick(Ref * ref);
    void onEvent(cocos2d::Ref* sender, int eventType);
    void closeGame(Ref * ref,Widget::TouchEventType type);
    
    virtual cocos2d::ui::Widget::ccWidgetTouchCallback
    onLocateTouchCallback(const std::string &callBackName);
    virtual cocos2d::ui::Widget::ccWidgetClickCallback
    onLocateClickCallback(const std::string &callBackName);
    virtual cocos2d::ui::Widget::ccWidgetEventCallback
    onLocateEventCallback(const std::string &callBackName);
};

#endif // __HELLOWORLD_SCENE_H__
