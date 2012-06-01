template <class T>
class LinkedStack : private Chain<T> {
public:
	bool IsEmpty() const {
		return Chain<T>::IsEmpty(); 
	}
	bool IsFull() const {
		return Chain<T>::IsFull();
	}
	T Top() const {
		if (IsEmpty()) throw OutOfBounds();
		T x;
		Find(1, x); 
		return x;
	}
	
	LinkedStack<T>& Add(const T& x)
	{
		Insert(0, x); 
		return *this;
	}
	LinkedStack<T>& Delete(T& x)
	{	
		Chain<T>::Delete(1, x);
		return *this;
	}
};

template <class T>
bool LinkedStack<T>::IsFull() const
{
	try {
		ChainNode<T>* p = new ChainNode<T>;
		delete p; return false;
	}
	catch (NoMem) {
		return true;
	}
}


// ==================================
// User defined linked stack
template <class T>
class Node {
	friend LinkedStac<T>;
private:
	T data;
	Node<T>* link;
};

template <class T>
class LinkedStack {
public:
	LinkedStack() { top = 0; }
	~LinkedStack();
	bool IsEmpty() const { return top ==0; }
	bool isFull() const;
	T Top() const;
	LinkedStack<T>& Add(const T& x);
	LinkedStack<T>& Delete(T& x);
	
private:
	Node<T>* top;
};


	
