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

//dp
//�������ڶ�����i-1���˱����i��������˭���������������ν�ģ�
//������������������һ��������еģ���ô����ռ��λ�û������������
//��һ�������վ�ڶ��ף�����1����ǰ���ܿ�����������
//�ڶ��������վ�ڶ�β������1���ں����ܿ�����������
//�����������վ�ڶ����м䣬һ����i-2��λ�ÿ���վ�����������ӿɼ���������
//�������ܵõ�

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int l,r;
        cin>>l>>r;
        int dp[20][20][20]={0};
        //dp[i][j][k]��ʾһ��k�˴���i���ҿ�j���������
        dp[1][1][1]=1;
        for(int k=2;k<=n;k++)
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++)
        {
            dp[i][j][k]=dp[i-1][j][k-1]+dp[i][j-1][k-1]+dp[i][j][k-1]*(k-2);
        }
    cout<<dp[l][r][n]<<endl;
    }
    return 0;
}