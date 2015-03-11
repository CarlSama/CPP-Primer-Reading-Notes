#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Base{
	vector<string> v;
	int i;

	public:
		friend ostream& operator << (ostream & os, const string s);

		friend istream& operator >> (istream& is,string s);//s要是非常量

		string operator [] (size_t n);
		const string operator [] (size_t n) const;

		Base& operator ++ ();
		Base operator ++(int);

		string& operator *() const{
		}

		string* operator ->() const{
		}
};

Base& Base::operator ++(){
	i++;
	return *this;
}

Base Base::operator ++(int){
	Base old = *this;
	i++;
	return old;
}

string Base::operator [] (size_t n){
	try{
		if(n<v.size())
			return v[n];
		else
			throw out_of_range("out");
	}catch(out_of_range oor){
		cout<<oor.what()<<endl;
	}
}

const string Base::operator [] (size_t n)const{
	try{
		if(n<v.size())
			return v[n];
		else
			throw out_of_range("out");
	}catch(out_of_range oor){
		cout<<oor.what()<<endl;
	}
}

ostream& operator << (ostream & os, const string s){
	os<<s;
	return os;
}

istream& operator >> (istream& is,string s){
	is>>s;

	if(!is)//要处理输入失败的情况
		s = string();

	return is;
}

int main(){
	return 0;
}
