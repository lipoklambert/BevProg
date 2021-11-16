#include "std_lib_facilities.h"

class Date {
	int y, m, d;
public:
	Date(int yy, int mm, int dd);   // ellenőrizze az érvényes dátumot, és inicializálja
    	void add_day(int n);            // növelje a Dátumot n nappal 
    	int month() const {return m;}
    	int day() const {return d;}
    	int year() const {return y;}
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
	// A (31*12)-t egy év napjainak vesszük, ha minden hónapban 31 nap van 
	int new_d = n % 31;          // hónapon kívüli napok, növelni
    	int new_m = (n / 31) % 12;   // az évekből hónapok, növelni 
    	int new_y = n / (31*12);     // éveket növelni 

    	y += new_y;
    	m += new_m;
    	d += new_d;
     
	// Ellenőriznünk kell a túlcsordulást, és n és származékai lehetnek negatívak is
	if (d > 31){
		 ++m; d -= 31; }     // Napi túlcsordulás 
	if (d < 1){
		 --m; d += 31; }     // Napi alulmaradás 
		 
	// Módosítottuk a hónapot, ezért ellenőriznünk kell 
	if (m > 12){
	 	++y; m -= 12; }     // Hónap túlcsordulás 
	if (m < 1){
		 --y; m += 12; }     // Hónap alulmaradás 
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
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
