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
//K<nʱ�������е��Ժ���֪����������

char pan[10][10];
int n,k,c;
int vistor[10];//�б��
void dfs(int cur,int num)
{
    if(num==k)
        {
            c++;
            return ;
        }

    if(cur>n) return;
    //�������DFS(row+1,num); ���ʹ��,��������Խ��
    for(int i=0;i<n;i++)
    {
        if(pan[cur][i]=='#'&&vistor[i]==0)
            {
                vistor[i]=1;//�������ӵ��б��
                dfs(cur+1,num+1);
                vistor[i]=0;//���ݺ�˵���ں����ӵ�״̬�Ѽ�¼����ǰ���б�ǻ�ԭ
            }
    }
    dfs(cur+1,num);
    //�������ѵ㣬��k<nʱ��row�ڵ���n֮ǰ�Ϳ����Ѿ���ȫ�����ӷź�
    //�����ڵ�ȫ�����Ӷ��źú��ĳ������״̬�Ѿ���ǰ��ѭ��ʱ��¼��
    //���Ϊ�˴�������У��ǰλ���Ȳ������ӣ���������һ�з����ӵ����
}
int main()
{
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)
            return 0;
            getchar();
        memset(vistor,0,sizeof(vistor));
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                cin>>pan[i][j];
                getchar();
            }
        dfs(0,0);
        cout<<c<<endl;
        c=0;
    }
    return 0;
}