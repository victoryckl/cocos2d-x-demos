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
	 CCSprite * m_pBackGround;//背景
	 CCSprite * m_pBackGround2;
	 CCPlane * m_pPlane;//飞机
	 CCBullet * m_PBullet;//主角子弹
	 //CCNpc *
public:
	virtual bool init();//初始化
	static CCScene * scene();//获取游戏场景
    CREATE_FUNC(CCGameScene);
	void gameLogic(float t);//游戏逻辑
	//处理按键
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void registerWithTouchDispatcher(void);
    
};
#endif