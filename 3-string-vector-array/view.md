## namespace 
[About how to using namespace](https://github.com/ThreeCobblers/Paladin/blob/master/blog/C%2B%2B/sosohu/chap3.md)

## string

* getline()得到的string对象不包括换行符

* size()返回值类型为string::size_t,是无符号数且足够存储下任一string对象的大小.
> 可借助auto / decltype推断
> 如果在表达式中使用了size(),就应避免使用有符号数带来的混乱
> **下标**使用string:size_t类型

* string中字符特性[详见primer 82]

* string.c_str()获取c风格

## vector

* 使用圆括号初始化: vector<int> v(10,1); 表示construct. 如果省略初始值:v(10),则为值初始化(value-initialized),初始值由对象类型决定.

* 使用花括号初始化: vector<int> v{10}; 表示列表初始化(list initialize).

* **下标**使用size_t类型

* vector<int> v(begin(array), end(array)); 使用数组初始化vector

## iterator

* begin, cbegin , rbegin, rcbegin

* 只要两个迭代器指向同一个容器,就能将它们相减,结果是迭代器之间的距离(类型为difference_type的带符号整数型).

## array

* 要理解数组的定义,从内而外阅读.

* **下标**使用size_t类型(stddef.h)

* C++11中引入begin(array)和end(array)来获取数组的特定指针

## range for

* for( auto c : s)

* for( auto &c : s)
	
* 处理多维数组
> int arr[row][col];
> for( auto &row : arr){
>	for( auto &c : row){
>	}
> }
