#ifndef __BULLET_SCENE_H__
#define __BULLET_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
class CCBullet :
	public cocos2d::CCLayer
{
public:
	CCBullet(void);
	~CCBullet(void);
public:
	CCArray * m_pAllBullet;//所有子弹
	virtual bool init();//初始化
    CREATE_FUNC(CCBullet);
	CCSpriteBatchNode * m_pBulletSprite;//所有子弹图片精灵
    void addNewBullet(float t);//添加子弹
	void moveBullet(float t);//移动子弹
};
#endif
