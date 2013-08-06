#include "CPlane.h"
CCPlane* CCPlane::sharedPlane=NULL;
CCPlane::CCPlane(void)
{
}

CCPlane::~CCPlane(void)
{
}
bool CCPlane::init()
{bool sRet=false;
do{
  CC_BREAK_IF(!CCLayer::init());
  //加载飞机图片
  CCSprite * spPlane=CCSprite::create("player.png",CCRectMake(47*2,0,47,56));
  this->addChild(spPlane,0,747); 
  /////////创建动画//////////////////////////
  CCAnimation * animation=CCAnimation::create();
  animation->setDelayPerUnit(0.1f);
  //定义动画的每一帧
  for(int i=0;i<4;i++)
  {
	  animation->addSpriteFrame(
		  CCSpriteFrame::create("player.png",CCRectMake(47*i,0,47,56)));
  }
  //创建动画
  CCAnimate * anim=CCAnimate::create(animation);
  spPlane->runAction(::cocos2d::CCRepeatForever::create(anim));
  /////////////////////////////////
  spPlane->setPosition(ccp(200,200));

 sRet=true;
 }while(0);
 return sRet;
}
CCPlane *CCPlane::create()
{
    CCPlane *pRet = new CCPlane();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
		sharedPlane=pRet;
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
void CCPlane::moveTo(CCPoint p)
{
	this->getChildByTag(747)->runAction(CCMoveTo::create(1,p));
	this->getChildByTag(747)->setPosition(p);
}
