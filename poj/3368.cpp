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
#define inf 1000000000
#define ll long long
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
#define iosfalse ios::sync_with_stdio(false);
using namespace std;
const int MAXN=1025;


int n,q;
int a[100005];
int f[100005];
int maxsum[100005][20];
void RMQ(int num) //Ԥ����->O(nlogn)
{
	for(int i=1;i<=num;i++)
        maxsum[i][0]=f[i];//f[i]Ϊ����������
    int k=log(double(num+1))/log(2.0);
	for(int j = 1; j <= k; ++j)
		for(int i = 1; i + (1 << j) - 1 <= num; ++i)
			{
				maxsum[i][j] = max(maxsum[i][j - 1], maxsum[i + (1 << (j - 1))][j - 1]);
			}
}
int query(int l,int r)
{
    if(l>r) return 0;
    int k=floor(log2(r-l+1));
    return max(maxsum[l][k],maxsum[r-(1<<k)+1][k]);
}
int main()
{
    while(scanf("%d %d",&n,&q)&&n){
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    f[1]=1;
    for(int i=2;i<=n;i++)//�����ִ�����Ϊ�������鴢������
    {
        if(a[i]==a[i-1])
        f[i]=f[i-1]+1;
        else f[i]=1;
    }
    RMQ(n);
    while(q--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        int t=l;   //��߿��ܲ�����,Ѱ���ұߵ�һ����ͬ��������
        while(t<=r&&a[t]==a[t-1])
            t++;
        int ans = max(t-l,query(t,r));
        printf("%d\n",ans);
    }
    }
    return 0;
}