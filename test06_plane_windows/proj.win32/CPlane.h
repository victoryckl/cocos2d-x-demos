#ifndef __PLANE_SCENE_H__
#define __PLANE_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
class CCPlane :
	public cocos2d::CCLayer
{
public:
	CCPlane(void);
	~CCPlane(void);
public:
	static CCPlane *sharedPlane;
    virtual bool init();//��ʼ���ɻ�
    static CCPlane * create();//�����ɻ�����
	void moveTo(CCPoint p);//�ƶ���ĳһ��
};
#endif