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
#define mod 1000000007
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1024;

//��cross ������ʵ�������������
//��Am,An��Bm,Bn�������ٹ�·A,B�����ཻ����루Am-Bm��*(An-Bn)<0
int c[MAXN];
int t,n,m,k;
struct P
{
int l,r;
} p[MAXN*MAXN];//�������ô����·
int cmp( P a,P b)
{
    if(a.l!=b.l) return a.l<b.l;
    else return a.r<b.r;
}
int lowbit(int x)//����lowbit
{
     return x&(-x);
}
void update(int i,int val)//����i��Ԫ������valע��i����Ϊ��
 {
     while(i<=m)//MΪ�����Ͻ�
     {
         c[i]+=val;
         i+=lowbit(i);
     }
 }
ll sum(int i)//��ǰi��� ���1e6 *1e6 ��int
 {
     ll s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
 }
int main()
{

    scanf("%d",&t);
    for(int it=1;it<=t;it++)
    {
        ll ans=0;
        scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d %d",&p[i].l,&p[i].r);
    }
    sort(p+1,p+k+1,cmp);
    memset(c,0,sizeof c);
    for(int i=1;i<=k;i++)
    {
        update(p[i].r,1);
        ans+=i-sum(p[i].r);
        //iΪ��ǰ�Ѳ����Ԫ�صĸ�����getsum������С�ڵ��ڵ�ǰrֵ��Ԫ�ظ����������Ϊ����������Ԫ�ظ���
        //��С�ڵ��ڵ�ǰԪ�ظ�������i ��������� ��������i- sum��i���������
    }
        printf("Test case %d: %I64d\n",it,ans);
    }
    return 0;
}