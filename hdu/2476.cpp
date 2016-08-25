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

// ����dp
//ˢ�ַ���

int main()
{
    char a[105],b[105];
    while(scanf("%s",a)!=EOF)
    {
        scanf("%s",b);
        int n=strlen (b);
        //dp[i][j]Ϊ i���j�������ַ���ˢ��һ��������С����
        int dp[105][105]={0};
        for(int j=0;j<n;j++)  //jΪβ��
              for(int i=j;i>=0;i--) //iΪ��ͷ
        {
            dp[i][j]=dp[i+1][j]+1;//��β��ˢ��ÿ��ˢһ���� ֵ ����dp[i][j] ���
            //�ʼĬ��aΪ�� ��aˢ��b��Ҫ�Ӻ���ǰˢ ÿ��ˢһ��
            //eg aaaaa -> bbbba->aaaba->ddaba->cdaba
            for(int k=i+1;k<=j;k++)
            {
                //Ѱ�� b��i k��ͬ ���ܼ���ˢ�Ĵ���
                if(b[i]==b[k])
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]);
                                           //i+1 k 2��������
                                //���� i k��ͬ ����Ӧ��dp[i][k-1]=dp[i+1][k]
                                //eg abcabc  �������� ˢ ��ʼ�� �����a ����ˢ
            }
        }
        int ans[105];
        for(int i=0;i<n;i++)
            ans[i]=dp[0][i];//��¼���ַ���a ��b ����
         for(int i=0;i<n;i++)
         {
             if(a[i]==b[i])
                {   if(i>0)
                    ans[i]=ans[i-1];//��Ӧ��� ��ˢ
                    else ans[i]=0;
                }
             else{
                //����� ���ǰi������j �ֿ�ˢ
                for(int j=0;j<i;j++)
                    ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
             }
         }
         cout<<ans[n-1]<<endl;
    }
    return 0;
}
