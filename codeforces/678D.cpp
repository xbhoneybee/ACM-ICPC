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

//�ݹ�ᱬջ��������tle


// �ȱ��������+�η���Ĥ+����С����+�˷���Ԫ

ll PowerMod(ll a, ll b, ll c)
{
        ll ans = 1;
        a = a % c;
        while(b>0)
        {
            if(b % 2 == 1)
            ans = (ans * a) % c;
            b = b/2;
            a = (a * a) % c;
        }
    return ans;
}
int main()
{
    ll a,b,x,n;
    cin>>a>>b>>n>>x;
    if(a==1)   //divide
        cout<<(x+n%mod*b)%mod<<endl;
    else{
        //��b*(an-1)/(a-1)��modȡģ 
        //a-1 �ĳ˷���ԪΪ��a-1)��mod-2�η�==1/(a-1)  ����С����
        ll ans1=(PowerMod(a,n,mod)*x)%mod;
        ll ans=PowerMod(a-1,mod-2,mod);//����С����+��Ԫ
        ll ans2=(PowerMod(a,n,mod)-1)*(ans)%mod*b;
        ll ans3=(((ans1+ans2) %mod )+mod )% mod;
        cout<<ans3<<endl;
    }
    return 0;
}
