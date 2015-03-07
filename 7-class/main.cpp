#include<iostream>

using namespace std;


typedef unsigned int uint;
class Base{
	public:
		//Base() = default;//C++11,默认内联
		Base(double c = 0.0):Base(c,0){}
		Base(double c,size_t st):counts(c),size(st){}

		void test() const ;
		void test() ;
		uint show(){
			return uint(0);
		}
		friend void myfriend();
		static const uint sint = 0;

	//	static void here()const{}

//		typedef unsigned int uint;
	//	using uint = unsigned int;
		const double counts;
		mutable size_t size{0};
//		uint &ref;
};
//uint Base::sint = 0;

void Base::test()const {
	size = 1;
	cout<<size<<endl;
}

void Base::test(){
	size = 1;
	cout<<size<<endl;
}

int main(){
	Base b;
	cout<<b.counts<<endl;

	return 0;
}
