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

//N ��set�洢���еĵ��ʣ�����ÿ�����ʣ��������п����ӵ�����ϣ�
//Ȼ���ж���set���Ƿ��Ѿ��洢������������õ��ʡ�
//�㷨���Ӷ�ΪO(n*lgn*|S|)������|S|��ʾ������󳤶ȡ�

int main()
{
    ios::sync_with_stdio(false);
    set<string> sets,setans;
    string s;
    while (!cin.eof())
    {
        cin>>s;
            sets.insert(s);
    }
    set<string>::iterator ip;
    for(ip=sets.begin();ip!=sets.end();ip++)
    {
        s=*ip;
        int len=s.size();
        for(int i=1;i<len;i++)
        {
            string s1=s.substr(0,i);
            string s2=s.substr(i,len-i);
            if(sets.count(s1)==1&&sets.count(s2)==1)
                {
                    setans.insert(s);
                }
        }
    }
    for(ip=setans.begin();ip!=setans.end();ip++)
        cout<<*ip<<endl;
    return 0;
}
