# 类

类的基本思想是data abstraction和encapsulation.
> data abstraction是依赖于interface和implementation分离的编程技术
> encapsulation实现了interface和implementation的分离.

## 封装

访问说明符(access spedifiers)

> 使用class和struct的唯一区别是默认的访问权限.

## 函数

定义在类内部的函数是隐式的inline函数.

## this

成员函数通过this指针来访问调用它的对象.当我们调用成员函数时,用请求该函数的对象地址初始化this.

this总是指向某个对象,所以是常量指针,不允许修改this中的地址.

## const对象

常量对象,以及其引用或指针只能调用常量函数.

## 构造函数

构造函数不能声明为const的.当我们创建一个const对象时,直到构造函数完成初始化,对象才获得"常量"属性.

1 default constructor -> synthesized default constructor(编译器合成)
> see main.cpp for more information

2 constructor initialize list(构造函数初始值列表)
> 当某个数据成员被列表忽略时,将以合成的默认构造函数方式隐式初始化(类内初始值或默认初始化)







