## 智能指针

位于memory头文件中.(使用前检查)

shared_ptr在无用之后仍然存在的情况:
> 将shared_ptr存储在容器中,最后应该earse删除,否则不会自动释放

unique_ptr
> u.release() 放弃指向
> u.reset() 释放
> u.reset(nullptr) 重指向
