#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            return 0;
        double sum=0.0;
        for(int i=n;i<=m;i++)
        {
             if(i>100000.0/i)
                 {
                     sum=0.00001;
                     break;
                 }
            else sum+=1.0/(i*i);
        }
        printf("%.5f\n",sum);
    }

    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}

//�пӵ㣬ע�⵱1.0/(i*i)��С�����޷���ʾ�������ó˷���ʾ�����ǵ�i*i��������ٽ�i����ȥ��