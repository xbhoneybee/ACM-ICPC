#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>

using namespace std;
// ���ﲻҪֱ�ӽ���a,b if a<b swap(a,b) then x,y need swap

int main() {
    int a, b, n, mx = 0, x = 0, y = 0;
    cin>>a>>b>>n;
    if(a > b) {
        int top = min(n/a, b);
        for(int i = 0;i <= top; i++) {
            int cur = (n-a*i)/b*b + a*i;
            if(cur > mx) {
                mx = cur;x = i; y = (n-a*i)/b;
            }
        }
    }
    else {
        int top = min(n/b, a);
        for(int i = 0;i <= top; i++) {
            int cur = (n-b*i)/a*a + b*i;
            if(cur > mx) {
                mx = cur;x = (n-b*i)/a; y = i;
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}


��⣺����a > b��ֻ��Ҫ����ö��x�жϼ��ɣ�����topΪmin(n/a, b)�����Ӷ���O(sqrt(n))�ġ�

֤���ܼ򵥣����x > b�����д�� a(x + b) + by = ax + ab + by = ax + b(a+y)��
�����x < b������������϶���ö�ٵ��˵ģ�����������Ϊmin(n/a, b)��

