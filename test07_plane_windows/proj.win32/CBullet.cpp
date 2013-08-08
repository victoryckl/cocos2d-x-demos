#include "CBullet.h"
#include "CPlane.h"

CCBullet::CCBullet(void)
{
}

CCBullet::~CCBullet(void)
{
	m_pAllBullet->release();
	m_pAllBullet = NULL;
	m_pBulletSprite = NULL;
}

bool CCBullet::init() {
	bool sRet = false;
	do {
		CC_BREAK_IF(!CCLayer::init());
		m_pAllBullet = CCArray::create();
		m_pAllBullet->retain();//必须retain()，否则下面m_pAllBullet->addObject(bullet);会报错

		m_pBulletSprite = CCSpriteBatchNode::create("bullet3.png");
		addChild(m_pBulletSprite);

		schedule(schedule_selector(CCBullet::addBullet), 0.2f);
		schedule(schedule_selector(CCBullet::moveBullet), 0.1f);

		sRet = true;//必须返回true
	}while(0);
	return sRet;
}

void CCBullet::addBullet(float t) {
	CCSprite * bullet = CCSprite::createWithTexture(m_pBulletSprite->getTexture());
	m_pBulletSprite->addChild(bullet);
	bullet->setPosition(CCPlane::sharedPlane()->getChildByTag(747)->getPosition());
	m_pAllBullet->addObject(bullet);
}

void CCBullet::moveBullet(float t) {
	for (unsigned int i=0; i<m_pAllBullet->count(); i++) {
		CCSprite * bullet = (CCSprite *)m_pAllBullet->objectAtIndex(i);
		bullet->setPositionY(bullet->getPositionY()+15);

		if (bullet->getPositionY() > 480) {
			m_pAllBullet->removeObjectAtIndex(i);
			m_pBulletSprite->removeChild(bullet, true);
		}
	}
}