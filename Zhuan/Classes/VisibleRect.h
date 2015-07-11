//
//  VisibleRect.h
//  Zhuan
//
//  Created by 丁逸鹏 on 15/5/7.
//
//

#ifndef __Zhuan__VisibleRect__
#define __Zhuan__VisibleRect__

#include <stdio.h>
#include "cocos2d.h"

class VisibleRect
{
public:
    static cocos2d::Rect getVisibleRect();
    
    static cocos2d::Vec2 left();
    static cocos2d::Vec2 right();
    static cocos2d::Vec2 top();
    static cocos2d::Vec2 bottom();
    static cocos2d::Vec2 center();
    static cocos2d::Vec2 leftTop();
    static cocos2d::Vec2 rightTop();
    static cocos2d::Vec2 leftBottom();
    static cocos2d::Vec2 rightBottom();
private:
    static void lazyInit();
    static cocos2d::Rect s_visibleRect;
};

#endif /* defined(__Zhuan__VisibleRect__) */
