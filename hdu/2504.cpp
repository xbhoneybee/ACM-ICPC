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
#define inf 1000000000.000
#define ll long long
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;


//ʹ��gcd�ж��Ƿ��ʣ�����ö�٣���Ҫ����������Ҫ�ֽ�������
int gcd(int x , int y)
{
    if(x<y) swap(x,y);
    if(!y)
    return x;
    else return gcd(y , x%y);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b;
        d=a/b;
        for(int j=2;;j++)
        {
            if(gcd(j,d)==1)
            {
                c=j*b;
                break;
            }
        }
     cout<<c<<endl;
    }
}