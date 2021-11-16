#include "std_lib_facilities.h"

struct Date {
	int y;
	int m;
	int d;
};

void init_day(Date& dd, int y, int m, int d)
// Egyszerű napi inicializálás, egyszerű ellenőrzésekkel. 
{
    	if (d < 1 || d > 31) error("Invalid day");
    	if (m < 1 || m > 12) error("Invalid month");

    	dd.y = y;       // Még nem csekkoljuk az év érvényességét
    	dd.m = m;
    	dd.d = d;
}

void add_day(Date& dd, int n){
//Függvény a napok hozzáadására vagy kivonására a dátumból. 
	dd.d += n;

	if (dd.d > 31){
		dd.m++;
		dd.d -= 31;
		if(dd.m > 12){
			dd.y++;
			dd.m -=12;
		}
	}
}

ostream& operator<<(ostream& os, const Date& d)
{
    	return os << '(' << d.y
              	<< ',' << d.m
              	<< ',' << d.d << ')';
}

int main(){
	try{
	
    	Date today;
    	init_day(today, 1978, 6, 25);

	Date tomorrow(today);
    	add_day(tomorrow, 1);
    	
    	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

    	return 0;
    	
	}
	
	catch(exception& e)
	{
    		cerr << e.what() << '\n';
    		return 1;
	}
	
	catch(...)
	{
    		cerr << "Unknown exception!\n";
    		return 2;
	}
}
