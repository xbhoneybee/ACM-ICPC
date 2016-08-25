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


//����������޲������൱����ͨͼ���뵽���鼯
//�ò��鼯�ֳ����Խ���λ�õ��±꼯�ϣ�Ȼ����vectorװÿ�����ϵ��±��Ԫ�أ�
//Ȼ���ÿ�����ϵ�Ԫ������һ�¾ͺ��ˡ�
vector<int> num[1000005];
vector<int> vid[1000005];
int a[1000005],ans[1000005];
int father[1000005];
int find(int x)   
{
    if(x==father[x]) return x;
    return father[x]=find(father[x]);
}
void join(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y) return ;
    father[x]=y;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) //ע�⽻����a,b���Ĵ����1��ʼ������i=1��ʼ
    {
        father[i]=i;
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        join(a,b);
    }
    for(int i=1;i<=n;i++)
    {
        int x=find(i); //wa�� find��������λ�õ���ͨ���ò�a[i]
        num[x].push_back(a[i]);
        vid[x].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        sort(num[i].begin(),num[i].end(),greater<int>());//����
        for(int j=0;j<vid[i].size();j++)
        ans[vid[i][j]]=num[i][j];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}