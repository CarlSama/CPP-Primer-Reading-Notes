## 

由于移动构造函数,新标准库的容器性能优于旧的.

vector

array
>大小固定

string

deque

list
forward_list
> 不支持随机访问

### 常用操作

列表初始化

a.swap(b)

c.emplace(inits) 使用inits构造c中元素

c.assign(iter, iter)
> 从不同但相容的类型赋值

