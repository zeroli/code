#ifndef THREADMISC_H
#define THREADMISC_H

#include <sys/types.h>
#include <inttypes.h>
#include <pthread.h>
#include <sched.h>
#include <cstdio>

class NoCopy
{
	private:
		NoCopy(const NoCopy&);
		NoCopy& operator=(const NoCopy&);
	public:
		NoCopy() {}
};

template  <typename T>
class TLS : public NoCopy
{
public:
	TLS(bool own = false) { pthread_key_create(&d_key, own ? &Destroy: 0); }
	~TLS() { pthread_key_delete(d_key); }
	
	void Set(const T* p) { pthread_setspecific(d_key, p); }
	T* Get() { return reinterpret_cast<T*>(pthread_getspecific(d_key)); }
	const T* Get() const { return reinterpret_cast<const T*>(pthread_getspecific(d_key)); }
	
private:
	static void Destroy(void* arg) { delete reinterpret_cast<T*>(arg); }

private:
	pthread_key_t d_key;
}; 

template <typename T> 
struct TLSDestroyableA
{
	TLSDestroyableA() 
		: data(true) {}
	~TLSDestroyableA() {
		Clear();
	}
	T& Get()
	{
		T* d = data.Get();
		if (!d) {
			d = new T;
			printf("new one d.\n");
			data.Set(d);
		}
		return *d;
	}
	const T& Get() const {
		return *data.Get();
	}
	T& operator() () { return Get(); }
	const T& operator() () const {
		return Get(); 
	}
	T* Ptr() {
		return data.Get(); 
	}
	void Clear() {
		T* d = data.Get();
		if (d) {
			delete d; 
			printf("deleting d.\n");
			data.Set(0);
		}
	}
	TLS<T> data;
}; 

class testA 
{
public:
	testA() { printf("construting testA.\n"); }
	~testA() { printf("destructing testA.\n");  }
	
private:
	TLSDestroyableA<int> d_data;
}; 

#endif
