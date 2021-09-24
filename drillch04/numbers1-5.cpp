#include "std_lib_facilities.h"

int main(){

	double n1, n2;
	
	while(cin >> n1 >> n2){
		if(n1 > n2){
			cout << "The smaller value is: "<< n2 << endl;
			cout << "The larger value is: "<< n1 << endl;
			
			if(n1 - n2 < 1.0/100){
				cout << "The numbers are almost equal" << endl;
			}
		}
		
		else if(n2 > n1){
			cout << "The smaller value is: "<< n1 << endl;
			cout << "The larger value is: "<< n2 << endl;
			
			if(n2 - n1 < 1.0/100){
				cout << "The numbers are almost equal" << endl;
			}
		}
		
		else{
			cout << "The numbers are equal" << endl;
		}	
	}
	
	return 0;
}
