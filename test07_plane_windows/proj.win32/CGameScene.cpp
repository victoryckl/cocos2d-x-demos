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
		
		m_pPlane = CCPlane::create();
		addChild(m_pPlane);

		m_pBullet = CCBullet::create();
		addChild(m_pBullet);
		
		schedule(schedule_selector(CCGameScene::gameLogic), 0.1f);

		setTouchEnabled(true);
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

bool CCGameScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent) {
	//m_pPlane->moveTo(pTouch->getLocation());

	CCSprite * plane = (CCSprite *)m_pPlane->sharedPlane()->getChildByTag(747);
	CCSize s = plane->getContentSize();
	CCRect planeRect = CCRectMake(
		plane->getPositionX() - plane->getAnchorPoint().x*s.width, 
		plane->getPositionY() - plane->getAnchorPoint().y*s.height,
		plane->getContentSize().width, plane->getContentSize().height);
// 	CCLog("plane:(%.2f,%.2f),(%.2f,%.2f)", 
// 		plane->getPositionX(), plane->getPositionY(),
// 		plane->getContentSize().width, plane->getContentSize().height);
// 	CCLog("touch:%.2f,%.2f", pTouch->getLocation().x, pTouch->getLocation().y);
	if (planeRect.containsPoint(pTouch->getLocation()) ) {
		return true;
	}
	return false;
}

void CCGameScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent) {
	m_pPlane->moveTo(pTouch->getLocation());
//	CCLog("touch:%.2f,%.2f", pTouch->getLocation().x, pTouch->getLocation().y);
}

void CCGameScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent) {
}

void CCGameScene::registerWithTouchDispatcher(void) {
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}