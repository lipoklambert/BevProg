#include "std_lib_facilities.h"

void f(vector<int> a){
	
	int length_of_a = 10;
		
	vector<int> lv(length_of_a);
	lv = a;
	for (int i = 0; i < length_of_a; ++i){
		cout << lv[i] << ' ';
	} 
	cout << endl;
	
	vector<int> lv2 = a;
	for (int i = 0; i < length_of_a; ++i){
		cout << lv2[i] << ' ';
	} 
	cout << endl;

}

int main(){

	vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	f(gv);
	
	vector<int> vv = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(vv);

	return 0;

}
