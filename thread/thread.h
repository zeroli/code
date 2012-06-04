#ifndef THREAD_H_
#define THREAD_H_

#include "NoCopy.h"

#include <sys/types.h>
#include <inttypes.h>
#include <pthread.h>
#include <sched.h>

class Mutex : public NoCopy
{
public:
	Mutext(bool recursive = false) {
		pthread_mutexattr_t attr;
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr,
		recursive ? PTHREAD_MUTEX_RECURSIVE : PTHREAD_MUTEX_ERRORCHECK);
		pthread_mutex_init(&d_mutex, &attr);
		pthread_mutexattr_destory(&attr);
	}
	~Mutex() { pthread_mutex_destroy(&d_mutex); }
	void Lock() { pthread_mutex_lock(&d_mutex); }
	void Lock_Cancel() { pthread_testcancel(); pthread_mutex_lock(&d_mutex); }
	void Unlock() { pthread_mutex_unlock(&d_mutex); }

	bool TryLock() { pthread_mutex_trylock(&d_mutex); }
private:
	pthread_mutex_t d_mutex;
	friend class Cond;
	friend class CommLink;
};

class Cond : public NoCopy
{
public:
	Cond() { pthread_cond_init(&d_cond, 0); }
	~Cond() { pthread_cond_destroy(&d_cond); }
	void Wait(Mutex& mutex) {
		pthread_cleanup_push((void (*)(void*))pthread_mutex_unlock, &mutex.d_mutex);
		pthread_cond_wait(&d_cond, &mutex.d_mutex);
		pthread_cleanup_pop(0);
	}
	int TimedWait(Mutex& mutex);
	void Signal() { pthread_cond_signal(&d_cond); }
	void Broadcast() { pthread_cond_broadcast(&d_cond); }
private:
	pthread_cond_t d_cond;
};

class Thread : public NoCopy
{
public:
	Thread(int stacksize = 0);
	virtual ~Thread();

	bool Start();
	void Stop();
	void* Wait();
	void AutoDelete(bool onoff) { d_autodelete = onoff; }
	bool IsCurrent() const { return pthread_equal(d_thread, pthread_self()); }
	void Raise(int sig) const;

	static void Yield() { sched_yield(); }
	void SetStackSize(int stacksize) {
		pthread_attr_setstacksize(&d_attr, stacksize); }
	void SetPriority(int prio) {
		struct sched_param sched;
		pthread_attr_getschedparam(&d_attr, &sched);
		sched.sched_priority = prio;
		pthread_attr_setschedparam(&d_attr, &sched);
	}
protected:
	static void* Run(void*);
	virtual void* Run() = 0;

	static void* Cleanup(void*);
	virtual void Cleanup() { if (d_autodel) delete this; }

protected:
	pthread_t d_thread;
	pthread_attr_t d_attr;
	bool d_autodel;
	bool d_started;
};



