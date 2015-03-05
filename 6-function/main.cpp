#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

//列表初始化的返回值
vector<int> process(char c){
	switch(c){
		case 'a':
			return {};
			break;
		case 'b':
			return {1,2,3};
			break;
		default:
			return {};
			break;
	}
}

// 返回数组的指针
typedef int name1[10];
name1* func(){}

using name2 = int[10];
name2* func2(){}

auto func3() -> int(*)[10]{}

int value[10];
decltype(value) *fun4(){
}

// overload and const 
void func5(const int * i){
	cout<<"const"<<endl;
}

void func5(int * j){
	cout<<"un_const"<<endl;
}

constexpr int func6(){
	return 0;
}

main(){
	initializer_list<string> ls{"a","b","c","d","e"};

	cout<<ls.size()<<endl;

	for(auto iter = ls.begin(); iter != ls.end(); iter++){
		cout<< *iter<<endl;
	}

	int * i = 0;
	func5(i);


	int val = 0;
	assert(val>1);
	cerr<<__FILE__<<endl;
	cerr<<__LINE__<<endl;
	cerr<<__TIME__<<endl;
	cerr<<__DATE__<<endl;

	return 0;
}
