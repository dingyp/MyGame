#include "HelloWorldScene.h"
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
    
    Size size = Director::getInstance()->getVisibleSize();
    
    Sprite  * button =Sprite::create("start.png");
    
    
    button->setPosition(Vec2(size.width/2,size.height/2));
    
    button->setTag(1);
    
    this->addChild(button);
    
    //button->addTouchEventListener(CC_CALLBACK_2(HelloWorld::click, this));
    
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
        CCLOG("");
        //...
    };
    
    
    // 3.添加监听器
    _eventDispatcher->
    addEventListenerWithSceneGraphPriority(listener1, button);

    return true;
}
void HelloWorld::click(Ref * ref, Widget::TouchEventType type){
    
    Node * node = this->getChildByTag(1);
    
    
    
    switch (type) {
        case Widget::TouchEventType::BEGAN:
            CCLOG("touch");
            break;
        case Widget::TouchEventType::MOVED:
            
            break;
        case Widget::TouchEventType::ENDED:
            node->removeFromParent();
            break;
        case Widget::TouchEventType::CANCELED:
            break;
    }
    

    
    
}