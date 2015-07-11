//
//  ControllerLayer.cpp
//  KaziProject
//
//  Created by 丁逸鹏 on 15/4/1.
//
//

#include "ControllerLayer.h"
#include "ChooseScene.h"
bool ControllerLayer::init()
{
    CCLOG("Layer init");
    if ( !Layer::init() )
    {
        return false;
    }
    auto ui=CSLoader::createNode("ControllerLayer.csb");
    addChild(ui);
    Button * button_Left = static_cast<Button *>(ui->getChildByName("Button_left"));

    button_Left->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveleft, this));

    Button * button_Right = static_cast<Button *>(ui->getChildByName("Button_right"));

    button_Right->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::moveright, this));
    
    Button * button_Jump = static_cast<Button *>(ui->getChildByName("Button_jump"));
    
    button_Jump->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::jump, this));
    
    Button * button_Back = static_cast<Button * >(ui->getChildByName("Button_Back"));
    
    button_Back->addTouchEventListener(CC_CALLBACK_2(ControllerLayer::back,this));
    
    
    return true;
}
void ControllerLayer::moveright(Ref *ref,Widget::TouchEventType type)
{
    
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->changeState(Role::rightwalk);
//            global->player->setNowDestination(Role::right);
//            global->player->changeState(walk);
            break;
            //	case (int)(cocos2d::ui::Widget::TouchEventType::MOVED):
            
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(Role::idle);
            
            
            break;
        default:
            break;
    }
    
    
}
void ControllerLayer::moveleft(Ref *ref,Widget::TouchEventType type)
{
    auto actionmove=RepeatForever::create(MoveBy::create(0.1,Vec2(-5,0)));
    actionmove->setTag(2);
    
    
    //auto game=GameScene::createScene();
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->changeState(Role::leftwalk);
//            global->player->setNowDestination(Role::left);
//            global->player->changeState(walk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            global->player->changeState(Role::idle);
        
            break;
        default:
            break;
    }
}
void ControllerLayer::jump(Ref *ref,Widget::TouchEventType type)
{
    
    
    //auto game=GameScene::createScene();
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
            global->player->changeState(Role::jump);
            //            global->player->setNowDestination(Role::left);
            //            global->player->changeState(walk);
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
           // global->player->changeState(Role::idle);
            
            break;
        default:
            break;
    }
}

void ControllerLayer::back(Ref *ref,Widget::TouchEventType type)
{
    
    switch ((int)type)
    {
        case (int)(cocos2d::ui::Widget::TouchEventType::BEGAN):
           
         
            break;
        case (int)(cocos2d::ui::Widget::TouchEventType::ENDED):
            
            
        case (int)(cocos2d::ui::Widget::TouchEventType::CANCELED):
            
             Director::getInstance()->replaceScene(TransitionFade::create(1,ChooseScene::createScene()));
            break;
        default:
            break;
    }
}



