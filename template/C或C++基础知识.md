# C语言
### char
全局变量char a[100];

(int)a[0]=0;

局部变量随机
#### 输入输出
gets(char *) 读一行

int a;

scanf("%x",a);
以16进制读入。

char s[10];

int tem;

scanf("%s",s);

sscanf(s,"%x",&tem);

在字符串s中读入int tem

输出% printf("%%");
#### math
const double e = 2.71828；

const double PI=acos（-1.0）；

log 函数默认以e为底

exp（x） 函数表示e的x次幂
#### 文件读写
重新定向：在main函数入口加入
```
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
```
#### 输入输出
printf("%*s", len, str) 这时 printf 额外接受一个参数作为域宽。如果 str 的长度小于 len ，会用空格在左边使长度补足。
#### cstdlib
rand()返回0到32767之间的一个整数

srand(time(NULL));在程序开始执行一次以当前时间初始化随机种子，确保每次程序运行使用的是不同套的随机数。 

#### 进制 
0x3f3f3f3f = ‭1061109567

0x7f7f7f7f = ‭2139062143‬
# c++
#### 输入输出
getline(cin,str);在使用时前面如果刚输入数字并回车会吃掉回车产生错误，此时要多用一次getline
##### stingstream
```
string line,word;
while(getline(cin,line))
{
   stringstream stream(line);
   while(stream>>word)
   {
       //实现了每次读一行，从每行中读一个单词
   }
}
int x;
while(stream>>x) arr[n++]=x;
```
#### goto
```
label :
{}
goto label;
```
## C++  STL
### 库函数
#### sort
sort 自定义比较函数规则

return true ; 排序为a,b;

return false；排序为b,a;

sort处理vector
```
sort(v.begin(), v.end(),less<int>());//升
sort(v.begin(), v.end(),greater<int>());//降
```
lower_bound(begin,end,val)

返回大于或等于val的第一个位置,一般要-begin才是其在数组中的下标值

注意对于vector等下标访问的数组结构lower_bound的时间复杂度为log N 

对于set，map 等树形数据结构则为O N，必须调用set 内部的lower_bound 才是log N 复杂度
upper >val
### string
string.substr(start,length);

string gap(60,'-'); //直接生成字符串

reverse(str.begin(), str.end()); 翻转 

string /int
```
string getstring ( const int n )
{
    std::stringstream newstr;
    newstr<<n;
    return newstr.str();
}
int getint ( string s )
{
    return atoi(s.c_str());
}
```
string toupper/tolower
```
void Toupper(string& str)
{
    transform(str.begin(),str.end(),str.begin(),::toupper);
}
void Tolower(string& str)
{
    transform(str.begin(),str.end(),str.begin(),::tolower);
}
```
### vector
```
vec.assign(size,value) //对vector vec 的size 个赋值为value
vector   vec（size ， value）初始化创建一个vector 确定大小和value
vector <int >vec (10) 确定vector的capacity 为10 
vector <int > vec[10] 建立了一个向量数组  vector[i]表示 一个向量
vector<int > vec2(vec1) 复制
vec.insert(vec.begin()+2,5) 向迭代器 指向元素前插入新元素 5
vec.front ()  第0个成员 vec.back()最后一个成员;
vec.at(4)  下标为4成员
vec.pop_back()删除尾元素
vec.erase（it） 删除迭代器所指向元素
vec.erase（first,last）删除迭代器所指定序列【  first ，last）
```
##### 复杂度 
由数组构成的vector，其inser/erase/find 都是O（N）
### pair
pair<int,int>p;//默认构造函数赋值0,0


### priority_queue
优先队列与队列的差别在于优先队列不是按照入队的顺序出队，而是按照队列中元素的优先权顺序出队（默认为大者优先，出队函数是pop(),有点像栈，队尾（栈顶）先出。

