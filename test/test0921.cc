#include <cstdio>

class point {
public:
//	virtual ~point() {}

	int x,y,z;
};

int main()
{
	printf("%d\n", &point::x);
	return 0;
}
	
