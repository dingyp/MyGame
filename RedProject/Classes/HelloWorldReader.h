//
//  HelloWorldReader.h
//  RedProject
//
//  Created by 丁逸鹏 on 15/3/1.
//
//

#ifndef __RedProject__HelloWorldReader__
#define __RedProject__HelloWorldReader__

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"
class HelloWorldReader:cocostudio::NodeReader
{
public:
    HelloWorldReader() {};
    ~HelloWorldReader() {};
    static HelloWorldReader* getInstance();
    static void purge();
    cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};


#endif /* defined(__RedProject__HelloWorldReader__) */
