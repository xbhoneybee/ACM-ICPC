#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c))
    {
        if(a==0&&b==0&&c==0)
            return 0;
    int divint=a/b;
    a=a%b;
    int fen[105];
    for(int i=0;i<=c;i++)
    {
        a*=10;
        fen[i]=a/b;
        a%=b;
        if(i==c&&fen[c]>=5)
        fen[c-1]++;
    }
    cout<<divint<<'.';
    for(int i=0;i<c;i++)
        cout<<fen[i];
    cout<<endl;
    }

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

//���ڼ����doubleֻ�ܴ���15��17��λС�� ��c<=100 ,����ֱ���㣬����ģ��������̡�ע�����һλ�������롣