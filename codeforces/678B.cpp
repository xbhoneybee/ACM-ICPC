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

int leap[1000005];
int main()
{
    for(int i=1000;i<=1000000;i+=4)
    {
        if(i%100==0){
            if(i%400==0)
                leap[i]=1;
        }
        else leap[i]=1;
    }
    int y;
    cin>>y;
    int x=1,y1;
    for(int i=y;;i++)
    {
        if(leap[i]) x+=366;
        else x+=365;
        x%=7;
        if(x==1&&leap[i+1]==leap[y])//wa��û�����ж��Ƿ�ͬ�����꣬��֪��Ϊʲô�����Ͷԣ���
        {
            y1=i+1;
            break;
        }
    }
    cout<<y1<<endl;
    return 0;
}