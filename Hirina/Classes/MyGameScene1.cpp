//
//  MyGameScene1.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/20.
//
//

#include "MyGameScene1.h"
MyGameScene1::MyGameScene1()
{
    map=TMXTiledMap::create("map/test.tmx");
}
Scene* MyGameScene1::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = new MyGameScene1();
    
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    //schedule(schedule_selector(MyGameScene::updateEvent), 0.1);
    
    return scene;
}
void MyGameScene1::updateEvent(float dt)
{
    // int x=global->player->getPosition().x;
    
    
}
void MyGameScene1::onEnter()
{
    BaseGameScene::onEnter();
    CCLOG("isover");
    Vec2 * positions=new Vec2[10];
    
    
    
    schedule(schedule_selector(MyGameScene1::updateEvent), 1);
    
}