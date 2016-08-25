#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

// �ݳ�ԭ��  ���ı�

LL gcd(LL x , LL y) //��1��Ϊ0 ������һ��
{
if(!y)
return x;
else return gcd(y , x%y);
}
LL lcm(LL x,LL y) //��С������
{
    return x/gcd(x,y)*y;
}
 vector<LL> p;
LL Solve(LL r)
{
    LL ans=0;
    if(p.size()==0) return 0;//wa��
    for(LL msk=1; msk<(1<<p.size()); msk++)
    {
        LL multi=1,bits=0;
        for(LL i=0; i<p.size(); i++)
        {
            if(msk&(1<<i))  //�жϵڼ�������Ŀǰ���õ�
            {
                ++bits;//�ж��м�λ���
                multi=lcm(p[i],multi);
            }
        }
        LL cur=r/multi;
        if(bits&1)  ans+=cur;//������
        else ans-=cur;
    }
    return ans;
}
int main()
{
    LL n,m;
    while(~scanf("%I64d %I64d",&n,&m))
    {
        int a[20]={0};
        for(int i=0;i<m;i++)
            {
                scanf("%d",&a[i]);
                if(a[i]==0) continue;  //wa��
                p.push_back(a[i]);//����4�� ���ֳܷ�2*2
            }
        ll ans=Solve(n-1);
        printf("%I64d\n",ans);
        p.clear();
    }
    return 0;
}