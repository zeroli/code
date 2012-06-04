#include <sys/time.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "thread.h"

#include <cassert>

Thread::Thread(int stacksize)
{
	pthread_attr_init(&d_attr);
	if (stacksize > )
		pthread_attr_setstacksize(&d_attr);
	pthread_attr_setinheritsched(&d_attr, PTHREAD_INHERIT_SCHED);
	d_autodel = false;
	d_started = false;
}

Thread::~Thread()
{
	if (d_started)
		pthread_detach(d_thread);
	pthread_attr_destroy(&d_attr);
}

bool Thread::Start()
{
	if (!d_started && pthread_create(&d_thread, &d_attr, Run, this) == 0)
		d_started = true;
	return d_started;
}

void Thread::Stop()
{
	if (d_started && pthread_cancel(d_thread) == 0)
		Wait();
}

void* Thread::Wait()
{
	void* rv = 0;
	if (d_started) {
		pthread_join(d_thread, &rv);
		d_started = false;
	}
	return rv;
}

void* Thread::Run(void* arg)
{
	Thread* p = reinterpret_cast<Thread*>(arg);
	void* rv;
	pthread_cleanup_push(Cleanup, p);

	while (pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0) != 0);
	rv = p->Run();
	pthread_cleanup_pop(1);
	return rv;
}

void Thread::Cleanup(void* arg)
{
	Thread* p = reinterpret_cast<Thread*>(arg);
	p->Cleanup();
}

void Thread::Raise(int sig) const
{
	pthread_kill(d_thread, sig);
}


// =============================
int Cond::TimedWait(Mutex& mutex, int msec)
{
	struct timeval tv;
	gettimeofday(&tv, 0);
	int ret;
	tv.tv_sec += msec / 1000;
	tv.tv_usec += msec % 1000 * 1000;
	if (tv.tv_usec >= 1000000) {
		tv.tv_sec++;
		tv.tv_usec -= 1000000;
	}
	struct timespec ts;
	ts.tv_sec = tv.tv_sec; ts.tv_nsec = tv.tv.usec * 1000;
	pthread_cleanup_push((void (*)(void*))pthread_mutex_unlock, &mutex.d_mutex);
	ret = pthread_cond_timedwait(&d_cond, &mutex.d_mutex, &ts);
	pthread_cleanup_pop(0);
	return ret;
}

