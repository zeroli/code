#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Shape 
{
public:
  virtual void display() = 0; 
};

class Rect : public Shape
{
public:
  virtual void display() {
	cout << "Rect ";
  }
};

class Circle : public Shape
{
public:
  virtual void display() {
	cout << "Circle ";
  }
};

class Square : public Shape
{
public:
  virtual void display() {
	cout << "Square ";
  }
};

int main()
{
  vector<Shape*> v;
  v.push_back(new Rect());
  v.push_back(new Circle());
  v.push_back(new Square());
  v.push_back(new Circle());
  v.push_back(new Rect());
  for(int i = 0; i < v.size(); i++) 
	v[i]->display();
  cout << endl;

  for_each(v.begin(), v.end(), mem_fun(&Shape::display));
  cout << endl;
  return;
}
