//
//  MyGameScene.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/3/31.
//
//

#include "MyGameScene.h"
MyGameScene::MyGameScene()
{
    map=TMXTiledMap::create("map/map2.tmx");
}
Scene* MyGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    // 'layer' is an autorelease object
    auto layer = new MyGameScene();
    
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    //schedule(schedule_selector(MyGameScene::updateEvent), 0.1);
    
    return scene;
}
void MyGameScene::updateEvent(float dt)
{
   // int x=global->player->getPosition().x;
    
    
}
void MyGameScene::onEnter()
{
    BaseGameScene::onEnter();
    CCLOG("isover");
    Vec2 * positions=new Vec2[10];
    
    
    
    schedule(schedule_selector(MyGameScene::updateEvent), 1);
    
}


