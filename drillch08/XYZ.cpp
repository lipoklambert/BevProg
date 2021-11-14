#include "std_lib_facilities.h"

namespace X{
	int var;
	void print(){
		cout << "X var value: " << var << endl;
	}
}

namespace Y{
	int var;
	void print(){
		cout << "Y var value: " << var << endl;
	}
}

namespace Z{
	int var;
	void print(){
		cout << "Z var value: " << var << endl;
	}
}

int main(){

	X::var = 7;
	X::print();	//print X var
	using namespace Y;
	var = 9;
	print();	//print Y var
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();	//print Z var
	}
	print();	//print Y var
	X::print();	//print X var

	return 0;

}
