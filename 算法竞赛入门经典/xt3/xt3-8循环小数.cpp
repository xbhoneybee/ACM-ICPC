#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int r[3003],u[3003],s[3003];
//r recycle u used s sequence
int main()
{
	int n,m,t;
	while (cin >> n >> m) {
		t = n;
		memset(r, 0, sizeof(r));
		memset(u, 0, sizeof(u));
		int count = 0;
		r[count ++] = n/m;   //r[0] ��������;
		n = n%m;             //nΪ�������֣�    
		while (!u[n] && n) { //ѭ������������δ���ֹ�����������Ϊ��
			u[n] = count;    //u�洢�����Ƿ���ֹ������ֵĴ���
			s[count] = n;    //s�洢��count��������ʲô
			r[count ++] = 10*n/m; //r�洢С�����ֽ����ÿһ��intΪһ�γ�������
			n = 10*n%m;     //n��Ϊ�µ�����
		}
		printf("%d/%d = %d",t,m,r[0]);
		printf(".");
		for (int i = 1 ; i < count && i <= 50 ; ++ i) {
			if (n && s[i] == n) printf("(");
			//ͨ������Ѱ��ѭ�������
			//n==0��ʾ����
			printf("%d",r[i]);
		}
		if (!n) printf("(0"); //������,��ѭ����Ϊ0
		if (count > 50) printf("...");//ֻ��ӡǰ50λ
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n",!n?1:count-u[n]);
		//count-u[n] u[n]Ϊ��������n���ֵĵ�һ��sequence
	}
	return 0;
}
//uva202 ���� С��ѭ����
//����ģ�����㣬����������ͬʱѭ��������
//copy