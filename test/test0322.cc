#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

class PositiveInteger
{
public:
    vector <int> m_vecBegin;//the begin integer of the sequence
    vector <int> m_vecEnd;    //the end integer of the sequence

public:
    PositiveInteger()
    {
        m_vecBegin.clear();
        m_vecEnd.clear();
    }

    ~PositiveInteger(){}

    void GetIntegerSequence(int n);
    void display(int n);
};

//..............
//x1+x2+...+xi=n, ..: i>=2,x1<=n/2
//x2=x1+1
//x3=x1+2
//xi=x1+i-1
//i*x1+i*(i-1)/2=n  =>  x1=(n-i*(i-1)/2 )/i=n/i-(i-1)/2
void PositiveInteger::GetIntegerSequence(int n)
{
    int i,sum,begin;

    i=2;
    while(1)
    {
        begin=n/i-(i-1)/2;    //.....
        if(begin<1)
            break;

        //.begin.....i........n
        sum=i*begin+i*(i-1)/2;
        if(sum==n)    //..,........,......
        {
            m_vecBegin.push_back(begin);
            m_vecEnd.push_back(begin+i-1);
        }

        i++;
    }
}

void PositiveInteger::display(int n)
{
    int size=m_vecBegin.size();
    if(size==0)
    {
        printf("   NONE\n");
    }
    else
    {
        for(int i=size-1;i>=0;i--)
        {
            printf("   %d=%d",n,m_vecBegin.at(i));
            for(int j=m_vecBegin.at(i)+1;j<=m_vecEnd.at(i);j++)
                printf("+%d",j);
        }
        printf("\n");
    }
}

//....
void show_menu()
{
    printf("---------------------------------------------\n");
    printf("input command to test the program\n");
    printf("   i or I : input n to test \n");
    printf("   q or Q : quit\n");    
    printf("---------------------------------------------\n");
    printf("$ input command >");
}

int main()
{
    char sinput[10];
    int n;

    show_menu();

    scanf("%s",sinput);
    while(strcmp(sinput,"q")!=0)
    {
        if(strcmp(sinput,"i")==0)
        {
            printf("  please input an integer:");
            scanf("%d",&n);

            PositiveInteger obj;
            obj.GetIntegerSequence(n);
            obj.display(n);
        }

        //....
        printf("$ input command >");
        scanf("%s",sinput);
    }
	return 0;
}
