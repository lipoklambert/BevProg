#include "std_lib_facilities.h"

int main(){

	string first_name;
	cout << "Enter the first name of the person you want to write to:\n";
	cin >> first_name;
	
	string friend_name;
	cout << "Please enter a friend's name:\n";
	cin >> friend_name;
	
	char friend_sex = 0;
	cout << "Is this friend male or female? (enter m or f):\n";
	cin >> friend_sex;
	
	int age;
	cout << "Please enter the age of the recipient:\n";
	cin >> age;
	if(age <= 0 || age >= 110){
		simple_error("you're kidding!");
	}
	
	cout << "Dear " << first_name << ",\n\n";
	cout << "How are you? I am fine. I miss you. "
	<< "I've just begin studying at the University of Debrecen.\n\n";
	cout << "Have you seen " << friend_name << " lately?\n";
	
	if('m' == friend_sex){
		cout << "If you see " << friend_name << " please ask him to call me.\n\n";
	}
	
	if('f' == friend_sex){
		cout << "If you see " << friend_name << " please ask her to call me.\n\n";
	}
	
	cout << "I hear you just had a birthday and you are " << age << " years old. ";
	
	if(age < 12){
		cout  << "Next year you will be " << age + 1 << ".";
	}
	
	if(age == 17){
		cout  << "Next year you will be able to vote.";
	}
	
	if(age > 70){
		cout  << "I hope you are enjoying your retirement.";
	}
	
	cout << "\nYours sincerely,\n\nLambert\n";
	
	return 0;
}
