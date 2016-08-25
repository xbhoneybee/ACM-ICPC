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

// ��Ԫ+����С����+�η���ģ+�����
//�������� �ȷ����һ��k, ʣ��a[k]-1 �������,�������k-1���ν���

ll PowerMod(ll a, ll b, ll c)
{
    ll ans = 1;
    a = a % c;
    while(b>0)
    {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b/2;
    a = (a * a) % c; }
    return ans;
}
ll C (ll n,ll m)
{
    if(m<n-m)
        m=n-m;
    ll ans=1;
    for(ll i=n;i>m;i--)
        {
            ans*=i;
            ans%=mod;
        }
    for(ll i=1;i<=n-m;i++)
        //ans/=i;
       ans= ans*(PowerMod(i,mod-2,mod))%mod;
    return ans%mod;
}
int main()
{
    int k;
    cin>>k;
    int a[1005]={0};
    for(int i=1;i<=k;i++)
        {
            scanf("%d",&a[i]);
        }
    int pre[1005]={0};
    for(int i=1;i<=k;i++)
        {
            pre[i]=pre[i-1]+a[i];
        }
    ll answer=1;
    for(int i=k;i>=1;i--)
    {
        answer*=(C(pre[i]-1,a[i]-1));
        answer%=mod;
    }
    cout<<answer%mod<<endl;
    return 0;
}