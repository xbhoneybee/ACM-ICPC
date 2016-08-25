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

//�ⶼ������ /(��o��)/~~
//�����  1 �ĸ�����3�ı���(����0)
//���������  
/* k==1ʱ ��Ϊ������ k==2ʱ��a[i]a[j]���Ľ���������c c��һ��0,1��������c=c*c
����c[i][j]=c[i][1]*c[1][j]+c[i][2]*c[2][j]+...+c[i][n]*c[n][j]�����ǵõ��ļ�Ϊ��
ai��ͷ��aJ��β�ĳ���Ϊ3�����и�������ΪҪ��ÿ�������Ľ������3 �ı�����ֻ�в���0ʱ ��˵������3�ı������㣬�ɼ�
��������ԭ01������¾���c���õ�����Ϊ��ͷԪ��Ϊai����βԪ��Ϊaj�ĳ���Ϊ4�����и�����
���γ�k-1�μ��õ�������ⲿ�ֿ����þ�������ݽ����Ż���
���ѵõ��ľ����е�ÿ��Ԫ�ص�ֵ��������Ϊ����Ϊk���������������и�����
ʵ���Ͼ���floyd�󳤶�Ϊk�ĵ�·��
��������þ���˷������ʽ�����⣡��ܾ���*/

ll a[105];
int n;    //������ģ����
struct Matrix
{
    int row,cal;
    ll m[105][105];
};
Matrix init(Matrix a,ll t)
{
    for(int i=0;i<a.row;i++)
        for(int j=0;j<a.cal;j++)
        a.m[i][j]=t;
    return a;
}
Matrix mul(Matrix a,Matrix b)
{
    Matrix ans;
    ans.row=a.row;ans.cal=b.cal;
    ans=init(ans,0);
    for(int i=0;i<a.row;i++)
        for(int j=0;j<b.cal;j++)
            for(int k=0;k<a.cal;k++)
                ans.m[i][j]=(ans.m[i][j]+a.m[k][i]*b.m[k][j])%mod;
            return ans;
}
Matrix quick_pow(ll k,Matrix A)
{
    Matrix I;
    I.row=n;I.cal=n;
    I=init(I,0);
    for(int i=0;i<n;i++)
        I.m[i][i]=1;
    while(k){
        if(k&1)
            I=mul(I,A);
        A=mul(A,A);
        k>>=1;
    }
        return I;
}
int count(ll a)
{
    int ans=0;
    while(a)
    {
        if(a&1)
            ans++;
        a>>=1;
    }
    return ans;
}
int main()
{
    ll k;
    scanf("%d %I64d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    Matrix A;
    A.row=n;A.cal=n;
    A=init(A,0);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(count(a[i]^a[j])%3==0)
                A.m[i][j]=1;
    ll ans=0;
    A=quick_pow(k-1,A);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            (ans+=A.m[i][j])%=mod;
    printf("%I64d\n",ans);
    return 0;
}
