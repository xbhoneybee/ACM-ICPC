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


// ̰�� ���� ���Բ����ظ�ʹ��һ������ �뵽�����ܶ��λ�� wa����Щ���ִ�С��ͬ���ܳ�λ����ͬ
// wa�� ���̶�λ�� �����λ

struct N
{
    int id;
    int need;
}num[12];
int cmp (N a ,N b)
{
    if(a.need!=b.need) return a.need<b.need;
    else return a.id>b.id;
}
int cmp3(N a,N b)
{
    return a.id<b.id;
}

int v,dight;
int ans;
int main()
{
    scanf("%d",&v);
    for(int i=1;i<=9;i++)
        {
            scanf("%d",&num[i].need);
            num[i].id=i;
        }
    sort(num+1,num+10,cmp);
    dight=v/num[1].need;
    int temp=num[1].id;
    if(dight==0) printf("-1\n");
    else {                      //�����̰��д����������̫����
        v-=num[1].need*dight;
        sort(num+1,num+10,cmp3);
        for(int i=1;i<=dight;i++)
        {
            int j;
            ans=temp;
            for(j=9;j>=temp;j--)
            {
                if(num[j].need-num[temp].need<=v)
                {
                    ans=j;
                    v-=(num[j].need-num[temp].need);
                    break;
                }
            }
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}