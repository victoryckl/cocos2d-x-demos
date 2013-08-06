#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class CCGameScene :
	public cocos2d::CCLayer
{
public:
	CCGameScene(void);
	~CCGameScene(void);

public:
	CCSprite * m_pBackGround;

public:
	virtual bool init();
	static CCScene * scene();
	CREATE_FUNC(CCGameScene);

	void gameLogic(float t);
};

#endif //__GAME_SCENE_H__