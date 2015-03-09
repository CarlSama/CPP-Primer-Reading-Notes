# IO class

* 不能对IO对象拷贝或赋值.

* 通常以引用(&)的方式传递.

* 读写IO对象会改变其状态,因此传递和返回的引用不能时const.

## iostream

### 条件状态

IO库定义了一个与机器无关的iostate类型,它提供了表达式状态的完整功能.ls

|状态|解释|函数|
|*---*|*---*|*---*|
|strm::iostate|机器无关类型||
|strm::badbit|流已崩溃(不可恢复错误)|s.bad()|
|strm::failbit|IO操作失败(可恢复错误)|s.fail()|
|strm::eofbit|流到达文件末尾|s.eof()|
|strm::goodbit|流未出错,值为0|s.good()|
|s.clear()|状态复位||
|s.clear(flags)|根据类型复位||
|s.setstate(flags)|置位||
|s.rdstate()|返回当前状态||

eg. cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit)

### 缓冲

由于设备的写操作可能很费时,允许操作将多个输出合成单一的设备写操作.

缓冲被刷新的原因:

1. 程序正常结束
2. 缓冲区满
3. 用操作符显式刷新(endl, flush, ends)
4. 使用unitbuf(每次写操作后立即刷新)来清空缓冲区
> cout<<unitbuf
> cout<<nounitbuf
5. 输出流别关联到另一个流(s.tie(x)/ s.tie())


## fstream

对一个已经打开的文件调用open会失败,并导致failbit被置位.

|文件模式|说明|
|*---*|*---*|
|in|读|
|out|写|
|app|写操作时定位到文件尾|
|ate|打开文件定位到文件尾|
|trunc|截断文件|
|binary|二进制方式打开|

1.	out/in只能针对fstream对象
2.	out默认附带trunc
3.	没有设定trunc时,可以设定app

## sstream

|操作|解释|
|*---*|*---*|
|s.str()|返回s保存的string拷贝|
|s.str(n)|将n拷贝到s中,返回void|





