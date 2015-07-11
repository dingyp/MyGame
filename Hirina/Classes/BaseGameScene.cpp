//
//  BaseGameScene.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/3/31.
//
//

#include "BaseGameScene.h"

void BaseGameScene::onEnter()
{
    Layer::onEnter();
    if(NULL==map)
    {
        map=TMXTiledMap::create("map/map1.tmx");
        CCLOG("init map");
    }
    addChild(map);
    global->map=map;
    TMXObjectGroup *objects = map->getObjectGroup("init");
    CCASSERT(NULL != objects, "'Objects' object group not found");
    auto spawnPoint = objects->getObject("player");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();

    Player * player=new Player();
    player->retain();
    global->player=player;
    
    //player->setAnchorPoint(Vec2(0.5,0.5));
    player->setPosition(Vec2(x,y));
    addChild(player);
//    this->runAction(CCFollow::create(player,CCRectMake(0,0,map->getContentSize().width,map->getContentSize().height)));
    
}
Scene * BaseGameScene::createScene()
{
    Scene * scene=Scene::create();
    auto layer = new BaseGameScene();
    scene->addChild(layer);
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    return scene;
    
}