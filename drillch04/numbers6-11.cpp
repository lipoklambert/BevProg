#include "std_lib_facilities.h"

int main(){

	double value;
	double largest;
	double smallest;
	string unit;
	vector<double> values;
	double sum;
	
	cout << "Enter the first value and unit (cm, in, ft or m):" << endl;
	cin >> value >> unit;
	while(unit != "ft" && unit != "m" && unit != "in" && unit != "cm"){
		cout << "Not valid unit! Enter the first value and unit (cm, in, ft or m):" << endl;
		cin >> value >> unit;
	}
	
	if(unit == "ft"){
		value = value * 0.3048;
	}
	if(unit == "in"){
		value = value * 0.0254;
	}
	if(unit == "cm"){
		value = value * 0.01;
	}
	
	values.push_back(value);
	
	largest = value;
	smallest = value;
	
	cout << "Enter the next value and unit (cm, in, ft or m):" << endl;
	
	while(cin >> value >> unit){
		while(unit != "ft" && unit != "m" && unit != "in" && unit != "cm"){
			cout << "Not valid unit! Enter the first value and unit (cm, in, ft or m):" 	       		<< endl;
			cin >> value >> unit;
		}
		if(unit == "ft"){
			value = value * 0.3048;
		}
		if(unit == "in"){
			value = value * 0.0254;
		}
		if(unit == "cm"){
			value = value * 0.01;
		}
		
		values.push_back(value);
		
		if(value > largest){
			largest = value;
			cout << value << " meter(s) is the largest so far" << endl;
		}
		else if(value < smallest){
			smallest = value;
			cout << value << " meter(s) is the smallest so far" << endl;
		}
		else{
			cout << value << " meter(s)" << endl;
		}
		
		cout << "Enter the next value and unit (cm, in, ft or m):" << endl;
	}
	
	sort(values);
	
	cout << "All values entered: " << endl;
	
	for(auto number : values){
		sum = sum + number;
		cout << number << " meter(s)" << endl;
	}
	
	cout << "Smallest value: " << smallest << " meter(s)" << endl;
	cout << "Largest value: " << largest << " meter(s)" << endl;
	cout << "Number of values: " << values.size() << endl;
	cout << "Sum of values: " << sum << " meters" << endl;
	
	
	return 0;

}
