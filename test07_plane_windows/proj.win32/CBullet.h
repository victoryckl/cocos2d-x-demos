#ifndef __BULLET_SCENE_H__
#define __BULLET_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

class CCBullet :
	public cocos2d::CCLayer
{
public:
	CCBullet(void);
	~CCBullet(void);
public:
	CCArray * m_pAllBullet;
	virtual bool init();
	CREATE_FUNC(CCBullet);
};

#endif //__BULLET_SCENE_H__

