#include "CBullet.h"


CCBullet::CCBullet(void)
{
}

CCBullet::~CCBullet(void)
{
}

bool CCBullet::init() {
	bool sRet = false;
	do {
		CC_BREAK_IF(!CCLayer::init());
		m_pAllBullet = CCArray::create();

		sRet = true;
	}while(0);
	return sRet;
}
