#ifndef __CCGAMESCENE_SCENE_H__
#define __CCGAMESCENE_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"
#include "CPlane.h"

USING_NS_CC;

class CCGameScene : public CCLayer
{
public:
	CCGameScene(void);
	~CCGameScene(void);

public:
	virtual bool init();
	static CCScene * scene();
	CREATE_FUNC(CCGameScene);

	void gameLogic(float t);

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void registerWithTouchDispatcher(void);

private:
	CCSprite * m_pBackGround;
	CCSprite * m_pBackGround2;
	CCPlane * m_pPlane;
};

#endif //__CCGAMESCENE_SCENE_H__