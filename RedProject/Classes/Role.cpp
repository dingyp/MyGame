//
//  Role.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/3.
//
//

#include "Role.h"
#include "Global.h"
void Role::onEnter(){
    Node::onEnter();
    
    if(!texture){
       
        Sprite * spritexture=Sprite::create("lingmeng/meng.png");
        texture=spritexture->getTexture();
      
    //  addChild(spritexture);
        speed=8;
        CCLOG("tex");
    }
    texture->retain();
    float width=texture->getContentSize().width;
    float height = texture->getContentSize().height;
    framedown=SpriteFrame::createWithTexture(texture,
                                             Rect(0, 0, width/3, height/4));
    frameup=SpriteFrame::createWithTexture(texture,Rect(0, height/4*3, width/3, height/4) );
    frameleft=SpriteFrame::createWithTexture(texture, Rect(0, height/4*2, width/3, height/4));
    frameright=SpriteFrame::createWithTexture(texture, Rect(0, height/4, width/3, height/4));
    sprite=Sprite::createWithSpriteFrame(framedown);
    this->setDownwalkAni(global->createAni(texture, 0));
    this->setUpwalkAni(global->createAni(texture, 3));
    this->setLeftwalkAni(global->createAni(texture, 1));
    this->setRightwalkAni(global->createAni(texture, 2));
    sprite->retain();
    addChild(sprite);
    schedule(schedule_selector( Role::updateCollision), 0.02);
   
}
void Role::changeState(State s)
{
    this->setNowState(s);
    this->stopAllActions();
    this->sprite->stopAllActions();
    switch (this->getNowState()) {
        case walk:
            if (global->isCanWalk()) {
                switch (this->getNowDestination()) {
                    case up:
                        
                        this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(0,speed))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getUpwalkAni())));
                        break;
                    case down:
                        this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(0,-speed))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getDownwalkAni())));
                        break;
                    case Role::left:
                        this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(-speed,0))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getLeftwalkAni())));
                        break;
                    case Role::right:
                        this->runAction(RepeatForever::create(MoveBy::create(0.1, Vec2(speed,0))));
                        this->sprite->runAction(RepeatForever::create(Animate::create(this->getRightwalkAni())));
                        break;
                    default:
                        break;
                }

            }
            
            break;
        case idle:
            
            break;
        case dead:
            
            break;
        default:
            break;
    }
    
}
void Role::updateCollision(float dt)
{
    if(!global->isCanWalk())
    {
        this->changeState(idle);
    }
}

void Role::setNowDestination(Destination d){
    if(d!=nowDestination){
        nowDestination=d;
        this->changeState(walk);
    }
}
Role::Destination Role::getNowDestination(){
    return nowDestination;
}
