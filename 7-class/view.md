# 类

类的基本思想是data abstraction和encapsulation.
> data abstraction是依赖于interface和implementation分离的编程技术
> encapsulation实现了interface和implementation的分离.

## 封装

访问说明符(access spedifiers)

> 使用class和struct的唯一区别是默认的访问权限.
> 一个类就是一个作用域:类外定义成员函数需要提供作用域.
> 函数的返回类型位于函数名之前,需要时加上作用域指示符. 

## 函数

定义在类内部的函数是隐式的inline函数.

## 类的声明

类在声明之后,定义之前是一个不完全类型(incomplete type):可以定义其引用或指针,可以声明(非定义)以不完全类型为参数或返回值类型的函数.
> 因此,一旦类名出现后,就允许包含指向自身的引用或指针
								
## this

成员函数通过this指针来访问调用它的对象.当我们调用成员函数时,用请求该函数的对象地址初始化this.

### const + this
默认情况下,this的类型是指向**非常量版本类类型**的**常量指针**.

在const成员函数中,this是**指向常量的常量指针**,所以此时无法通过this指针来修改类成员,因此我们就不能调用普通成员函数.

## 类作用域和成员函数

编译器分两步来处理类:首先编译成员的声明,(此时类成员可见)然后是定义在类内部的成员函数体
> 用来定义类型的成员必须先定义后使用,与普通成员不同.
> inline函数和constexpr函数通常定义在头文件.

### 类型名的特殊处理

在类中,如果成员使用了外层作用域中的某个名字,该名字代表某种类型,则类之后不能重定义这种类型.
> 类型名的定义通常出现在类的开始处.


## 构造函数

构造函数不能声明为const的.当我们创建一个const对象时,直到构造函数完成初始化,对象才获得"常量"属性.

1 default constructor(无参) 

2 synthesized default constructor(编译器合成)
> 如果存在**类内初始值**,用它初始化
> 否则,默认初始化(与类型及位置有关)该成员,如果定义在块中的内置类型或复合类型对象被默认初始化,值未定义.

3 constructor initialize list(构造函数初始值列表)
> 当某个数据成员被列表忽略时,将以合成的默认构造函数方式隐式初始化(类内初始值或默认初始化)
> 对于const,引用或为提供默认构造函数的类类型,必须对其初始化而非赋值

4 delegating constructor

### 隐式类类型转换

如果构造函数只接受一个实参,则它实际上定义了转换为此类的隐式转换机制.这种构造函数也称为转换构造函数(converting constructor).
> 只允许一步转换
> 可以添加explicit来抑制隐式转换,只能直接初始化

构造函数执行过程:

1. 初始值列表
2. 默认初始化
3. 函数体

## 友元

友元关系不具有传递性.

友元声明的作用是**影响访问权限**,本身并不是普通意义上的声明,类内其他函数要使用友元函数只能等到其正式声明.

## 聚合类(aggregate class)

## 静态成员

### 变量

不属于任一对象,所以不在构造函数中初始化.
> 类内部初始化静态成员: **static constexpr** int count = 0;(通常也应该在外部定义一下)
> 类外部声明和定义

静态成员可以是不完全类型.
> In class Bar
> static Bar mem; OK
> Bar* mem; OK
> Bar mem; NO

可以用静态成员做默认实参
> void clear(char = bkground);

### 函数

静态成员函数无this指针,因此:
> 不能声明为const.
> 不能在其中使用this指针.

## 访问控制

类内:
	protected -> 子类\类内函数\frined类访问

继承:
	private属性不能被继承
	private继承 -> protected和public在子类中变为private
	public继承  -> protected和public在子类中保持
	protected继承->protected和public在子类中变为protected
