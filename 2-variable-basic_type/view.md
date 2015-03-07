## Basic bult-in type

###arithmetic type

####itergral type

>Attention !
>字符型有三种: char, signed char, unsigned char.类型char会表现为signed还是unsigned,由编译器决定.

* 浮点 <-> 整形, 截断或补0

* 给无符号类型超出范围的值,结果是初始值对无符号类型**总数**取模. 
> -1 -> unsigned char == (11...1) % (256) == 255

* 给带符号类型超出范围的值,结果未定义(undefined).

* 无符号与有符号运算是,会先转换为无符号类型.
> 无符号 - 有符号 的结果永远不会为负数!
> unsigned - unsigned 必定为正数
> 警惕unsigned用于for循环


####float type

###void *
[there is an good example, good job](https://github.com/ThreeCobblers/Paladin/blob/master/blog/C%2B%2B/chap2.md)

### 字面值常亮的前缀/后缀
[See Page 37 in Primer or here](https://github.com/ThreeCobblers/Paladin/blob/master/blog/C%2B%2B/chap2.md)


## Compound type

复合类型指基于其他类型的类型.

### Reference

引用类型**不是对象**,是某个对象的别名,必须被初始化且不可重新绑定.程序将引用和**对象**bind在一起,而非拷贝.
> int &ref = i;
> ref = j; // 赋值
> C++11引入了 右值引用(rvalue reference)

### Pointer

在C++11中可以利用nullptr来判断空指针.
>int *&p = ptr; // p为指针ptr的引用(面对指针或引用的声明语句时,从右往左阅读)

## Variable

###对象的初始化

对象(object),通常指一块存储数据并具有某种类型的**内存空间**.

在C++中,初始化不是赋值,初始化的含义是创建变量时赋予一个初始值,而赋值的含义是把对象的当前值擦除,以一个新值代替.

####默认初始化(default initialized)

内置类型变量的默认初始化值由定义的位置决定.
>定义于函数外部的变量初始化为0;
>定义于函数内部的变量将未被初始化(uninitialized);

####列表初始化

作为C++11新标准的一部分,用花括号来初始化变量得到了广泛的应用.(list initialization)列表初始化.

对于内置类型,如果我们使用列表初始化且初始值存在丢失信息的风险,则编译将报错.
>long double ld = 3.1415926
>int a{ld} ;//Wrong
>ing c(ld), d = ld; //Pass
>直接使用literal赋值,Wrong

###声明与定义

**分离式编译(separate compliation)**允许将程序分割为若干文件,每个文件可被独立编译.

为了支持分离式编译,C++将声明和定义区分.声明(declaration)使得**名字对程序所知**,一个文件如果要使用别处定义的名字则需要包含名字的声明;定义(definition)负责创建与名字关联的实体.

声明与定义都规定了变量的类型和名字;此外,定义申请空间,同时赋以初值.
>**extern** int i; //声明而非定义(显式初始化会抵消extern的作用)

C++是静态类型(staticlly typed)语言,代表其在**编译阶段**检查类型.

### const

* 就像reference一样,const对象一旦创建就无法改变,所以const对象必须初始化.

* 编译器在编译的过程中,会将const量替换到对应的地方.(就像define).为了执行替换,编译器必须知道常量的值,如果程序包含多个文件,则每个用到const对象的地方必须能放对其访问.
> 如果不使用extern,则这些文件中都要对它有定义.默认情况下,**const对象被设置为仅在当前文件中有效**.
> 如果要在多个文件中共享const量,则在**定义和声明时都指定extern**.

* 在初始化常量表达式时允许使用任意表达式作为初值.
> const int &r = 10 * i; //OK,不会借助于r来修改.
> int &t = 10 * i; // Wrong,实际上t被binding到了临时变量,当然无法通过t来修改值,所以违法.

* const 与 pointer
> const int * 与 int const * 都是 指向常量的指针(pointer to const)
> int * const 为 常量指针(const pointer)

* 顶层const(top-level const)表示对象本身是常量;底层const(low-level const)则与指针和引用等复合类型的基本类型部分有关.
> 类型转换和用作函数参数时,顶层const会被忽略.
> 类型转换时,普通指针->const;但是,const->普通有限制.
> const_cast只能改变对象的底层const(能将对象做出区分的底层const...)

* const成员函数可以修改mutable对象的值
> 存在基于const的函数重载:this指针的类型不同


#### constexpr

常量表达式(const expression)是指不会改变并且在编译中能得到计算结果的表达式.复杂系统中,很难分辨一个初始值是不是常量表达式.在C++11中,允许将变量生命为constexpr,由编译器决定是否为常量表达式.
> constexpr int sz = size(); //只有size是constexpr函数时才正确

声明constexpr时用到的类型必须为字面值类型(literal type): 算数类型,引用和指针.
> 指针的初始值必须为0或者内存中固定(函数体外部或这内部static)
> constexpr 仅能对对指针对象本身有效.
								

constexpr函数是指能用于常量表达式的函数.
> 要遵循约定: 函数的返回类型及所有形参类型都时literal类型, 且只有一条return语句.
> 可以包含其他语句,只要不进行任何操作 :(

### 类型别名(type alias)

* typedef 
> typedef char * cptr;

* C++11中,using
> using SI = sales_item;

### auto

* auto定义的变量必须有初始值.

* auto推断时一般会忽略top-level const,保留low-level const.

### decltype

* 它可以返回操作数的数据类型.
> decltype(f()) i = 10; // f()的返回值类型

* 与auto不同的是,decltype 返回的变量类型包括 **顶层const和引用**.
> 如果表达式是解印用类型,则返回**引用**类型
> decltype(*p) ; // 错误,引用类型为初始化

* 与auto的另一个不同是,双层括号的结果永远是引用
> decltype((p)) ; //Wrong

## Basic

* 可寻址的最小内存块 -> 字节(byte)

* 存储的基本单元 -> 字(word)
