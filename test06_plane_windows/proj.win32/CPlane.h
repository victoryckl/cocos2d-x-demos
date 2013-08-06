#ifndef __PLANE_SCENE_H__
#define __PLANE_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
class CCPlane :
	public cocos2d::CCLayer
{
public:
	CCPlane(void);
	~CCPlane(void);
public:
	static CCPlane *sharedPlane;
    virtual bool init();//初始化飞机
    static CCPlane * create();//创建飞机对象
	void moveTo(CCPoint p);//移动到某一点
};
#endif