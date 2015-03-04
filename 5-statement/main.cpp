#include<iostream>
#include<stdexcept>

using namespace std;

int main(){
	try{
		throw runtime_error("Just wrong !");
	}catch(runtime_error e){
		cout<<e.what()<<endl;
	}

	return 0;
}
