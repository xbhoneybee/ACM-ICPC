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
#include <sstream>
#define inf 10000000000
#define ll long long
#define LL long long
#define iosfalse ios::sync_with_stdio(false);
using namespace std;

//ʹ��trie���ṹ����trie���ڵ��м���������isword��cnt��
//isword�ֱ��ʾ�Ӹ��ڵ㵽�ýڵ��Ƿ���һ�����ʣ�cnt��ʾ�ж��ٸ����ʾ�������ڵ㡣
//�Ƚ����е��ʱ�����trie���У�Ȼ��һ��һ���ز��ң�������ĳ���ڵ�ʹ��cnt==1 ���� isword==true��
//��ô�Ӹ����ýڵ���ɵ��ַ������Ǹõ��ʵ����ǰ׺��
struct Node {
int cnt;//cnt��ʾ�ж��ٸ����ʾ�������ڵ㡣
int next[26];  //����
bool isword;   //�����˽ڵ��Ƿ񹹳ɵ���
Node() //c++Ĭ�Ϲ��캯��
{
    cnt=0;
    isword=false;
    memset(next,-1,sizeof next);
}
};
Node T[30005];
char words[1005][25];
int len=1;//T�����±�
char pre[30];
int idx=0;
void insert(char *tar)
{
    Node *p=&T[0];
    int mid;
    while(*tar)
    {
        p->cnt++;
        mid=*tar-'a';
        if(p->next[mid]==-1)
        {
            p->next[mid]=len;//�ҵ���һλ �����±�
            len++;
        }
        p=&T[p->next[mid]];//��������
        tar++;
    }
    p->cnt++;
    p->isword=true;
}
void search(char *tar)
{
    Node *p=&T[0];
    int id;
    idx=0;
    while(p->cnt>1&& *tar)
    {
        pre[idx++]=*tar;
        id=*tar-'a';
        p=&T[p->next[id]];
        tar++;
    }
    pre[idx]='\0';
}
int main()
{
    int i,j;
    i=0;len=1;
    while(~scanf("%s",&words[i]))
    {
        char temp[25];
        strcpy(temp,words[i]);
        insert(temp);
        i++;
    }
    for(j=0;j<i;++j)
    {
        char t[25];
        strcpy(t,words[j]);
        search(t);
        printf("%s %s\n",words[j],pre);
    }
    return 0;
}