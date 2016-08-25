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
const int MAXN=32005;

//��Ϊ��y�������star �����ж�ǰi-1��star���ж��ٸ�star��xС�ڵ�i����x
//�����������a[i]��ʾ�±�Ϊi��λ�����ж��ٸ�����
//cΪ���Ӧ��״����

int c[MAXN],level[MAXN],n;
int lowbit(int x)//����lowbit
{
     return x&(-x);
}
void update(int i,int val)//����i��Ԫ������valע��i����Ϊ��
 {
     while(i<=MAXN)//nΪ�����Ͻ�
     {
         c[i]+=val;
         i+=lowbit(i);
     }
 }
int sum(int i)//��ǰi���
 {
     int s=0;
     while(i>0)
     {
         s+=c[i];
         i-=lowbit(i);
     }
     return s;
 }
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        ++x;//��״�����1��ʼ
        level[sum(x)]++;//��������x���һ���е�������������level
        update(x,1);//��x������һ��star
    }
    for(int i=0;i<n;i++)
        printf("%d\n",level[i]);
    return 0;
}