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
#define inf 1000000000
#define ll long long
#define mod 1000000007//  ���ﲻҪд��100000000+7 define���滻������
using namespace std;
#define iosfalse ios::sync_with_stdio(false);

int main()
{
    int a,b;
    cin>>a>>b;
    double x;
    int add=a+b;
    int de=a-b;
    if(de==0) {
        cout<<a<<endl;
        return 0;
    }
    if(de<0){
        cout<<-1<<endl;
        return 0;
    }
    x=min( de/(2.*(de/(2*b))),add/(2.*(add/(2*b)) ));
    //�������� ǡ������k��� x��С x>=b
    printf("%.14f\n",x);

    return 0;
}