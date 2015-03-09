#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<stringstream>

using namespace std;

int main(){
	char c;
/*	while(cin>>c){
	}
	
	iostream::iostate state = cin.rdstate();
	cout<<(state & iostream::eofbit)<<ends;*/
	cout<<unitbuf;
	cout<<"a";
	cout<<"s";
	clog<<"d";
	cerr<<"f";
	cout<<endl;

	string line;
	fstream fs("info",fstream::app);
	try{
		if(!fs)
			throw(runtime_error("can't open file"));

		fs<<"Append me !";
		cout<<fs.fail()<<endl;
		fs<<"2.Append me !";
		fs.close();
		cout<<"Show file state: "<<fs.is_open()<<endl;
	}catch(runtime_error e){
		cout<<"Error :"<<e.what()<<endl;
	}

	stringstream in,out;
		while(cin>>in){
			in<<":";
		}

		cout<<out;

	return 0;
}

