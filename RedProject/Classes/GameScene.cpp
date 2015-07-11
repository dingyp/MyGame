//
//  GameScene.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/1.
//
//

#include "GameScene.h"
#include "VisibleRect.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    //auto controllerlayer=ControllerLayer::create();
    
    ControllerLayer *controllerLayer=ControllerLayer::create();
    scene->addChild(controllerLayer,2);
    //    scene->addChild(controllerlayer,1);
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    if(NULL==map){
        map=TMXTiledMap::create("map/map1.tmx");
    }
    //map->setScale(2);
    addChild(map);

    TMXObjectGroup *objects = map->getObjectGroup("player");
    CCASSERT(NULL != objects, "'Objects' object group not found");
    auto spawnPoint = objects->getObject("playerinit");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt();
    int y = spawnPoint["y"].asInt();
    Player * player = new Player();
    global->player=player;
    global->map=map;
    player->setPosition(Vec2(x,y));
    addChild(player,2);
    //player->sprite->runAction(RepeatForever::create(Animate::create(global->createAni(player->texture, 3))));
    TMXObjectGroup *object2=map->getObjectGroup("Event");
    auto transitionpoint=object2->getObject("transitionEvent");
    int x1=transitionpoint["x"].asInt();
    int y1=transitionpoint["y"].asInt();
    transitionPosition=Vec2(x1,y1);
    //CCLOG("over");
    this->runAction(CCFollow::create(player,CCRectMake(0,0,map->getContentSize().width,map->getContentSize().height)));
    schedule(schedule_selector(GameScene::updateEvent), 0.1);
    return true;

}
void GameScene::onEnter()
{
    Layer::onEnter();
    
}
void GameScene::updateEvent(float dt)
{
    if(fabs(transitionPosition.x-global->player->getPosition().x)<15&&
       fabs(transitionPosition.y-global->player->getPosition().y)<15){
        CCLOG("x:%f,%f",transitionPosition.x,global->player->getPosition().x);
        CCLOG("Child Scene");
        Director::getInstance()->replaceScene(TransitionFade::create(1, MyGameScene::createScene()));
        unschedule(schedule_selector(GameScene::updateEvent));
    }
}