也可以通过指定算子来指定自己的优先顺序。priority_queue 模板类有三个模板参数，第一个是元素类型，第二个容器类型，第三个是比较算子。其中后两个都可以省略
默认容器为vector，默认算子为less，即小的往前排，大的往后排（出队时序列尾的元素出队）。

priority_queue<int> q1;

priority_queue< pair<int, int> > q2; 

priority_queue<int, vector<int>, greater<int> > q3; // 定义小的先出队

如果要定义自己的比较算子，方法有多种，这里介绍其中的一种：重载比较运算符。优先队列试图将两个元素x 和y 代入比较运算符(对less 算子，调用x<y，对greater 算子，调用x>y)，若结果为真，则x 排在y 前面，y 将先于x 出队，反之，则将y 排在x 前面，x 将先出队。
看下面这个简单的示例：
```
class T{
public:
int x, y, z;
T(int a, int b, int c):x(a), y(b), z(c){}
};
friend bool operator < (const T &t1, const T &t2){
return t1.z < t2.z; // 按照z 的顺序来决定t1 和t2 的顺序
}
```
###### 复杂度
实现 堆 

push pop 都是 O（logN）；

### map
 map<string,string>::iterator it;
 
 在遍历时，*it是一个pair，it->first 是key it->second 是value
 
 map.erase(iterator);erase 之后iterator 自动指向下一个位置；而且可以使用iterator = map.find（key）确定位置
 ```
std::map<std::string, std::string > mapTest; 
bool TestVal(const std::string & val);
std::map<std::string,std::string>::iterator it = mapTest.begin();
while(it!=mapTest.end())
{
        if(TestVal(it->second))
        {
                mapTest.erase(it++);
        }
            else
                it++;
}
```
该方法中利用了后++ 的特点，这个时候执行mapTest.erase(it++);这条语句分为三个过程 

1. 先把it的值赋值给一个临时变量做为传递给erase的参数变量
2. 因为参数处理优先于函数调用，所以接下来执行了it++操作，也就是it现在已经指向了下一个地址。
3. 再调用erase函数，释放掉第一步中保存的要删除的it的值的临时变量所指的位置。
 ### hash_map
insert ()  erase()  [] ： O(1)
 ### deque
 deque(int nSize,const T&t):创建一个deque,元素个数为nSize,且值均为t

que.pop_front();弹出队首元素 不返回值

 ### list 
 不支持[]
 #####  复杂度 
 insert   erase  O(1)
 
 sort O (nlgn)(lg n) 
 
 ### multiset
 用法同set，但是允许多个重复元素
 multiset<int,greater<int>> st;
 从大到小排。
 注意multiset 的erase(0)会将set内的所有0
删去，只删一个用erase(set.find(0))

### bitset
复杂度O N/64

#include <bitset>

初始化

bitset<32> bitvec; //32位，全为0。 <> 内填入一个常量

0-31 低位到高位

bitset<n> b;

b有n位，每位都为0

bitset<n> b(u);

b是unsigned long型u的一个副本

bitset<n> b(s);

b是string对象s中含有的位串的副本

bitset<n> b(s, pos, n);

b是s中从位置pos开始的n个位的副本

b.any()

b中是否存在置为1的二进制位？

b.none()

b中不存在置为1的二进制位吗？

b.count()

b中置为1的二进制位的个数

b.size()

b中二进制位的个数

b[pos]

访问b中在pos处的二进制位

b.test(pos)

b中在pos处的二进制位是否为1？

b.set()

把b中所有二进制位都置为1

b.set(pos)

把b中在pos处的二进制位置为1

b.reset()

把b中所有二进制位都置为0

b.reset(pos)

把b中在pos处的二进制位置为0

b.flip()

把b中所有二进制位逐位取反

b.flip(pos)

把b中在pos处的二进制位取反

b.to_ulong()

用b中同样的二进制位返回一个unsigned long值

os << b

把b中的位集输出到os流

bitset 还可以进行位运算 & | ^