#include<iostream>
#include<memory>
#include<algorithm>

using namespace std;

class Base{
	public:
		friend void swap(Base &, Base&);
		Base(string *p):ps(p),use(new int(1)){}
		Base(const Base& other):ps(other.ps),use(other.use) {
			cout<<"const"<<endl;
			(*use)++;
		}

		Base& operator = (const Base& other){
			cout<<"assign"<<endl;
			(*(other.use))++;
			(*use)--;
			if(!(*use)){
				delete ps;
				delete use;
			}

			ps = other.ps;
			use = other.use;
			return *this;
		}

		Base(Base && s):ps(s.ps),use(s.use) noexcept{
			s = use = nullptr;
			use = new int(1);
		}

		Base& operator = (Base && b){
			if(&b != this){//查看地址非否相等
				delete ps;
				delete use;

				ps = b.ps;
				use = b.use;

				ps = use = nullptr;
			}
		}


		~Base(){
			if(!(*use)){
				delete ps;
				delete use;
			}
		}

	private:
		string* ps;
		int* use;
};


class Folder{


void swap(Base& left,Base& right){
	using std::swap;
	cout<<"using"<<endl;
	swap(left.ps,right.ps);
}

class Other{
	public:
		Other(string *s):base(s){}

		void swap(Other& left,Other& right){
			using std::swap;
			swap(left.base, right.base);
		}

		Other& operator = (Other ot){
			//not reference
			using std::swap;
			swap(*this,ot);
			return *this;
		}

	private:
		Base base;
};

int main(){
	Base a;
	Base b = a;
	Base c(a);
}
