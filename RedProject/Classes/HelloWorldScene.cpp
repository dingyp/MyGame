#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"
using namespace std;
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    Button * button = static_cast<Button*>(rootNode->getChildByName("Button_1"));
    button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::touch, this));
    
    Button * buttonClose =static_cast<Button *>(rootNode->getChildByName("Button_close"));
    buttonClose->addTouchEventListener(CC_CALLBACK_2(HelloWorld::closeGame, this));
    addChild(rootNode);
    Sprite * texsp=Sprite::create("explosion_01.png");
    Animation * bomb=global->createAni(texsp->getTexture(), 1, 13, 12);
    
    AnimationCache::sharedAnimationCache()->addAnimation(bomb, "bomb");
//    Sprite * node =Sprite::create();
//    node->setPosition(VisibleRect::center());
//    node->runAction(RepeatForever::create(Animate::create(AnimationCache::sharedAnimationCache()->animationByName("bomb"))));
//    addChild(node);
    
    return true;
}
void HelloWorld::touch(Ref * ref,Widget::TouchEventType type){
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
           
            Director::getInstance()->replaceScene(TransitionFade::create(1, MyGameScene::createScene()));
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
    }
      //  Sprite *sprite=Sprite::create("res/");
}
void HelloWorld::onClick(Ref * ref){
    CCLOG("onClick");
}
void HelloWorld::onEvent(cocos2d::Ref* sender, int eventType)
{
    CCLOG("onEvent");
}
Widget::ccWidgetTouchCallback HelloWorld::onLocateTouchCallback(const string &callBackName)
{
    if (callBackName == "touch")//判断事件名，返回对应的函数。下同
    {
        return CC_CALLBACK_2(HelloWorld::touch, this);
    }
    return nullptr;
}
Widget::ccWidgetClickCallback HelloWorld:: onLocateClickCallback(const string &callBackName)
{
    if (callBackName == "onClick")
    {
        return CC_CALLBACK_1(HelloWorld::onClick, this);
    }
    return nullptr;
}
Widget::ccWidgetEventCallback HelloWorld:: onLocateEventCallback(const string &callBackName)
{
    if (callBackName == "onEvent")
    {
        return CC_CALLBACK_2(HelloWorld::onEvent, this);
    }
    return nullptr;
}
void HelloWorld::closeGame(Ref * ref, Widget::TouchEventType type)
{
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
         //  exit(0);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
            MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
            return;
#endif
            
            Director::getInstance()->end();
            
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
#endif
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
    }

}


