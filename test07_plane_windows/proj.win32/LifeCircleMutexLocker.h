#ifndef __LIFE_CIRCLE_MUTEX_LOCKER_H__
#define __LIFE_CIRCLE_MUTEX_LOCKER_H__

#include <pthread.h>

class LifeCircleMutexLocker
{
	pthread_mutex_t* mutex;

public:
	LifeCircleMutexLocker(pthread_mutex_t* aMutex) : mutex(aMutex)
	{
		pthread_mutex_lock(mutex);
	}
	~LifeCircleMutexLocker(){
		pthread_mutex_unlock(mutex);
	}
};

#define LifeCircleMutexLock(mutex) LifeCircleMutexLocker __locker__(mutex)

#endif //__LIFE_CIRCLE_MUTEX_LOCKER_H__

