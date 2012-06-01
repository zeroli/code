#include <cstdio>

int main()
{
	unsigned short s = 0xff10;
	unsigned char* p = (unsigned char*)&s;
	printf("s = %x\n", s);
	printf("p = %x\n", *p);

	unsigned short s1 = *(unsigned short*)p;
	printf("s1 = %x\n", s1);

	FILE* f = fopen("a.dat", "wb");
	unsigned char p1 = (unsigned char)((s >> 8) & 0xff);
	unsigned char p2 = (unsigned char)(s & 0xff);
	fwrite((const char*)&p1, 1, sizeof(unsigned char), f);
	fwrite((const char*)&p2, 1, sizeof(unsigned char), f);
	fclose(f);

	unsigned char* pbuf = new unsigned char[3];
	FILE* f1 = fopen("a.dat", "rb");	
	fread(pbuf, 1, 3, f1);
	printf("high = %x\n", *pbuf);
	printf("low = %x\n", *(pbuf+1));
	fclose(f1);

	unsigned short s2 = *(unsigned short*)pbuf;
	printf("s2 = %x\n", s2);
	delete [] pbuf;
	return 0;
}
