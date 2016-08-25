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


//��״����+��ɢ��  
//ÿ����һ�����͸�����״���飬�鿴��ǰ�����С���ѳ��ֹ����ж��ٸ���sum��
//Ȼ���õ�ǰλ�ü�ȥ��sum���Ϳ��Եõ���ǰ�����µ����������
//�����еļ����������ܵ����������
//val���ݷ�Χ�ϴ� ��ɢ������
//val���ԭ�����Ԫ�أ�pos���ԭʼλ�ã���node[i].pos = i��
//����Щ�ṹ�尴��val�Ĵ�С����
//reflect��������ɢ�����ֵ����reflect[node[i].pos] = i��
int n;
struct Node{
int pos;
ll val;
}node[500005];
ll tree[500005];//Cn = A(n �C 2^k + 1) + ... + An
int lowbit(int x)
{
    return x&-x;
}
void add(int k,int num)
{
    while(k<=n)
    {
        tree[k]+=num;
        k+= k&-k;
    }
}
bool cmp(const Node& a, const Node& b)
{
    return a.val < b.val;
}
void update(int x)//update tree x
{
    while(x<=n)
    {
        tree[x]+=1;
        x+=lowbit(x);
    }
}
int getsum (int k)
{
    int sum=0;
    while(k)
    {
        sum+=tree[k];
        k-=k&-k;
    }
    return sum;
}
ll reflect[500005];
int main()
{
    while(cin>>n&&n){
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&node[i].val);
        node[i].pos=i;
    }
    ll  ans=0;
    sort(node+1,node+n+1,cmp);
    for(int i=1;i<=n;i++)
        reflect[node[i].pos]=i;
    for(int i=1;i<=n;i++)
    {
        update(reflect[i]);
        ans+=i-getsum(reflect[i]);
    }
    cout<<ans<<endl;
    memset(tree,0,sizeof tree);
    }
    return 0;
}