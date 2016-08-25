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

//D  ����dp
//�����ʵ�������� ��Ҫ�Ǳ߽翼��
double dp[2005][2005][2][2];//0<-    1-> i,j,����i-1 ��f1 j+1�� f2�� ʱ���ǳ���
int vis[2005][2005][2][2];
int downl[2005];
int downr[2005];
int v[2005];
int n,h;
double p;
double dfs(int l,int r,int f1,int f2)
{   // 0 means fall left, 1 means fall right
    if(vis[l][r][f1][f2])
        return dp[l][r][f1][f2];
    if(l>r)
        return 0;
    vis[l][r][f1][f2]=1;//��Ǽ����
    double ans =dp[l][r][f1][f2];
    
    ans+=p*0.5*(min(h*1,v[l]-v[l-1]-f1*h)+dfs(l+1,r,0,f2));//���������
            //���i-1��i��Զ ��h, �Ͻ����� ֻ���Ǹ��ǵ� i-1��λ�ã������ҿ��ǣ���
            //min()����д��ʮ�־���࿴�����
    ans+=(1-p)*0.5*(min(h*1,v[r+1]-v[r]-f2*h)+dfs(l,r-1,f1,0));//���ұߵ�
    
    int L =downr[l];//������ұߵ� L��ʾ��Ӱ�쵽�����
    int R =downl[r];//�ұ�����ߵ�
    if(R<=l) ans+=p*0.5*(v[r]-v[l]+min(h,v[l]-v[l-1]-f1*h));
    else  ans += p*0.5*(v[r]-v[R]+h+dfs(l,R-1,f1,1));
    if(L>=r) ans+=(1-p)*0.5*(v[r]-v[l]+min(h,v[r+1]-v[r]-f2*h));
    else ans+=(1-p)*0.5*(v[L]-v[l]+h+dfs(L+1,r,1,f2));
    dp[l][r][f1][f2]=ans;//��¼��
    return ans;
}
int main()
{
    cin>>n>>h>>p;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    sort(v+1,v+1+n);//because no in particular order so sort
    v[n+1]=inf;  //imagine two trees there the most left and the most right
    v[0]=-inf;
    downr[n]=n;  //  down to right can effect the n th tree  
    downl[1]=1;
    for(int i=n-1;i>=1;i--)
    {
        if(v[i+1]-v[i]<h)
            downr[i]=downr[i+1];
        else
            downr[i]=i;
    }
    for(int i=2;i<=n;i++)
    {
        if(v[i]-v[i-1]<h)
            downl[i]=downl[i-1];
        else downl[i]=i;
    }
    printf("%.15f\n",dfs(1,n,0,0));
    return 0;
}
