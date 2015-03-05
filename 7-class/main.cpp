#include<iostream>

using namespace std;


class Base{
	public:
		Base() = default;
	private:
		unsigned int counts = 0;//类内初始值
};

int main(){
	Base b;
	return 0;
}
