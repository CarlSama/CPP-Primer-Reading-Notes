#include<iostream>

using namespace std;

int main(){
	cout<<2;
	clog<<"clog";//Seems clog is un-bufferd
	cout<<1;
	cerr<<"cerror";//Now std-cout-stream would be refresh ! when using endl here, clog wouldn't be printed
	clog<<"clog";
	return 0;
}
