#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "VisibleRect.h"
USING_NS_CC;
using namespace cocos2d::ui;
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
    Rect s_visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Button * buttonStart= Button::create("start.png");
    buttonStart->setTag(0);
    buttonStart->setPosition(VisibleRect::center());
    addChild(buttonStart);
    buttonStart->addTouchEventListener(CC_CALLBACK_2(HelloWorld::startCallBack, this));
    
    
    

    return true;
}
void HelloWorld::startCallBack(Ref * ref,Widget::TouchEventType type)
{
    switch (type) {
        case cocos2d::ui::Widget::TouchEventType::BEGAN:
            break;
        case cocos2d::ui::Widget::TouchEventType::MOVED:
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED:
            this->removeChildByTag(0);
            initGame();
            break;
        case cocos2d::ui::Widget::TouchEventType::CANCELED:
            break;
        
    }
    
}
void HelloWorld::initGame(){
    
    
    hero =Sprite::create("blue.png");
    hero->setPosition(VisibleRect::center());
    this->addChild(hero);
    
    
    // 创建一个事件监听器类型为 OneByOne 的单点触摸
    auto listener1 = EventListenerTouchOneByOne::create();
    // 使用 lambda 实现 onTouchBegan 事件回调函数
    listener1->onTouchBegan = [](Touch* touch, Event* event){
// 获取事件所绑定的 target
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        
        // 获取当前点击点所在的位置坐标
        Point location = touch->getLocation();
        Rect rect = target->getBoundingBox();
       
        // 点击范围判断检测
        if (rect.containsPoint(location))
        {
         log("sprite began... x = %f, y = %f", location.x, location.y);
         return true;
        }
        return false;
    };
    
    // 触摸移动时触发
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        //...
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point location= touch->getLocation();
        target->setPosition(location);
    };
    
    // 点击事件结束处理
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        //...
    };
    // 添加监听器
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, hero);
    herovecolity=Vec2(3,-3);
    schedule(schedule_selector(HelloWorld::updateMove), 0.01);
    schedule(schedule_selector(HelloWorld::updateVec),0.01);
}


void HelloWorld::updateMove(float dt){
    hero->setPosition(Vec2(hero->getPositionX()+herovecolity.x,hero->getPositionY()+herovecolity.y));
    
}

void HelloWorld::updateVec(float dt){
    Size visibleSize=Director::getInstance()->getVisibleSize();
    if(hero->getPositionY()>=visibleSize.height||hero->getPositionY()<=0){
        herovecolity=Vec2(herovecolity.x,-herovecolity.y);
        CCLOG("vertical collision");
    }
    else if (hero->getPositionX()<=0||hero->getPositionX()>=visibleSize.width){
        herovecolity=Vec2(-herovecolity.x, herovecolity.y);
        CCLOG("horizontal collision");
    }
}
