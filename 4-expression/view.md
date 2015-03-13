## expression

* 对象被当做左值使用时,用的是内存中的位置;对象被当做右值只用时,用的是内容.

* 使用关键字decltype时:
> 表达式求值结果为左值,decltype作用于该表达式得到引用类型: decltype(*p)
> 右值,非引用

### && ||

* short-cicut evaluation

### 关系运算符

* 左结合

### 赋值运算符

* 右结合

### sizeof

* 面对数组和指针的差异.

### 逗号表达式

* 从左往右依次计算.

## 类型转换

* 无符号 & 有符号类型不一致时
> 无符号类型不小于有符号类型,转换为无符号类型.(unsigned int 和 int -> unsigned int)
> 无符号类型小于有符号类型,转换结果依赖于机器.(unsigned int 和 long long -> long long)

* 显示类型转换

static_cast<type-id>(expression)

没有运行时检查来保证转换的安全性

1. 基类指针转换为派生类指针

2. built-in type之间的转换
> 告诉编译器我们不在意精度损失,关闭警告

3. 找回void指针或设置为void指针
> double * p = static_cast<double *>(void *)

dynamic_cast<type-id>(expression)

要求:type-id必须是指针,引用或者void*

1. 进行基类指针与派生类指针之间的转换(不同层)
> 进行类型检查,比static_cast更安全
> 需要有虚函数(由于运行时检查需要运行时类型信息,这个信息存储在虚函数表中)

2. 同层之间的转换
> static_cast不允许
> dynamic_cast结果为0

reinpreter_cast<type-id>(expression)

type-id必须是一个指针,引用,算数类型,函数指针或者成员指针.它可以在指针和整数之间转换,

const_cast<type-id>(expression)
去除const和volatile属性.type-id要为指针，引用．
可以去除底层const
```c++
int j = 10;
const int * ptr = &j;
(*(const_cast<int*>(i))) = 0;
cout<<j<<endl; // 0
```

