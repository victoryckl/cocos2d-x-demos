#ifndef __CCPLANE_SCENE_H__
#define __CCPLANE_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

class CCPlane :
	public cocos2d::CCLayer
{
public:
	CCPlane(void);
	~CCPlane(void);

public:
	virtual bool init();
	CREATE_FUNC(CCPlane);
	void moveTo(CCPoint sp);
	static CCPlane * sharedPlane();

private:
	static CCPlane * m_plane;
};

#endif //__CCPLANE_SCENE_H__