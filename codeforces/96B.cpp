#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;

//һ���,�������ۻ�����©

int lucky[]={47,74,4477,4747,4774,7447,7474,7744,444777,447477,447747,
447774,474477,474747,474774,477447,477474,477744,744477,744747,744774,747447,
747474,747744,774447,774474,774744,777444,44447777,44474777,44477477,44477747,
44477774,44744777,44747477,44747747,44747774,44774477,44774747,44774774,44777447,
44777474,44777744,47444777,47447477,47447747,47447774,
47474477,47474747,47474774,47477447,47477474,47477744,47744477,47744747,47744774,
47747447,47747474,47747744,47774447,47774474,47774744,47777444,74444777,74447477,
74447747,74447774,74474477,74474747,74474774,74477447,74477474,74477744,74744477,
74744747,74744774,74747447,74747474,74747744,74774447,74774474,74774744,74777444,
77444477,77444747,77444774,77447447,77447474,77447744,77474447,77474474,77474744,
77477444,77744447,77744474,77744744,77747444,77774444};

int main()
{
   int n ;
   cin>>n;
   int i=0;
   if(n>77774444)
    {
        cout<<4444477777<<endl;
        return 0;
    }
    else if(77747444<n)
        {
        cout<<77774444<<endl;
        return 0;
    }
   for(;lucky[i]<n;i++)
    ;
   cout<<lucky[i]<<endl;

    return 0;
}




//��ʹ��next_permutation�㷨���
int main()
{
    int num=0;//lucky ����
    long long lucky[1000]={0};
    int startnumber[]={47,4477,444777,44447777};//�ֵ�����С�Ļ���
    char startnumch[10];
    for(int i=0;i<4;i++){
    sprintf(startnumch,"%d",startnumber[i]);// int to array
    do{
        lucky[num++]=atoi(startnumch);  //  array to int
    }while(next_permutation(startnumch,startnumch+(i+1)*2));

    }
    lucky[num++]=4444477777;//exceed int
    int n,i=0;
    cin>>n;
    while(lucky[i]<n)
    {
     i++;
    }
    cout<<lucky[i]<<endl;
    return 0;
}

//����next_permutation ���� ���http://blog.sina.com.cn/s/blog_9f7ea4390101101u.html

/******************************************************************************/
����һ����һ���������һ�����еĺ��������Ա���ȫ����,Ҫ����ͷ�ļ�<algorithm>
 ��������ǰ�ıʼ�    ��֮��ȫ�෴�ĺ�������prev_permutation
  
  
 (1) int ���͵�next_permutation
  
 int main()
 {
  int a[3];
 a[0]=1;a[1]=2;a[2]=3;
  do
 {
 cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
 } while (next_permutation(a,a+3)); //����3ָ����Ҫ�������еĳ���
  
 //�������a֮������У��ͷ���true�����a�����һ������û�к�̣�����false��ÿִ��һ�Σ�a�ͱ�����ĺ��
  
  
 }
  
 �����
  
  1 2 3
  1 3 2
  2 1 3
  2 3 1
  3 1 2
  3 2 1
  
  
 ����ĳ� while(next_permutation(a,a+2));
 �������
  1 2 3
  2 1 3
  
 ֻ��ǰ����Ԫ�ؽ����ֵ�����
 ��Ȼ������ĳ� while(next_permutation(a,a+1)); ��ֻ�����1 2 3
  
  
  
 �����б�������������û�к�̣���next_permutationִ�к󣬻�����н����ֵ���������,�൱��ѭ��
  
  int list[3]={3,2,1};
 next_permutation(list,list+3);
 cout<<list[0]<<" "<<list[1]<<" "<<list[2]<<endl;
  
 //���: 1 2 3

  
  
  
  
 (2) char ���͵�next_permutation
  
 int main()
 {
  char ch[205];
 cin >> ch;
  
 sort(ch, ch + strlen(ch) );
 //�������������������ֵ���������������9874563102 cout<<ch; �����0123456789,�����������ȫ������
  
  char *first = ch;
  char *last = ch + strlen(ch);
  
  do {
 cout<< ch << endl;
 }while(next_permutation(first, last));
  return 0;
 }
  
 //�����Ͳ�������֪��ch�Ĵ�С�ˣ��ǰ�����ch�ַ���ȫ����������
 //������ while(next_permutation(ch,ch+5)); ���ֻ����1562���ͻ����������Ϊch�е����Ԫ��ָ��δ֪
 //��Ҫ�����ַ����������򣬲���5ָ��������ĳ��ȣ�����������

  
  
  
  
  
 (3) string ���͵�next_permutation
  
 int main()
 {
  string line;
  while(cin>>line&&line!="#")
 {
  if(next_permutation(line.begin(),line.end())) //�ӵ�ǰ����λ�ÿ�ʼ
 cout<<line<<endl;
  else cout<<"Nosuccesor\n";
 }
 }
  
  
  
 int main()
 {
  string line;
  while(cin>>line&&line!="#")
 {
 sort(line.begin(),line.end());//ȫ����
 cout<<line<<endl;
  while(next_permutation(line.begin(),line.end()))
 cout<<line<<endl;
 }
 }
  
  
  
  
  
  
  next_permutation �Զ���ȽϺ���
  
  
 #include<iostream> //poj 1256 Anagram
 #include<string>
 #include<algorithm>
 using namespace std;
 int cmp(char a,char b) //'A'<'a'<'B'<'b'<...<'Z'<'z'.
 {
  if(tolower(a)!=tolower(b))
  return tolower(a)<tolower(b);
  else
  return a<b;
 }
 int main()
 {
  char ch[20];
  int n;
 cin>>n;
  while(n--)
 {
 scanf("%s",ch);
 sort(ch,ch+strlen(ch),cmp);
  do
 {
 printf("%s\n",ch);
 }while(next_permutation(ch,ch+strlen(ch),cmp));
 }
  return 0;
 }	
