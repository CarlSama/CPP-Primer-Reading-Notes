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


|类型|说明|示例|
|:---------:|:--------------------------------------------------------:|:--------------------------------------------:|
|static_cast|任何具有明确定义的类型转换,只要不包含底层const,都可以使用|float f = static_cast<float>(double);//关闭警告|
||告诉编译器我们不在意精度损失| double * p = static_cast<double *>(void *)//找回void*|
|const_cast| 只能改变**底层const**?,不安全||
|| 不能通过它来修改指针的类型||							 
|reinterpret_cast|在位模式重新解释||
|dynamic_cast||| 
