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
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;
#define iosfalse ios::sync_with_stdio(false);


/*
״̬ѹ��DP+������
����Ľ���˼·����ö��ѡ�����ɸ�ʱ��״̬��
��״̬��Ϊ1<<n���ж���Щ״̬���������Щ��Ʒ�ܷ�һ�ξ�
���ߣ���������ߣ��ǾͰ����״̬����һ����Ʒ��Ԥ��������
��ö�����ҵ�tot����Ʒ��������tot����Ʒ��û�н���
��Ҳ��������״̬����ͬʱ����һ����Ʒ������Ʒ��
��01������ÿ����Ʒ�������state[i]����ֵ��1����
����n����Ʒ�����ټ�ֵҲ����dp[(1<<n)-1]��dp[i]��ʾ״̬i��Ҫ�˵����ٴ���)��
״̬ת�Ʒ���:dp[j|k] = min(dp[j|k],dp[k]+1) (kΪstate[i,1<=j<=(1<<n)-1])��
�㷨���Ӷ�O((2^N)*N)
*/
int n,c1,c2;
int w[15];
bool vis[1030];//vis[i]==1��ʾ�ܷ�����i�� furnitureΪһ�鱻c1װ��
int dp[1030];//dp[i]��ʾ��i�ö����Ʊ�ʾ�����������
int state[1030];
bool isok(int x)//�ж�״̬x�Ƿ��������
{
    int sum=0;
    memset(vis,0,sizeof vis);
    vis[0]=1;
    for(int i=0;i<n;i++)
    {
        if((x>>i)&1)//x�ĵ�iλΪ1
        {
            sum+=w[i];
            for(int j=c1;j>=w[i];j--)//�����ķǳ����� ��ʼ�����춼�������Լ�ģ��һ��Ŷ�
            {                   //����˵��״̬��c1��c2��c3,3���������һ�β��������c1���Ϊ1��
                if(vis[j-w[i]])//�ڶ��β�����c2��c1+c2����������Ϊ1�������ΰ�c3��ǰ�����ϱ��Ϊ1��
                    vis[j]=1;//�����Щ�������ϳɵ���������Ͷ�����ǳ���1
            }
        }
    }
    if(sum>c1+c2)  //װ����
        return 0;
    for(int i=0;i<=c1;i++)
    {
        if(vis[i]&&sum-i<=c2)//������Էֳ�i ��sum-i
            return 1;//����i���Ա�v1װ��(ǰ��forѭ���Ƕ���v1�ģ�vis[i]��ʾ���i���Ա�v1װ��)
                     //sun-i���Ա�v2װ��
    }
    return 0;
}
int tot;
void init()
{
    tot=0;
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]=inf;
        if(isok(i))
            state[tot++]=i;
    }
}
int main()
{
    iosfalse
    int t;
    cin>>t;
    for(int tst=1;tst<=t;tst++)
    {
        cin>>n>>c1>>c2;
        for(int i=0;i<n;i++)
            cin>>w[i];
        init();
        int V=(1<<n)-1;
        dp[0]=0;//û����Ʒ 0������
        for(int i=0;i<tot;i++)//ö�����п�����һ������
            for(int j=V;j>=0;j--)//ԭ��ı�����dp[j] = min(dp[j],dp[j-c[i]]+w[i])
                                //������Ȼ�����Ʋ��ñ�ʾ�������ǿ�����|�����
                                //����൱�ڱ����İ��dp[j+c[i]] = min(dp[j+c[i]],dp[j] + w[i])
        {
            if(dp[j]==inf)
                continue;
            if((j&state[i])==0)//�޽���
            {
                dp[j|state[i]]=min(dp[j]+1,dp[j|state[i]]);
            }

        }
        int ans=dp[V];
        cout<<"Scenario #"<<tst<<":"<<endl;
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}
