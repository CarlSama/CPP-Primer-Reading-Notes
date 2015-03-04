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
