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

//����ģ��
/*������֮����n�ı��������Ƕ�n������0��ͨ����һ������Щ�������ϣ��õ��ĺʹ����һ�������
�������ܶ�������Ͳ��ð��ˡ���������ֻҪ�ҳ�һ�鼴�ɣ��������Ǿ���Ҫ�ҵ�һ�顣���Խ���������ģ�ͣ�
Ϊʲô�����ó���ģ�ͣ���n��������Щ���������ͷֱ��nȡ��õ���������Χ��0~n-1, ����ͬ����������������n��
������Ϊnʱ�� �����п϶���һ�����ĺ�������������С��n,�⵱����������������������ͬ���ٸ�
���ӣ�1��3��5��9��2  ��5������ �Ұ�����������ӱ�ɣ� 1��4�� 9�� 18�� 20�� ��Ȼ��5������ 
ʹ����һһ��5ȡ�࣬�õ� 1�� 4�� 4�� 3�� 0�� �Ұ������������룬����Ϊ���壬 ������5�����壬4�����룬
��һ������1,3���ڶ�������1,3,5�� �ú��߼�ǰ�߱��Ǵ�*/

int a[10005];
ll pre[10005];
int main()
{
    int n;
    scanf("%d",&n);
    map<ll ,int> ma;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
         pre[i]%=n;
         if(pre[i]==0){
            printf("%d\n",i);
            for(int j=1;j<=i;j++)
            {
               printf("%d\n",a[j]); 
            }
            break;
         }
        if(ma.count(pre[i])==0)
            ma[pre[i]]=i;
        else{
                printf("%d\n",i-ma[pre[i]]);
            for(int j=ma[pre[i]]+1;j<=i;j++)
                printf("%d\n",a[j]);
            break;
        }
    }
    return 0;
}