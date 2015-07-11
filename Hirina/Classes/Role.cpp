//
//  Role.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#include "Role.h"
#include "Global.h"
void Role::onEnter()
{
    Node::onEnter();
    if(NULL==walkTexture){
        Sprite * walkSprite=Sprite::create("images/miku_walk8.png");
        walkTexture=walkSprite->getTexture();
        Sprite * idleSprite=Sprite::create("images/miku_idle10.png");
        idleTexture=idleSprite->getTexture();
        scales=0.5;
    }
    _velocity=Point(0,0);
    mSprite=Sprite::createWithTexture(idleTexture, Rect(0,0,idleTexture->getContentSize().width/10,
                                                        walkTexture->getContentSize().height));
    
    this->setWalkAni(global->createAni(walkTexture, 1, 8, 8));
    this->setIdleAni(global->createAni(idleTexture, 1, 10, 10));
    
    mSprite->setScale(scales);
   // downAction->setTag(1);
    
    //mSprite->setAnchorPoint(Vec2(0.5,0.25));
    this->addChild(mSprite);
    this->changeState(idle);
    this->setNowDestination(right);
    this->isJump=false;
    //idleAction->retain();
    
    
    schedule(schedule_selector(Role::updateState), global->fps);
    schedule(schedule_selector(Role::updateDown),global->fps);
    //schedule(schedule_selector(Role::updateViewPointer),global->fps);
    
}
Size Role::getContentSize()
{
    return Size(scales*mSprite->getContentSize().width,scales*mSprite->getContentSize().height);
}
void Role::changeState(State s)
{
    if(nowState!=jump){
        formState=nowState;
    }
    nowState=s;
    isRun=false;
    float width=walkTexture->getContentSize().width;
    float height = walkTexture->getContentSize().height;
    switch (nowState) {
        case idle:
            this->stopAllActionsByTag(2);
            this->mSprite->stopAllActions();
           // this->_velocity=Point(0,0);
             idleAction=RepeatForever::create(Animate::create(this->getIdleAni()));
           // downAction=RepeatForever::create(Animate::create(this->getIdleAni()));
            this->mSprite->runAction(idleAction->clone());
            break;
        case rightwalk:
            isRun=true;
            this->stopAllActionsByTag(2);
            this->setNowDestination(right);
            this->mSprite->stopAllActions();
            this->mSprite->setFlippedX(false);
            moveAction=RepeatForever::create(MoveBy::create(0.1,Vec2(10,0)));
            moveAction->setTag(2);
        //    if(!isJump){
                this->mSprite->runAction(RepeatForever::create(Animate::create(this->getWalkAni())));
         //   }
            this->runAction(moveAction);
            break;
        case leftwalk:
            isRun=true;
            this->stopAllActionsByTag(2);
            this->setNowDestination(left);
            this->mSprite->stopAllActions();
            this->mSprite->setFlippedX(true);
            moveAction=RepeatForever::create(MoveBy::create(0.1,Vec2(-10,0)));
            moveAction->setTag(2);
         //   if(!isJump){
                this->mSprite->runAction(RepeatForever::create(Animate::create(this->getWalkAni())));
          //  }
            this->runAction(moveAction);
            break;
        case jump:
            this->_velocity=Point(0,5);//初速度
           // this->mSprite->stopAllActions();
            
          
//            this->mSprite->setSpriteFrame(SpriteFrame::createWithTexture(walkTexture, Rect(width/2,0,width/8,height)));
            CCLOG("jump1");
            if(!isJump){
                CCLOG("jump2");
                schedule(schedule_selector(Role::updateGravity),global->fps);
                isJump=true;
            }
            
//            this->runAction(Sequence::create(JumpBy::create(1, Vec2(0,80),50,1),
//                                             CallFunc::create(this,callfunc_selector(Role::JumpOverCallBack)),  NULL) );
            break;
        default:
            break;
    }
}
void Role::updateState(float dt)
{
    Vec2 point=global->tileCoordForPosition(this->getPosition());
    TMXLayer *collisionLayer=global->map->getLayer("ground");
    
    
    //左右碰撞检测
    int x1=this->getContentSize().width/2;
    int y1=this->getContentSize().height/2*0.8;
    Point p1,p2,p3;
    Point playerpoint=this->getPosition();
    int x=playerpoint.x;
    int y=playerpoint.y;
    switch (this->getNowDestination()) {
        case right:
            p1=ccp(x+x1,y-y1);
            p2=ccp(x+x1,y);
            p3=ccp(x+x1,y+y1);

            break;
        case left:
            p1=ccp(x-x1,y+y1);
            p2=ccp(x-x1,y);
            p3=ccp(x-x1,y-y1);
            break;
        default:
            break;
    }
    Point r1=global->tileCoordForPosition(p1);
    Point r2=global->tileCoordForPosition(p2);
    Point r3=global->tileCoordForPosition(p3);
    
    int id1=collisionLayer->getTileGIDAt(r1);
    int id2=collisionLayer->getTileGIDAt(r2);
    int id3=collisionLayer->getTileGIDAt(r3);
    if((id1||id3)&&id2)
    {
        this->stopAllActionsByTag(2);
        isRun=false;
    }else{
        //此处添加恢复动作
 //
       
        if(nowState==leftwalk||nowState==rightwalk){
            
           // CCLOG("resume");
            if(!isRun){
                this->changeState(nowState);
            }
            //this->changeState(nowState);
        }
        if(nowState==jump&&(formState==leftwalk||formState==rightwalk))
        {
            if(!isRun){
                this->changeState(formState);
            }
        }
    }

    int flag=0;
    for(int i=point.y;i<global->map->getMapSize().height;i++)
    {
        if(collisionLayer->getTileGIDAt(Vec2(point.x,i+1))||i==global->map->getMapSize().height-1)
        {
            if(i!=point.y){
                flag=1;
                yIndexPlatForm=i+1;
                if(!isDown&&!isJump){
                    schedule(schedule_selector(Role::updateGravity),  global->fps);
                    isDown=true;
                    CCLOG("downstart");
                }

            }else{
                 yIndexPlatForm=i+1;
            }
            if(i==global->map->getMapSize().height-1){
                yIndexPlatForm=i+10;
            }
            break;
        }
    }
    
    
    
   // CCLOG("%f,%f",point.x,point.y);
}

