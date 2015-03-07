#include<iostream>

using namespace std;


class Base{
	public:
		Base() = default;//C++11,默认内联
		Base(double c):counts(c){}

		double counts = 0.0;
};

int main(){
	Base b;
	cout<<b.counts<<endl;
	return 0;
}
