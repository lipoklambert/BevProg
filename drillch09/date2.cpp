#include "std_lib_facilities.h"

struct Date {
	int y, m, d;
	Date(int yy, int mm, int dd);   // ellenőrizze az érvényes dátumot, és inicializálja
    	void add_day(int n);            // növelje a Dátumot n nappal 
};

Date::Date(int yy, int mm, int dd)
// Egyszerű napi inicializálás, egyszerű ellenőrzésekkel. 
{
	if (dd < 1 || dd > 31) error("Invalid day");
	if (mm < 1 || mm > 12) error("Invalid month");

	y = yy;       // Még nem csekkoljuk az év érvényességét
    	m = mm;
    	d = dd;
}

void Date::add_day(int n){
//Függvény a napok hozzáadására vagy kivonására a dátumból. 
	d += n;

	if (d > 31){
		m++;
		d -= 31;
		if(m > 12){
			y++;
			m -=12;
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
	
    	Date today(1978, 6, 25);

	Date tomorrow(today);
    	tomorrow.add_day(1);
    	
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
