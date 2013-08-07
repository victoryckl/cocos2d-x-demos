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
	virtual bool init();
	CREATE_FUNC(CCBullet);

	void addBullet(float t);
	void moveBullet(float t);

private:
	CCArray * m_pAllBullet;
	CCSpriteBatchNode * m_pBulletSprite;
};

#endif //__BULLET_SCENE_H__

