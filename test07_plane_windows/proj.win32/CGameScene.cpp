#include "CGameScene.h"


CCGameScene::CCGameScene(void)
{
}


CCGameScene::~CCGameScene(void)
{
}

bool CCGameScene::init() {
	bool sRet = false;
	do {
		CC_BREAK_IF(!CCLayer::init());
		m_pBackGround = CCSprite::create("background4.png");
		addChild(m_pBackGround);
		m_pBackGround->setAnchorPoint(CCPointZero);
		m_pBackGround->setPosition(CCPointZero);
		sRet = true;
	}while(0);
	return sRet;
}

CCScene * CCGameScene::scene() {
	CCScene * scene = NULL;
	do {
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		CCGameScene * game = CCGameScene::create();
		CC_BREAK_IF(!game);
		scene->addChild(game);
	}while(0);
	return scene;
}
