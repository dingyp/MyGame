//
//  Player.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/19.
//
//

#include "Player.h"
#include "Global.h"
bool Player::init()
{
    if(!Node::init())
    {
        return false;
    }
    return true;
}
Player::Player()
{
   // Sprite * spritexture=Sprite::create("images/miku_num10.png");
    Sprite * walkSprite=Sprite::create("images/miku_walk8.png");
    walkTexture=walkSprite->getTexture();
    Sprite * idleSprite=Sprite::create("images/miku_num10.png");
    idleTexture=idleSprite->getTexture();
    scales=0.5;

    CCLOG("init Player");
    schedule(schedule_selector(Player::updateViewPoint), global->fps);
    
}
void Player::updateViewPoint(float dt){
    this->setViewpointCenter(this->getPosition());
}