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
	CCArray * m_pAllBullet;//�����ӵ�
	virtual bool init();//��ʼ��
    CREATE_FUNC(CCBullet);
	CCSpriteBatchNode * m_pBulletSprite;//�����ӵ�ͼƬ����
    void addNewBullet(float t);//����ӵ�
	void moveBullet(float t);//�ƶ��ӵ�
};
#endif
