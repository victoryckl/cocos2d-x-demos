#ifndef __LIFE_CIRCLE_LOGGER_H__
#define __LIFE_CIRCLE_LOGGER_H__

#include "cocos2d.h"

USING_NS_CC;

class LifeCircleLogger{
	std::string m_msg;
public:
	LifeCircleLogger(){}
	LifeCircleLogger(const std::string& msg):m_msg(msg){ CCLog("%s BEGINS!", m_msg.c_str()); }
	~LifeCircleLogger(){ CCLog("%s ENDS!",m_msg.c_str()); }
};
#define LOG_FUNCTION_LIFE LifeCircleLogger(__FUNCTION__); 

#endif //__LIFE_CIRCLE_LOGGER_H__

