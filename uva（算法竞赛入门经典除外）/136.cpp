#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;

ll ugly[1505]={1,2,3,4,5};
int main()
{
    for(int i=5;i<1501;i++)
    {
        ll minn=inf;//ÿ�����µ�ugly[i] ����С����n-1λ����Ҫ����minn;
        for(int j=0;j<i;j++)
        {
            if(ugly[j]*2>ugly[i-1]&&ugly[j]*2<minn)
               {
                    minn=ugly[j]*2;
               }
            if(ugly[j]*3>ugly[i-1]&&ugly[j]*3<minn)
            {
                 minn=ugly[j]*3;
            }
            if(ugly[j]*5>ugly[i-1]&&ugly[j]*5<minn)
                {
                    minn=ugly[j]*5;
                }
        }

        ugly[i]=minn;
    }

    printf("The 1500'th ugly number is %I64d.\n",ugly[1499]);
    return 0;
}