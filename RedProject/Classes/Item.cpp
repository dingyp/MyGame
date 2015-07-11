//
//  Item.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/29.
//
//

#include "Item.h"
void Item::onEnter()
{
    Node::onEnter();
    if(NULL==sprite)
    {
        sprite=Sprite::create("images/BubbleSimple.png");
        this->setIsCollision(true);
        this->setIsCanRemove(true);
    }
    this->addChild(sprite);
    this->sprite->runAction(RepeatForever::create(Sequence::create(MoveBy::create(0.2,Vec2(0,2)),
                                                                   MoveBy::create(0.2,Vec2(0,-2)),NULL)));
}