template <class T>
class Stack  {
	// LIFO object
public:
	Stack(int MaxStackSize = 10);
	~Stack() { delete [] stack; }
	
	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == MaxTop; }
	
	T Top() const;
	Stack<T>& Add(const T& x);
	Stack<T>& Delete(T& x);
	
private:
	int top;
	int MaxTop;
	T* stack;
};

template <class T>
Stack<T>::Stack(int MaxStackSize)
{
	MaxTop = MaxStackSize-1;
	stack = new T[MaxStackSize];
	top = -1;
}

template <class T>
T Stack<T>::Top() const
{
	if (IsEmpty()) throw OutOfBounds();
	else return stack[top];
}

template <class T>
Stack<T>& Stack<T>::Add(const T& x)
{
	if (IsFull()) throw NoMem();
	stack[++top] = x;
	return *this;
}

template <class T>
Stack<T>& Stack<T>::Delete(T& x)
{
	if (IsEmpty()) throw OutOfBounds();
	x = stack[top--];
	return *this;
}


	