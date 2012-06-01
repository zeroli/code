#include <iostream>

#define N 10

class stackmin {
	int data[N];
	int minidx[N];
	int top;
public:
	stackmin() 
		: top(-1)
	{	
		::memset(minidx, -1, sizeof(int)*N);
		::memset(data, 0, sizeof(int)*N);
	}

	bool push(int d)
	{		
		if (top < N-1) 
			data[++top] = d;
		else
			return false;
		if (top==0) 
			minidx[top] = 0;
		else if (data[minidx[top-1]] > d)
			minidx[top] = top;
		else
			minidx[top] = minidx[top-1];
		return true;	
	}
	bool pop(int& d)
	{
		if (top<0)
			return false;
		else
			d = data[top];	
		minidx[top] = -1;
		top--;
		return true;
	}
	bool min(int& m)
	{
		if (top>=0)
			m = data[minidx[top]];
		else 
			return false;
		return true;
	}		
	void print()
	{
		for (int i = 0; i <= top; i++)
			std::cout << data[i] << " ";
		std::cout << "\n";
	}
};

int main()
{
	stackmin sm;
	int d[N] = { 4, 2, 9, 10, 7, 3, 1, 5, 8, 6};
	for (int i = 0; i < N; i++) {
		sm.push(d[i]);
		std::cout << "push " << d[i] << " => stack: ";
		sm.print();
		int minval; sm.min(minval);
		std::cout << "after push, min value = " << minval << std::endl;
	}
	std::cout << "\n";
	for (int i = 0; i < N; i++) {
		int val;
		sm.pop(val);
		std::cout << "pop " << val << " => stack: ";
		sm.print();
		int minval = -1;
		if (sm.min(minval)) {
			std::cout << "after pop, min value = " << minval << std::endl;
		} else 	
			std::cout << "no any value after pop\n";
	}
	return 0;
}
	
