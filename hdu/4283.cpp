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

//����dp

int main()
{
    int t;
    scanf("%d",&t);
    for(int m=1;m<=t;m++)
    {
        int n;
        scanf("%d",&n);
        int diao[105];
        int dp[105][105]={0};
        int sum[105]={0};
        for(int i=1;i<=n;i++)
            {
                scanf("%d",&diao[i]);
                sum[i]=diao[i]+sum[i-1];//ǰ׺�ͣ�ǰi����˿��diaoֵ
            }
            //dp[i][j]��ʾi��j��һ�ε���Сֵ����ʼ�����ݽ�i��j(j>i) ��dp inf;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    dp[i][j]=inf;
            for(int l=1;l<=n;l++) //   l ���䳤��
                for(int i=1;i<=n-l+1;i++) //i ö�����
            {
                int j=i+l;  //jΪ��β(����)
                for(int k=1;k<=j-i+1;k++)
                {//����dp[i][j]�ĵ�i���ˣ����п��ܵ�1���ϳ���Ҳ���Ե�j-i+1���ϳ������ǵ�K���ϳ�
                    dp[i][j]=min(dp[i][j],dp[i+1][i+k-1]+dp[i+k][j]+k*(sum[j]-sum[i+k-1])+diao[i]*(k-1));
                    //��  i+1  �� i+k-1  �ܹ���k-1����Ҫ��i�ȳ�ջ��
                    //�� i+k   ��j �ܹ�j-i-k+1������i�����ջ

                                            //��i���˵�k���ϳ� diao ֵ diao[i]*(k-1)
                //���������ڵ�k+1��֮��,Ҳ����һ��������dp[i+k][j]��
                //�������������ˣ��������ڵ�k+1��֮�������ŭֵҪ����k*(sum[j]-sum[i+k-1])
                }                           //��i���˵�k���ϳ� diao ֵ diao[i]*(k-1)
            }
          int   ans=dp[1][n];
        cout<<"Case #"<<m<<": "<<ans<<endl;
    }
    return 0;
}
//���Էֿ������飬����ö�٣����������