#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<set>
#include<queue>
#include<cctype>
#include<map>
#include<stack>
#define inf 1000000000
#define ll long long
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

//  cin ��scanf��Ҫ���ã�����
//�ҵ� ���� y-x=w[i]   ���У�     �ж��Ƿ���������

struct P {
    int val; //y-x
    int x;
    int y;
    int pos; //�������˳��
}po[100005];
struct W{
int wval;  //w[i]
int wpos;  //i
}w[100005];
int cmp0( P a,P b) //cmp0 || cmp1  �����һ��
{
    if(a.val!=b.val) return a.val<b.val;
    else  if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int cmp1( P a,P b)
{
    if(a.val!=b.val) return a.val<b.val;
    else  if(a.y!=b.y) return a.y<b.y;
    else return a.x<b.x;
}
int cmp2( W a,W b)
{
    if(a.wval!=b.wval) return a.wval<b.wval;
    else   return a.wpos<b.wpos;
}
int cmp3(P a,P b)
{
    return a.pos<b.pos;
}
int main()
{
    iosfalse
    int n;
    cin>>n;
        for(int i=0;i<n;i++)
           {
               int s,t;
               cin>>s>>t;
               po[i].x=s;
               po[i].y=t;
               po[i].val=t-s;
               po[i].pos=i;
           }
           sort(po,po+n,cmp1);
        for(int i=0;i<n;i++)
            {
                int temp;
                cin>>temp;
                w[i].wpos=i;
                w[i].wval=temp;
            }
            sort(w,w+n,cmp2);
        //�ҵ���������  �Ȱ�y-x���� ��w �����������һ���в�ͬ��һ������
        for(int i=0;i<n;i++)
        {
            if(po[i].val==w[i].wval)
            {
            po[i].pos=w[i].wpos;//�����pos�������x,y
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
        //�������ͬ��Ϊ�������������� ������ͬw[i] ��i���� ��ͬpoint y-x ��cmp0 ��cmp1 �Ĵ�������
        //��ʱ ��ͬy-x ������������ ��ͬ�Ĳ���һ��������������
        //�ж��Ƿ�������������
        sort(po,po+n,cmp3);
          for(int i=0;i<n-1;i++)
        {
            if(po[i].x<po[i+1].x||po[i].y<po[i+1].y)  //�����������������
                continue;
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<po[i].x<<' '<<po[i].y<<endl;

    return 0;
}