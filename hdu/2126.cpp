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


//�������ɵ�ƵĽ�ans ��S ��˳��㷴�ˣ�����10��� /(��o��)/~~
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int sou[35]={0};
        for(int i=1;i<=n;i++)
            scanf("%d",&sou[i]);
        sort(sou+1,sou+n+1);
        int S=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=sou[i];
            if(sum<=m) S++;
            else break;
        }
        if(S==0) {
            cout<<"Sorry, you can't buy anything."<<endl;
            continue;
        }
        int dp[505][35]={0};
        dp[0][0]=1;        //��ͳ�ʼ��1
        for(int i=1;i<=n;i++)
            for(int j=m;j>=sou[i];j--) //�����������
                for(int k=S;k>0;k--)
                {
                dp[j][k]+=dp[j-sou[i]][k-1];//�󷽰������
                }
        int ans=0;
        for(int i=0;i<=m;i++)
            ans+=dp[i][S];      //��Ŀ�ʵ�����s����������s����mԪ
        cout<<"You have "<<ans<<" selection(s) to buy with "<<S<<" kind(s) of souvenirs."
        <<endl;

    }
    return 0;
}