#ifndef _SINGLETON_H_
#ifndef _SINGLETON_H_

template <typename T>
class Singleton 
{
public:
	static T* Intance() {
		if (!m_pInstance) m_pInstance = new T;
		return m_pInstance;
	}
protected:
	Singleton();
	~Singleton();
private:
	Singleton(const Singleton&);
	Singleton& operator=(Singleton const &);
	static T* m_pInstance;
};

template <class T> 
T* Singeton<T>::m_pInstance = 0;

#endif
