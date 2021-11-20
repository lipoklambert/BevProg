#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n){
	for(int i = 0; i < n; ++i){
		os << a[i] << endl; }
}

void print_vector(ostream& os, vector<int> v, int n){
	for(int i = 0; i < n; ++i){
		os << v[i] << endl; }
}

int main(){
	//1. feladat
	int a = 7;
	int* p1 = &a;
	//2. feladat
	cout << "p1: " << p1 << endl;
	cout << "*p1: " << *p1 << endl;
	
	//3. feladat
	int* p2 = new int[7] {1, 2, 4, 8, 16, 32, 64};
	//4. feladat
	cout << "p2: " << p2 << endl;
	cout << "*p2: " << *p2 << endl;
	
	//5. feladat
	int* p3 = p2;
	//6. feladat
	p2 = p1;
	//7. feladat
	p2 = p3;
	
	//8. feladat
	cout << "p1: " << p1 << endl;
	cout << "*p1: " << *p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "*p2: " << *p2 << endl;
	
	//9. feladat
	delete[] p2;
	//10. feladat
	p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	//11. feladat
	p2 = new int[10];
	//12. feladat
	for (int i = 0; i<10; ++i)
        	p2[i] = p1[i];
        
        //13. feladat
        vector<int> v1 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
        vector<int> v2;
        for (int i = 0; i < v1.size(); ++i)
        	v2.push_back(v1[i]);
	
	return 0;

}
