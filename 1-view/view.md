## Function Defination

	return_type function_name(parameter_list) left_curly_brace

		function body -> block

	right_curly_brace

## Type

类型定义了数据元素的内容,以及这种数据上可以进行的操作.

* int -> built-in type

## Develop

* Preprocessor
* Compiler
* Assembler
* Linker

## IO

一个流是一个字符序列,是从IO设备顺序读出/写入.

流(stream)代表随着时间的推移,字符是**顺序**生成或消耗的.

IO设备将数据保存在buffer中,可以使用endl显示的刷新;读cin会刷新cout;程序非正常终止会刷新cout.

### IO对象

* cin

* cout

* cerr (标准错误)输出警告和错误信息 -> 标准错误流
写到cerr的数据是不存储到buffer的.

* clog 输出运行时一般信息 -> 标准错误流
默认情况下,clog数据存入buffer(?).

[Here is an smart example](https://github.com/ThreeCobblers/Paladin/blob/master/blog/C%2B%2B/chap1.md) 

```C++
int main(){
    cout<<2;
    clog<<"clog";//Seems clog is un-bufferd ?
    cout<<1;
    cerr<<"cerror";//Now std-cout-stream would be refresh ! when using endl here, clog wouldn't be printed
    clog<<"clog";
    return 0;
}
```

<< operator 接受两个运算对象:左侧运算对象是一个ostream对象,右侧的运算对象时要打印的值.返回左侧的运算对象(可以连用 <<).

* "this is a string" -> string literal

### 读取输入数量不定的数据:
```C++
	while(std::cin >> value){
	}
```
输入运算符返回其左侧对象,既std::cin.当我们使用一个istream对象作为条件时,其效果是检测流的状态.

* 流是有效的,成功.

* 遇到eof,或者一个无效的输入时,istream对象的状态变为无效.处于无效状态的istream对象会使条件变为假.

## while

	while ( condition )
		statement

## for
	
	for ( init-statement ; condition ; expression )
		statement
	
