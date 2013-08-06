#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "CPlane.h"
#include "CBullet.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
class CCGameScene :
	public cocos2d::CCLayer
{
public:
	CCGameScene(void);
	~CCGameScene(void);
public:
	 CCSprite * m_pBackGround;//����
	 CCSprite * m_pBackGround2;
	 CCPlane * m_pPlane;//�ɻ�
	 CCBullet * m_PBullet;//�����ӵ�
	 //CCNpc *
public:
	virtual bool init();//��ʼ��
	static CCScene * scene();//��ȡ��Ϸ����
    CREATE_FUNC(CCGameScene);
	void gameLogic(float t);//��Ϸ�߼�
	//������
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void registerWithTouchDispatcher(void);
    
};
#endif