### 离散化
有些数据本身很大，自身无法作为数组的下标保存对应的属性。如果这时只是需要这堆数据的相对属性，那么可以对其进行离散化处理！

离散化：当数据只与它们之间的相对大小有关，而与具体是多少无关时，可以进行离散化。

eg 9 1 0 5 4 与 5 2 1 4 3 的逆序对个数相同。

设有4个数：1234567、123456789、12345678、123456
排序：123456<1234567<12345678<123456789

 =>   1   <     2    <     3     <   4

那么这4个数可以表示成：2、4、3、1

使用STL算法离散化：

思路：先排序，再删除重复元素，然后就是索引元素离散化后对应的值。
假定待离散化的序列为a[n]，b[n]是序列a[n]的一个副本，则对应以上三步为：
```
b[i]=a[i]
sort(a,a+n);
int size=unique(a,a+n)-a; //size为离散化后元素个数
for(i=0;i<n;i++)	
b[i]=lower_bound(a,a+size,b[i])-a + 1;//b[i]为经离散化后对应的值
```
映射回来就是原来未unique的a'[i]=离散化后a[b[i]-1] b[i]缩小了原本的值，变成序列号，由a[]调用序列号得到原值

对于第3步，若离散化后序列为0, 1, 2, ..., size - 1则用lower_bound，序列为1, 2, 3, ..., size则用upper_bound，其中lower_bound返回第1个不小于b[i]的值的指针，
而upper_bound返回第1个大于b[i]的值的指针，当然在这个题中也可以用lower_bound然后再加1得到与upper_bound相同结果
两者都是针对以排好序列。使用STL离散化大大减少了代码量且结构相当清晰。
---
### 二分查找
```
int binary_search(int *data, int size, int value)  
{  
    int mid;  
    int left = 0;  
    int right = size - 1;  
    while(left < right)  
    {  
        // 确保中点靠近区间的起点  
        mid = left + (right-left)/2;  
        // 如果找到则返回  
        if(data[mid] == value) return mid;  
        // 将中点赋给终点  
        else if(data[mid] > value) right = mid;  
        // 将中点加一赋给起点  
        else left = mid + 1;  
    }  
    return -1;  
}  
```
上述代码存在一个问题，就是当序列中存在多个value的时候，bsearch会返回最中间的那一个元素，有时候这不是我们想要的结果，换句话说这样就无法确定值等于value的完整区间，所以还需要对上面的代码进行改进，使得其可以查找出value出现的第一个位置和最后一个位置，其实就是对等于情况的讨论，下面的代码实现了这个功能：
```
/* 
该函数当value存在时返回它出现的第一个位置， 
如果value不存在则返回位置i,满足在该位置插入value后该序列仍然有序 
*/  
int lower_bound(int *data, int size, int value)  
{  
    int mid;  
    int left = 0;  
    int right = size - 1;  
    while(left < right)  
    {  
        // 确保中点靠近区间的起点  
        mid = left + (right-left)/2;  
        // 将中点赋给终点，包含等于情况  
        if(data[mid] >= value) right = mid;  
        // 将中点加一赋给起点  
        else left = mid + 1;  
    }  
    return left;  
}  
  
/* 
该函数当value存在时返回它出现的最后一个位置的后面一个位置，因为起点会移动到中点加一 
如果value不存在则返回位置i,满足在该位置插入value后该序列仍然有序 
*/  
int upper_bound(int *data, int size, int value)  
{  
    int mid;  
    int left = 0;  
    int right = size - 1;  
    while(left < right)  
    {  
        // 确保中点靠近区间的起点  
        mid = left + (right-left)/2;  
        // 将中点赋给终点  
        if(data[mid] > value) right = mid;  
        // 将中点加一赋给起点，包含等于情况  
        else left = mid + 1;  
    }  
    return left;  
}  
```
### 暴力
暴力出奇迹！

对于棋盘横竖对角线的暴力直接
for(i,j)每个点遍历一遍，判断满足条件

i+size<n|j+size<n|i+size&&j+size<n|i+size&&j-size<n

### 枚举
```
do{
    
}while(next_permutation(a,a+n));
```
或者状压 for

### 尺取法
```
    int l = 0,r= 0,sum = 0,ans=n+1;
        while(1){
            while(r < n && sum<s){
                sum+=a[r];
                r++;
            }
            if(sum < s){
                break;  
            }
            ans=min(r-l,ans);
            sum -= a[l++];
        }
```