void Role::updateDown(float dt)
{
    if(isDown)
    {
        Vec2 point=global->tileCoordForPosition(this->getPosition());
        TMXLayer *collisionLayer=global->map->getLayer("ground");
        float playery=this->getPositionY()-this->getContentSize().height/2;
        float plateformy=global->positionCoordForTile(Vec2(point.x,yIndexPlatForm)).y+global->map->getTileSize().height/2;
        CCLOG("comp: %f,%f",playery,plateformy);
        if(playery<=plateformy){
            CCLOG("downtoground");
            this->stopAllActionsByTag(3);
            this->setPositionY(plateformy+this->getContentSize().height/2);
            downOverCallBack();
           
        }
    }
}
void Role::JumpOverCallBack()
{
//    if(nowState==jump)
//    {
//        if(formState==rightwalk||formState==leftwalk){
//            this->changeState(formState);
//        }else{
//            this->changeState(idle);
//        }
//    }
    isJump=false;
    isDown=true;
}
void Role::downOverCallBack()
{
    isJump=false;
    isDown=false;
    
    this->_velocity=Point(0,0);
    unschedule(schedule_selector(Role::updateGravity));
    if(nowState==jump){
        changeState(formState);
    }
    if(nowState==leftwalk||nowState==rightwalk){
        this->changeState(nowState);
    }
}
void Role::setViewpointCenter(CCPoint p)
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    float x = MAX(p.x, size.width / 2);
    float y = MAX(p.y, size.height / 2);
    
    x = MIN(x, (global->map->getMapSize().width*global->map->getTileSize().width) - size.width / 2);
    y = MIN(y, (global->map->getMapSize().height*global->map->getTileSize().height) - size.height / 2);
    CCPoint actualPosition = ccp(x, y);
    CCPoint centerOfView = ccp(size.width / 2, size.height / 2);
    CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
    int x1 = viewPoint.x;
    int y1 = viewPoint.y;
    int herox = p.x;
    int heroy = p.y;
    int thisx = this->getPositionX();
    int htisy = this->getPositionY();
    int mapSize = global->map->getMapSize().width;
    int TileSize = global->map->getTileSize().width;
    
    this->getParent()->setPosition(viewPoint);
    int x2 = 0 - viewPoint.x;
    int y2 = 0 - viewPoint.y;

}
void Role::updateGravity(float dt)
{
 //CCLOG("%f",dt);
    if(isDown){
       // this->_velocity=Point(0,0);
    }
    if(_velocity.y<=0)
    {
        JumpOverCallBack();
    }
    Point gravity = Point(0.f, -7.f);
    Point gravityStep = gravity* dt;
    this->_velocity = ccpAdd(this->_velocity, gravityStep);
    this->setPosition(ccpAdd(this->getPosition(), _velocity));
}



