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

// ����dfs ��Ϊ���߶���������   dpö���Ӽ�,���ö�ά���鴢��

int main()
{
    int w[25]={0},dp[25][2005],sum;
    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i];
            sum+=w[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        //dp[i][j]=0 ��ʾ��i�������Ƿ���Գ�������Ϊj����Ʒ״̬
        for(int i=1;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
                if(dp[i-1][j] || dp[i-1][j+w[i]]||((j-w[i]>=0)?dp[i-1][j-w[i]]:0))
                //����         �������һ��    ��ԭ��������һ��
                dp[i][j]=1;
            }
    cin>>m;
    while(m--)
    {
        cin>>x;
        if(dp[n][x]&&x<=sum&&x>0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    }
        return 0;
}
