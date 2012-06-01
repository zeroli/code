#include <iostream>
#include <cstring>

class CMyString {
public:
	CMyString(char* pData=NULL);
	CMyString(const CMyString& str);
	~CMyString() { delete [] m_pData; }
	CMyString& operator =(const CMyString& str);
	
private:
	char* m_pData;
};

CMyString::CMyString(char* pData)
	: m_pData(new char [strlen(pData)+1])
{
	memcpy(m_pData, pData, sizeof(strlen(pData)));
}

CMyString::CMyString(const CMyString& str)
{
	
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str) {
	CMyString strTemp(str);
	char* pTemp = strTemp.m_pData;
	strTemp.m_pData = m_pData;
	m_pData = pTemp;
	}
}
	
class A
{
public:
	A() {}
	~A() {}
private:
	int a;
};

int main()
{
	CMyString str1("String 1");
	CMyString str2("String 2");
	str2 = str1;
	A aa;
	int v = aa.a;
	return 0;
}
