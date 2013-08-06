#include "CCGameScene.h"


CCGameScene::CCGameScene(void)
{
}


CCGameScene::~CCGameScene(void)
{
}

bool CCGameScene::init() {
	bool sRet = false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		m_pBackGround = CCSprite::create("background4.png");
		addChild(m_pBackGround);
		m_pBackGround->setAnchorPoint(ccp(0, 0));
		m_pBackGround->setPosition(ccp(0, 0));

		schedule(schedule_selector(CCGameScene::gameLogic), 0.1f);

		sRet = true;
	} while (0);
	return sRet;
}

CCScene * CCGameScene::scene() {
	CCScene * scene = NULL;
	do
	{
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
}