#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int i=123;
    for(;i<=329;i++)
    {
        int a=i,b=i*2,c=i*3;
        int  num[10]={0};
        num[a/100]=1;
        num[a%100/10]=1;
        num[a%10]=1;
        num[b/100]=1;
        num[b%100/10]=1;
        num[b%10]=1;
        num[c/100]=1;
        num[c%100/10]=1;
        num[c%10]=1;
        int flag=0;
        for(int j=1;j<=9;j++)
        {
            if(num[j]==0)
                break;
            if(j==9) flag=1;
        }
        if(flag) cout<<a<<' '<<b<<' '<<c<<endl;
    }

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

//���ǵ�ȫ���м��������ʵ�֣���Сabc=123 ���ghi=987�����abc=329��ö��ÿ�������Ƿ�9������ȫ�����֡