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

//  |���� ǰ׺��+��׺�ͽ���ʱ�临�Ӷ�
//a[i]*x x>2 ��2���Ƴ�������,Ϊʹ�����󣬽�����x*��һ�𣬳���2�����������������ȷ����
//ö�� ǰ׺�ͺ�׺��ʹ���Ӷȴ�O(n*n)->O(n)

ll a[200005];
ll prea[200005];
ll sufa[200005];
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    prea[0]=0;//ע���ʼ��Ϊ0 ����1������
    sufa[n+1]=0;//
    for(int i=1;i<=n;i++)
        {
            prea[i]=prea[i-1]|a[i];
        }
     for(int i=n;i>=1;i--)
        {
            sufa[i]=sufa[i+1]|a[i];
        }
    ll mul=x;
    for(int i=1;i<k;i++)
        mul*=x;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,(a[i]*mul)|prea[i-1]|sufa[i+1]);
    }
    cout<<ans<<endl;

    return 0;
}
