## parameter

### 数组形参

不允许拷贝数组,所以不能返回数组,只能返回数组的指针.
使用数组时(通常)将数组转换成指针.

* 提供数组长度的三种方式:
	1 数组中使用特殊标记
	2 使用标准库规范begin,end
	3 显示传递数组大小

当形参使用数组的引用时,数组的维度是类型的一部分.
> void print(int (&arr)[10])
>	for(auto elem : arr)
>		cout<<elem;

#### 含有可变形参的函数

1 如果所有实参的类型相同且数量未知,可以传递名为initializer_list的标准库类型
> see main.cpp for more information :)

2  

### 返回复杂类型的函数

1 使用别名
2 尾置返回类型(trailing return type)
3 decltype
> see main.cpp for more information

### 重载与const

当存在底层const和非const决定的重载函数时
> 使用底层const对象调用,则只能匹配到特定版本.因为底层const不能转换为非const
> 使用非底层const对象调用,原则上都可以转换,但是编译器优先调用非const版本. 


