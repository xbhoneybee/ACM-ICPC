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
#include <sstream>
#define inf 10000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//D  2�ֲ���
//���ȵ���ȷһ�㣬��ʼʱӲ������ƽ�����ٵ������ջ�����k��Ӳ�ң���ƽ������Ļ����k��Ӳ�ң�
//���Ը���������ö�������������ٵ�Ӳ������Ȼ�����ö��������������Ӳ������Ȼ�����������
ll c[500005];
int main()
{
    iosfalse
    ll n,k;
    cin>>n>>k;
    ll sum=0;
    ll ave;
    for(int i=0;i<n;i++)
        {cin>>c[i];sum+=c[i];}
    sort(c,c+n);
    if(c[n-1]==c[0])
    {
        cout<<0<<endl;
        return 0;
    }
    if(c[n-1]-c[0]==1)
    {
        cout<<1<<endl;
        return 0;
    }
    ave=sum/n;
    ll big,small;

    ll l=c[0]-1,r=ave;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        ll cost1=0;
        for(int i=0;c[i]<mid;i++)
        cost1+=(mid-c[i]);
        if(cost1<=k)
            small=mid,l=mid+1;
        else r=mid-1;
    }
    l=(sum+n-1)/n,r=inf;//wa��    һ���ӱ�ƽ������Ŀ�ʼ��  ��Ϊ����0��ʼ ����͵��Ӳ�ұȸ��Ķ�
    //������������10 20

    //6 4 7 10 4 5 5 3 7 10  big=5 small=7  ͵���ˣ���ʱҪ����ȥ������ֱ�Ӵ�sum+n-1  /n��ʼ��
    while(l<r)
    {
        ll mid=(l+r)>>1;
        ll cost2=0;
        for(int i=n-1;c[i]>mid&&i>=0;i--)
        cost2+=(c[i]-mid);
        if(cost2<=k)
            big=mid,r=mid;
        else l=mid+1;
    }
    cout<<big-small<<endl;
    return 0;
}

