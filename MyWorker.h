#ifndef WORKER_H_
#define WORKER_H_
#include "thread.h"

template <typename T, typename A=int>
class Worker : public Thread
{
public:
	Worker(T& obj,  void* (T::*work)()) 
		: Thread(1048576), d_type(0), d_obj(obj)
	{ d_work.work0 = work; }
	
	Worker(T& obj, void* (T::*work)(A), A arg) 
		: Thread(1048576), d_type(1), d_obj(obj), d_arg(arg)
	{ d_work.work1 = work; }
	
	Worker(T& obj, void (T::*work)())
		: Thread(1048576), d_type(2), d_obj(obj)
	{ d_work.work2 = work; }
	
	Worker(T& obj, void (T::*work)(A), A arg)
		: Thread(1048576), d_type(3), d_obj(obj), d_arg(arg)
	{ d_work.work3 = work; }

protected:
	 virtual void* Run() {
		void* rval = 0;
		switch (d_type) {
			case 0:
				rval = (d_obj::*d_work.work0)();
				break;
			case 1:
				rval = (d_obj::*d_work.work1)(d_arg);
				break;
			case 2:
				(d_obj::*d_work.work2)();
				break;
			case 3:
				(d_obj::*d_work.work3)(d_arg);
				break;
			default:
				break;
		}
		return rval;
	}
	int d_type;
	T& d_obj;

	union {
		void* (T::*work0)();
		void* (T::*work1)(A);
		void (T::*work2)();
		void (T::*work3)(A);
	} d_work;
	A d_arg;
};

#endif
