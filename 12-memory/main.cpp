#include<iostream>
#include<memory>
#include<string>

using namespace std;

class vstring{
	public:
		typedef vector<string>::size_type size_type;
		vstring();
		vstring(initializer_list<string> li);
		size_type size() const{
			return data->size();
		}
		bool empty() const{
			return data->empty();
		}
	private:
		shared_ptr<vector<strig> > > data;
		bool check(size_type i);
};

bool vstring::check(size_type i){
	try{
		if(i > data->size())
			throw out_of_range();
	}catch(out_of_range oor){
		cout<<"out of range"<<endl;
	}
}

int main(){
	shared_ptr<string> sptr = make_shared<string>(10,'o');
	try{
		if(!sptr)
			throw(runtime_error("Empty"));
		cout<<(*sptr)<<endl;
		cout<<sptr.unique()<<endl;
		cout<<sptr.use_count()<<endl;

		shared_ptr<string> pp(sptr);
		cout<<pp.use_count()<<endl;
	}catch(runtime_error e){
		cout<<e.what()<<endl;
	}
}
