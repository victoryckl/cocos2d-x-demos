#include "CBullet.h"
#include "CPlane.h"
CCBullet::CCBullet(void)
{
}

CCBullet::~CCBullet(void)
{
}
bool CCBullet::init()
{bool sRet=false;
do{CC_BREAK_IF(!CCLayer::init());
  //��ʼ���ӵ�����
  this->m_pAllBullet=CCArray::create();
  m_pAllBullet->retain();
  this->m_pBulletSprite=CCSpriteBatchNode::create("bullet3.png");
  this->addChild(m_pBulletSprite);
  //ÿ��300�������1���ӵ�
  this->schedule(schedule_selector(CCBullet::addNewBullet),0.3f);
  //ÿ��100�����ƶ��ӵ�
  this->schedule(schedule_selector(CCBullet::moveBullet),0.1f);
 sRet=true;
 }while(0);
 return sRet;
}
 void CCBullet::addNewBullet(float t)//����ӵ�
 {
	 CCSprite * spriteBullet=CCSprite::createWithTexture(this->m_pBulletSprite->getTexture());
	 this->m_pBulletSprite->addChild(spriteBullet);
	 spriteBullet->setPosition(CCPlane::sharedPlane->getChildByTag(747)->getPosition());
	 this->m_pAllBullet->addObject(spriteBullet);
 }
 void CCBullet::moveBullet(float t)//�ƶ��ӵ�
 {
	 for(int i=0;i<m_pAllBullet->count();i++)
	 {  //�õ���i���ӵ�
		 CCSprite * nowBullet=(CCSprite *)m_pAllBullet->objectAtIndex(i);
		 nowBullet->setPositionY(nowBullet->getPositionY()+10);
		 if(nowBullet->getPositionY()>480)
		 { 
			 m_pAllBullet->removeObjectAtIndex(i);
			 m_pBulletSprite->removeChild(nowBullet,true);
		 }
	 }
 
 }