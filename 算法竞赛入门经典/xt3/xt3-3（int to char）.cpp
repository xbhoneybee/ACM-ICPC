�ַ���ת�������֣���atoi��atol��atof���ֱ��Ӧ�������ͣ�long�ͣ�double�͡�
itoa

������ ��:��һ����ת��Ϊ�ַ���
 ������ ��:char *itoa(int value, char *string, int radix);
 ������ϸ����:itoa��Ӣ��integer to array(��int������ת��Ϊһ���ַ���,����ֵ����������string��)����д.
 ����������
 ����value: ��ת����������
 ����radix: �ǻ�������˼,���Ƚ�valueת��Ϊradix���Ƶ�������Χ����2-36������10��ʾ10���ƣ�16��ʾ16���ơ�
 ����* string: ����ת����õ����ַ�����
 ��������ֵ��
 ����char * : ָ�����ɵ��ַ����� ͬ*string��

������ע:�ú�����ͷ�ļ���"stdlib.h"
�ο�http://blog.sina.com.cn/s/blog_4ba5b45e0102durh.html

uva1225

wa
#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    int ans[10]={0};
    char s[1000005];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char sn[105];
        sprintf(sn,"%d",i);//������������ַ������ڴ��ַ���,��'\0'
                       //Ҳ����win��ʹ��itoa������<stdlib.h>�����ǷǱ�׼c���� 
        strcat(s,sn);  //strcpy��ֵ��strcmp�Ƚϣ�strcat����
    }
    int m=strlen(s);   //strlen���ַ������ڷǿ�Ԫ�ظ�������'\0'�����ã���'\0'���������ڡ�
    for(int j=0;j<m;j++)
    {
        switch(s[j]){
        case '0': ans[0]++;break;
        case '1': ans[1]++;break;
        case '2': ans[2]++;break;
        case '3': ans[3]++;break;
        case '4': ans[4]++;break;
        case '5': ans[5]++;break;
        case '6': ans[6]++;break;
        case '7': ans[7]++;break;
        case '8': ans[8]++;break;
        case '9': ans[9]++;break;
        }
    }
    for(int k=0;k<10;k++)
        {
            printf("%d",ans[k]);
            if(k<9) printf(" ");
        }
    printf("\n");
    memset(ans,0,sizeof(ans));
    memset(s,0,sizeof(s));
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
//һֱwa�㣺δ�ҵ���



�޸ĺ�
ac
#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
    int ans[10]={0};
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int j=i;
       while(j>0)          //������λ������ֱ�Ӽ���ÿ�����ֵĸ���
       {
           ans[j%10]++;
           j/=10;
       }
    }
    for(int k=0;k<10;k++)
        {
            printf("%d",ans[k]);
            if(k<9) printf(" ");
        }
    printf("\n");
    memset(ans,0,sizeof(ans));
    }
    //printf("Time used = %.8f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}