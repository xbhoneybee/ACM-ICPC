#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
#include <string.h>
#include <set>
#include <queue>
#include <cctype>
#include <map>
#include <stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//���ʹ����״����
//n^2���Ӷȿ϶�TLE ��ÿһ������F*S ���Խ�ÿ�������߶����� ����Sһ�� ����F ����ۼ� O (n) �뵽O(log n)����״����
//Ԥ����
//c��Ӧ��ԭ�����ÿ��idx�±��idx֮�ͣ�d��Ӧԭ�����ÿ��idx�±��Ԫ�ظ�����
//c��������һ����ǰ����ߺ�����������С����֮�ͣ�d�������������ǰ���������С�ĸ����ĺ�
ll c[100005],d[100005];
int lowbit(int x)
{
     return x&(-x);
}
void addc(int i,ll val)
{
     while(i<=100005)
     {
         c[i]+=val;
         i+=lowbit(i);
     }
 }
ll sumc(int i)
 {
     ll s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
 }
void addd(int i,ll val)
 {
     while(i<=100005)
     {
         d[i]+=val;
         i+=lowbit(i);
     }
 }
ll sumd(int i)
 {
     ll s=0;
     while(i>0)
     {
         s+=d[i];
         i-=lowbit(i);
     }
     return s;
 }
 struct T
 {
    int x,h,idh,idx;
 }tree[100005];
int cmpx( T a, T b)
{
    return a.x<b.x;
}
int cmph(T a,T b)
{
    return a.h<b.h;
}
int cmpidh( T a, T b)
{
    return a.idh<b.idh;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
           scanf("%d %d",&tree[i].x,&tree[i].h);
        }
        sort(tree+1,tree+1+n,cmpx);
        for(int i=1;i<=n;i++)
        {
            if(i>1)
            {
                if(tree[i].x!=tree[i-1].x)
                    tree[i].idx=i;
                else tree[i].idx=tree[i-1].idx;
            }
            else tree[i].idx=1;
        }
        int maxx=tree[n].idx;
        sort(tree+1,tree+1+n,cmph);
        for(int i=1;i<=n;i++)
        {
            if(i>1)
            {
                if(tree[i].h!=tree[i-1].h)
                    tree[i].idh=i;
                else tree[i].idh=tree[i-1].idh;
            }
            else tree[i].idh=1;
        }
        sort(tree+1,tree+1+n,cmpidh);
        for(int i=1;i<=n;i++)
        {
            addc(tree[i].idx,tree[i].idx);
            addd(tree[i].idx,1);
        }
        ll ans=0,tem1,tem2;
        for(int i=1;i<n;i++)
        {
           //wa �� ������absֱ���� ҪԤ����(����״����)idx������ͱ���С�����ĸ��� ll tem=tree[i].idh*abs((n-i)*tree[i].idx-(sumd(n)-sumd(i)));
            tem1=sumd(tree[i].idx-1)*tree[i].idx-sumc(tree[i].idx-1);
            tem2=(sumd(maxx)-sumd(tree[i].idx))*tree[i].idx-(sumc(maxx)-sumc(tree[i].idx));
            ans+=(tem1-tem2)*tree[i].idh;
            addc(tree[i].idx,-tree[i].idx);//Ҫ�������ɾ��������������ظ��������
            addd(tree[i].idx,-1);
        }
        printf("%I64d\n",ans);
        memset(c,0,sizeof c);
        memset(d,0,sizeof d);
    }
    return 0;
}
