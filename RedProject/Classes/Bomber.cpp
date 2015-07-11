//
//  Bomber.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/7.
//
//

#include "Bomber.h"
void Bomber::onEnter()
{
    Node::onEnter();
    sprite=Sprite::create("bomb_0.png");
    sprite->setScale(0.5);
    this->addChild(sprite);
   // sprite->runAction(JumpBy::create(0.5, Vec2(0,0), 10, 1));
    //schedule(schedule_selector(Bomber::updateBomb),0.1);
    scheduleOnce(schedule_selector(Bomber::updateBomb), 3);
 
}
void Bomber::updateBomb(float dt)
{
    //CCLOG("exit");
    this->sprite->runAction(Sequence::create( Animate::create(AnimationCache::sharedAnimationCache()->animationByName("bomb")),
                                             CallFunc::create(this, callfunc_selector(Bomber::remove))
                                             , NULL));

    
}
void Bomber::remove()
{
    this->removeFromParent();
}