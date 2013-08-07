#include "CPlane.h"

CCPlane * CCPlane::m_plane = NULL;

CCPlane::CCPlane(void)
{
}


CCPlane::~CCPlane(void)
{
}

bool CCPlane::init() {
	bool sRet = false;
	do {
		CC_BREAK_IF(!CCLayer::init());
		CCSprite * spPlane = CCSprite::create("player.png", CCRectMake(0, 0, 47, 56));
		CC_BREAK_IF(!spPlane);
		addChild(spPlane, 0, 747);
		spPlane->setPosition(ccp(200, 200));

		CCAnimation * animation = CCAnimation::create();
		animation->setDelayPerUnit(0.1f);
		for (int i=0; i<4; i++) {
			animation->addSpriteFrame(CCSpriteFrame::create("player.png", CCRectMake(47*i, 0, 47, 56)));
		}
		CCAnimate * anim = CCAnimate::create(animation);
		spPlane->runAction(CCRepeatForever::create(anim));

		m_plane = this;
		sRet = true;
	}while(0);
	return sRet;
}

void CCPlane::moveTo(CCPoint p) {
	CCMoveTo * move = CCMoveTo::create(0.5, p);
	CCSprite * sp = (CCSprite*)getChildByTag(747);
	sp->runAction(move);
}

CCPlane * CCPlane::sharedPlane() {
	return m_plane;
}