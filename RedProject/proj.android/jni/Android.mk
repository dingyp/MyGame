LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

#define walk
 #  $(wildcard $(1)) $(foreach e,$(wildcard $(1)/*),$(call walk,$(e)))
#endef

#ALLFILES = $(ca) 

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
	           ../../Classes/GameScene.cpp \
		   ../../Classes/VisibleRect.cpp \
		   ../../Classes/Role.cpp \
		   ../../Classes/ControllerLayer.cpp \
	           ../../Classes/Global.cpp \
		   ../../Classes/SingleTon.cpp \
	           ../../Classes/Bomber.cpp \
		   ../../Classes/Player.cpp \
	           ../../Classes/JoyStick.cpp \
	           ../../Classes/MyGameScene.cpp \
		  ../../Classes/BaseGameScene.cpp \
		  ../../Classes/Item.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)
