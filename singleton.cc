#include <iostream>

/**
 * singleton 1 version
 */
class singleton 
{
public:
	static singleton* instance()
	{
		if (!m_ps) 
			m_ps = new singleton();
		return m_ps;
	}

protected:
	singleton() { std::cout << "construct m_ps; \n"; }
	~singleton() { if (m_ps) { delete m_ps; std::cout << "delete/destory m_ps; \n"; } } 
	singleton(const singleton&) {}
	singleton& operator=(const singleton&) {}

private:
	static singleton* m_ps;
}; 

singleton* singleton::m_ps = 0;

/**
 * singleton2 version
 */
class singleton2
{
public:
	static singleton2& instance()
	{
		return m_s;
	}
protected:
	singleton2() {}
	~singleton2() {}
	singleton2(const singleton2&) {}
	singleton2& operator=(const singleton2&) {}
private:
	static singleton2 m_s;
};
singleton2 singleton2::m_s;

/**
 * singleton3 version
 */
class singleton3
{
public:
	static singleton3* instance()
	{
		if (!m_ps) {
			static singleton3 s;
			m_ps = &s;
		}
		return m_ps;
	}
	void printSomething() {
		std::cout << "print Something in singleton3.\n";
	}
protected:
	singleton3() {}
	~singleton3() { m_ps = 0; std::cout << "destroy singleton3.\n"; }
	singleton3(const singleton3&) {}
	singleton3& operator=(const singleton3&) {}
private:
	static singleton3* m_ps;
};
singleton3* singleton3::m_ps = 0;

/**
 * singleton multithread version
 */
class singletonmt
{
public:
	static singletonmt& instance()
	{
		if (!m_ps) {
//			locker(d_mutex);
			if (!m_ps) {
				static singletonmt smt;
				m_ps = &smt;
			}
		}
		return *m_ps;
	}
protected:
	singletonmt() {}
	~singletonmt() {}
	singletonmt(const singletonmt&) {}
	singletonmt& operator=(const singletonmt&) {}
private:
//	mutex d_mutex;
	static singletonmt* m_ps;
};
singletonmt* singletonmt::m_ps = 0;


int main()
{
	{
		singleton* g = singleton::instance();
	}
	{
		singleton3* sg = singleton3::instance();
		sg->printSomething();
	}
	return 0;
}

