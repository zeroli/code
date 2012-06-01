#include <iostream>

int main()
{
	int dirbyte=85;
	printf("0x%x\n", dirbyte);
	double ax = 250;
	double ay = 250;
	double cx = -250;
	double cy = -250;
	double tx = cx*2 + ax;
	double ty = cx*2 + ay;
	double aa = ax*ax + ay*ay;

	double tvx = 2*-125 - tx;
	double tvy = 2*-175 - ty;

	double t = tvx * ax + tvy * ay;
	std::cout << "tvx = " << tvx << ", tvy = " << tvy << std::endl;
	std::cout << "t = " << t << std::endl;
	std::cout << "aa = " << aa << std::endl;	
	double x = -125 - ax*t / aa;
	double y = -175 - ax*t / aa;

	std::cout << "x = " << x << ", y = " << y << std::endl;

	return 0;
}

