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
#define inf 1000000000
#define ll long long
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;
#define iosfalse ios::sync_with_stdio(false);


//d��ȫ��������
//����Ҫ���

int main()
{
    int dp[10000]={1};
    int v[5]={1,5,10,25,50};
    for(int i=0;i<=4;i++)
        for(int j=v[i];j<=7500;j++)
        {
            dp[j]=dp[j]+dp[j-v[i]];
            //״̬ת�ƣ�jԪǮ������ �ɵ�i��coin��ɣ�ÿ�μ����µĵ�i��Ӳ�ҵ���ɷ���
        }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<dp[n]<<endl;
    }
    return 0;
}