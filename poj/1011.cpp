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

// DFS+��֦

int cmp(int x,int y)
{
    return x>y;
}
int len[100];
bool used[100];
int n,lenth;
int dfs(int i,int l,int t)
//iΪ��ǰ��ȡ�Ĺ������,lΪҪƴ��һ�������Ĺ��ӻ���Ҫ�ĳ���,t��ֵΪ���й����ܳ���
{
    if(l==0)
    {
        t-=lenth;
    if(t==0) return 1;
    for( i=0;used[i];i++);
    //��֦1��������һ������ӵ�ʱ���ҵ���һ����û��ʹ�õ�С���ӿ�ʼ
    used[i]=1;
    if(dfs(i+1,lenth-len[i],t))
        return 1;
    used[i]=0;//�Ҳ���,ǰһ��ƥ��ʧ�ܣ������ϴ�ֵ
    t+=lenth;
    }
    else{
        for(int j=i;j<n;j++)
        {
             if(j>0&&(len[j]==len[j-1]&&!used[j-1]))
            //��֦2��ǰ�������������ʱ�����ǰ���Ǹ�û��ʹ�ã�Ҳ������ǰ���Ǹ�
            //��ʼ����������ȷ�������ô�ٴ������ʼҲ�϶�����������ȷ������˼�֦�����ϴ�
                continue;
          if(!used[j]&&l>=len[j])
            //��֦3����򵥵ļ�֦��Ҫƴ��һ������ӻ���Ҫ�ĳ���L>=��ǰС���ӳ��ȣ�����ѡ��
          {
              l-=len[j];
              used[j]=1;
              if(dfs(j,l,t))
                return 1;
              l+=len[j];//û�ҵ������ϲ�
              used[j]=0;
              if(len[j]==l)
            //��֦4�������޴�ļ�֦������Ҫ���е��˴�˵�����µ�����ʧ�ܣ�
            //�����ε�С�����ȸպ�����ʣ�³��ȣ����Ǻ��������ʧ�ܣ���Ӧ�÷�����һ��
                break;
          }
        }
    }
    return 0;
}
//�����������Ӵ�С������ô������Ϊһ֧����Ϊ K
//������ľ�����ܱȼ�֧�̵�Сľ��ƴ�ɵ�Ҫ�á�
//����һЩ��
//�����Ҫƴ 2 ֧��Ϊ8��ľ������һ֧ľ����ƴ��
// 5 + 3
//Ȼ��ƴ�ڶ�֧ľ������ʧ���ˣ��������л��г�Ϊ 2 �� 1
//��ľ�����ҿ����� 5 + 2 + 1 ƴ�õ�һ֧���ٳ���ƴ�ڶ�
//֧����ϸ��һ�룬�ͻᷢ��������û���壬ע��Ҫʧ�ܵġ�
//����Ӧ������ 2+1 ��Ϊ 2+1 �� 3 ����
int main()
{
    while(cin>>n&&n){
    int suml=0;
    for(int i=0;i<n;i++)
    {
          cin>>len[i];
          suml+=len[i];
          used[i]=0;
    }
    sort(len,len+n,cmp);
    int flag=0;
    for(lenth=len[0];lenth<=suml/2;lenth++)
    //��֦6���������һ��������С������֮�͵�����������С����Ӧ�ò�С��С������ĳ���
    {
        if(suml%lenth==0){
            if(dfs(0,lenth,suml))
            {
            flag=1;
            cout<<lenth<<endl;
            break;
            }
        }
    }
    if(!flag)
        cout<<suml<<endl;
    }
    return 0;
}
