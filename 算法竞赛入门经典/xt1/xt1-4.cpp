#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  printf("%f %f\n",sin(n/180.0*acos(-1.0)),cos(n/180.0*acos(-1.0)));
    return 0;
}

//ע��sin cos ���㺯�������Ի����ƣ�����Ҫ��n�����ơ�
//ע��n/180.0 ����180 .����ת����