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

		m_pBackGround2 = CCSprite::create("background4.png");
		addChild(m_pBackGround2);
		m_pBackGround2->setAnchorPoint(CCPointZero);
		m_pBackGround2->setPosition(ccp(0, 680));
		
		schedule(schedule_selector(CCGameScene::gameLogic), 0.1f);
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

void CCGameScene::gameLogic(float t) {
	m_pBackGround->setPositionY(m_pBackGround->getPositionY() - 5);
	m_pBackGround2->setPositionY(m_pBackGround->getPositionY()+680);
	if (m_pBackGround2->getPositionY() <= 0) {
		m_pBackGround->setPositionY(0);
	}
}