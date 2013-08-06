#include "CGameScene.h"

CCGameScene::CCGameScene(void)
{
}

CCGameScene::~CCGameScene(void)
{
}
bool CCGameScene::init()//初始化
{ bool sRet=false;
  do{
	  CC_BREAK_IF(!CCLayer::init());
      //加载背景
	  this->m_pBackGround=CCSprite::create("background4.png");
	  this->addChild(m_pBackGround);
	  this->m_pBackGround->setAnchorPoint(ccp(0,0));
	  this->m_pBackGround->setPosition(ccp(0,0));
	  this->m_pBackGround2=CCSprite::create("background4.png");
	  this->addChild(m_pBackGround2);
	  this->m_pBackGround2->setAnchorPoint(ccp(0,0));
	  this->m_pBackGround2->setPosition(ccp(0,680));
	  //加载飞机
	  this->m_pPlane=CCPlane::create();
      this->addChild(m_pPlane);
	  //加载子弹
	  this->m_PBullet=CCBullet::create();
	  this->addChild(m_PBullet);
	  //加载敌机
	  ////////////加入计划任务
	  this->schedule(schedule_selector(CCGameScene::gameLogic),0.1f);
	  this->setTouchEnabled(true);
	  sRet=true;
  }while(0);
  return sRet;
}
CCScene * CCGameScene::scene()//获取游戏场景
{ CCScene * scene=NULL;
 do{
	 scene=CCScene::create();
	 CC_BREAK_IF(!scene);//如果scene为空跳出
	 CCGameScene * game=CCGameScene::create();
	 CC_BREAK_IF(!game);
	 scene->addChild(game);//把图层添加到场景

 }while(0);
  return scene;  
}
void CCGameScene::gameLogic(float t)
{
	this->m_pBackGround->setPositionY(
		this->m_pBackGround->getPositionY()-5);
	this->m_pBackGround2->setPositionY(
		this->m_pBackGround->getPositionY()+680);
	if(m_pBackGround2->getPositionY()==0)
	{
		m_pBackGround->setPositionY(0);
	}
}
 
void CCGameScene::registerWithTouchDispatcher()
  {
		CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,INT_MIN+1,true);
 }
bool CCGameScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
	this->m_pPlane->moveTo(pTouch->getLocation());
	return true;
}
void CCGameScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
}
void CCGameScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
}
   
  

