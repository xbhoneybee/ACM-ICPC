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

ll gcd(ll x , ll y) 		//Ҫ��x>y,
{                           //ע��ll
    if(x<y) swap(x,y);
    if(!y)
    return x;
    else return gcd(y , x%y);
}
ll gbd(ll x,ll y)
{
    int gc=gcd(x,y);
    return (x/gc)*(y/gc)*gc;
}
int  main()
{
    long long  n,a,b,p,q;//ȫ��ll
    cin>>n>>a>>b>>p>>q;
    long long s=0;
    int minpq=min(p,q);
    s=p*(n/a);
    s-=minpq*(n/gbd(a,b));//�ҹ�������  n/��С������
    s+=q*(n/b);
    cout<<s<<endl;
    return 0;
}
