#include <iostream>

class Shape {
public:
	virtual void draw() const = 0;
}; 

class Circle : public Shape {
public:
	virtual void draw() const {
		std::cout << "circle draw() call\n";
	}
};

int main()
{
	void (Circle::*mfarr[3])() const;
    // more gneneral as below
	// typedef (Circle::*mf)() const;
	// mf mfarr[3];	
	for (int i = 0; i < 3; i++) 
		mfarr[i] = &Shape::draw;
	Circle c;
	for (int i = 0; i < 3; i++) {
		std::cout << i << ": ";
		(c.*mfarr[i])();
	}
 	
	return 0;
}
