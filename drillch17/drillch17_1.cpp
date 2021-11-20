#include "std_lib_facilities.h"

//4. feladat
void print_array10(ostream& os, int* a){
	for(int i = 0; i < 10; ++i){
		os << a[i] << endl; }
}

//7. feladat
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
	int* a = new int[10];
	//2.feladat
	for(int i = 0; i < 10; ++i){
		cout << "Value of int: " << a[i] << endl; 
	}
	//3.feladat	
	delete[] a;
	
	//5. feladat
	int* b = new int[10];
	for(int i = 0; i < 10; ++i){
		b[i] = 100 + i;
	}
	
	print_array10(cout, b);
	delete[] b;
	
	//6.feladat
	int* c = new int[11];
	for(int i = 0; i < 11; ++i){
		c[i] = 100 + i;
		cout << "Value of 'c' array: " << c[i] << endl;
	}
	
	delete[] c;
	
	//8. feladat
	int* d = new int[20];
	for(int i = 0; i < 20; ++i){
		d[i] = 100 + i;
	}
	
	print_array(cout, d, 20);
	delete[] d;
	
	//10. feladat
	vector<int> v;
	for(int i = 0; i < 10; ++i){
		v.push_back(100+i);
	}
	print_vector(cout, v, 10);
	
	vector<int> v2;
	for(int i = 0; i < 11; ++i){
		v2.push_back(100+i);
	}
	print_vector(cout, v2, 11);
	
	vector<int> v3;
	for(int i = 0; i < 20; ++i){
		v3.push_back(100+i);
	}
	print_vector(cout, v3, 20);

	return 0;
 
}
