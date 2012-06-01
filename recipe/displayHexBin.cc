#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void displayHexBin(const T& v)
{
	const unsigned char c2h[] = "0123456789ABCDEF";
	const unsigned char c2b[] = "01";
	
	unsigned char* p = (unsigned char*)&v;
	char* buf = new char [sizeof(T)*2+1];
	char* ptmp = buf;
	p = p + sizeof(T)-1;
	for (int i = 0; i < sizeof(T); i++, --p) {
		*buf++ = c2h[*p >> 4];
		*buf++ = c2h[*p & 0x0F];
	}	
	*buf = '\0';
	printf("hex format displayed as %s\n", ptmp);
	
	delete [] ptmp;
	p = (unsigned char*)&v; p = p + sizeof(T)-1;
	ptmp = buf = new char [sizeof(T)*8+1];
	for (int i = 0; i < sizeof(T); i++, --p) {
		for (int j = 0; j < 8; j++) 
			*buf++ = c2b[(*p >> (7-j)) & 0x1];
	}
	*buf = '\0';
	printf("bin format displayed as %s\n", ptmp);	
	delete [] ptmp;
}

int main()
{
	srand(time(0));
	int a = (int)rand()%100;
	
	std::cout << "original decimal format value = " << a << "\n";
	displayHexBin(a);	
	return 0;
}
