#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

int main(){
	vector<int> sum{1,2,3,4,5,6,7,8,9};
	long long res = accumulate(sum.begin(),sum.end(),0);
	cout<<unitbuf;
	cout<<res;
}
