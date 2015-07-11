//
//  HelloWorldReader.cpp
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/1.
//
//

#include "HelloWorldReader.h"
#include "HelloWorldScene.h"
USING_NS_CC;
static HelloWorldReader* _instanceHelloWorldReader = nullptr;
HelloWorldReader*HelloWorldReader::getInstance()
{
    if (!_instanceHelloWorldReader)
    {
        _instanceHelloWorldReader = new HelloWorldReader();
    }
    return _instanceHelloWorldReader;
}