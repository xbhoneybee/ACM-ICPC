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
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 10000//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//  dp ��������ʵ����������������У�ֻ�����������зֱ��Ǵ�S��ǰһ���ֺʹ�S��һ���ֵ������С�
//int dp[5005][5005]; �ᱬ�ڴ� ��ȡ�����������

int dp[2][5005];
int main()
{
    iosfalse
    int n;
    char a[5050];
    char b[5050];
    while(scanf("%d",&n)!=EOF){
    memset(dp,0,sizeof dp);
    scanf("%s",a);   //cin ��scanf��Ҫ����
    int i;
    for( i=0;i<n;i++)
        b[i]=a[n-1-i];
    b[i]='\0';
    int ans=0;
    for(i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i-1]==b[j-1]) dp[i%2][j]=dp[1-i%2][j-1]+1;//��������
        else dp[i%2][j]=max(dp[1-i%2][j],dp[i%2][j-1]);
    }
    ans=dp[n%2][n];
    cout<<n-ans<<endl;
    }
    return 0;
}