#include<iostream>
#include<vector>

using namespace std;

class Man{
	public:
		Man() = default;
		virtual ~Man(){}

		/*virtual int getAge(){
			return age;
		}*/

		using uint = unsigned int;
		uint age = 0;
};

class Police : public Man{ 
	public:
		Police() = default;
		virtual ~Police(){}

		/*virtual int getAge(){
			cout<<"Police"<<endl;
			return age;
		}*/
		void policeID(){
			cout<<"policeID"<<endl;
		}
};

class Farmer: public Man{ 
	public:
		Farmer() = default;
		virtual ~Farmer(){}

		/*virtual int getAge(){
			cout<<"Farmer"<<endl;
			return age;
		}*/

		void farmerID(){
			cout<<"farmenrID"<<endl;
		}
};

int main(){
	//static_cast
	double * d;
	void* a = static_cast<void*>(d);

	//dynamic_cast
	Man mn;
	Farmer* fptr = static_cast<Farmer*>(&mn);//OK
	//运行时检查
	//Farmer* ffptr = dynamic_cast<Farmer*>(&mn);//Wrong
	
	//需要虚函数
	Farmer far;
	Man* mptr = dynamic_cast<Man*>(&far);
	//Farmer* fmptr = dynamic_cast<Farmer*>(mptr);//Wrong

	Police pol;
	Farmer* ffptr = &far;
	//Police* pptr = static_cast<Police*>(fptr);//Wrong,不允许cross cast(同层)
	Police* pptr = dynamic_cast<Police*>(ffptr);//Wrong,不允许cross cast(同层)
	cout<<pptr<<endl;

	//const_cast
	const Farmer cfar;
	Farmer* uncfarptr = const_cast<Farmer*>(&cfar);//去除const属性
	uncfarptr->age = 10;

	Farmer fffar;
	Farmer* const faptr = &fffar;
	const Farmer* cfptr = &fffar;




	
	return 0;
}
