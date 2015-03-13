## 语句
* 复合语句(compound statement)是指用花括号括起来的语句和声明序列.也称为块(block).
* [switch语句](https://github.com/ThreeCobblers/Paladin/blob/master/blog/C%2B%2B/sosohu/chap5.md)
## 异常处理
* [程序出错的处理方式](https://github.com/ThreeCobblers/Paladin/blob/master/blog/C%2B%2B/sosohu/chap5.md)
* throw expression. 引发(raise)异常.
* try block. try语句块以关键字try开始,并以几个catch clause结束.
|位置|异常|介绍|
|:----:|:----:|:----:|
|exception头文件|exception class|只报告异常,不提供额外信息|
|stdexcept头文件|....|常用的异常类, what()返回内容|
|new头文件|bad_alloc||
|type_info头文件|bad_cast||
>See main.cpp for more information.

### 栈展开

当throw出现在try语句块内时,检查与该try关联的catch语句.如果找到了,就使用其处理异常.否则就退出当前函数,在外层函数中继续查找.可能最后一直没有找到匹配的catch,程序调用terminate.


在栈展开的过程中,编译器将确保创建的对象被正确的销毁.
> 调用析构函数


