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
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1025;
//���� ÿ�������Ƿ���������ͨ ��ͨ��Ϊһ����ͨ��֧��
//���һ����temp����ͨ��֧ ֻ��temp-1���߿�ʹ������ͨ
//���䣨��һ�������鼯����
int fa[1024];
void initial(int n)//��ʼ��ÿ���򶼶���
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int findd(int x)//��ѯ
{
    while(fa[x]!=x)
        x=fa[x];
    return x;
}
void combine(int a,int b)//����
{
    int ta=findd(a);
    int tb=findd(b);
    if(ta!=tb)
        fa[ta]=tb;
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)&&n)
    {
        initial(n);
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            combine(a,b);
        }
        int temp=0;
        for(int i=1;i<=n;i++)
        {
            if(fa[i]==i)//Ѱ����ͨ���ʼ����
                temp++;
        }
        printf("%d\n",temp-1);
    }
    return 0;
}