#include "std_lib_facilities.h"

enum class Month{

	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec

};

Month operator+(const Month& m, int n)
{
    int r = int(m) + n;
    r %= int(Month::dec);

    if (r == 0) return Month::dec;  // A modulo hatásának visszaállítása... 
    return Month(r);
}


// + operátor alapján más operátorok meghatározása
Month operator-(const Month& m, int n) { return (m+(-n)); }
Month& operator+=(Month& m, int n) { m = m + n; return m; }

bool operator<(const Month& m, int n) { return int(m) < n; }
bool operator>(const Month& m, int n) { return int(m) > n; }

/*
Ha esetleg Year is class-ba, valami ilyesmi lenne...
class Year {

	static const int min = 1800;
	static const int max = 2200;
public:
	class Invalid{};
	Year(int x) : y(x) {if(x<min || max<=x) throw Invalid{};}
	int year() {return y;}
private:
	int y;
	
};
To be continued...
*/

class Date {
public:
	class Invalid{};
	Date(int yy, Month mm, int dd); 
    	void add_day(int n);  // növelje a Dátumot n nappal 
    	Month month() const {return m;}
    	int day() const {return d;}
    	int year() const {return y;}
private:
	int y;
	Month m;
	int d;
	bool is_valid();
};

bool Date::is_valid()
{
	if (d < 1 || d > 31) return false;
    	if (m < Month::jan || m > Month::dec) return false;
    	return true;
}

Date::Date(int yy, Month mm, int dd) :y{yy}, m{mm}, d{dd}
{
	if (!is_valid()) throw Invalid{};
}

void Date::add_day(int n){
//Függvény a napok hozzáadására vagy kivonására a dátumból. 
	// A (31*12)-t egy év napjainak vesszük, ha minden hónapban 31 nap van 
	int new_d = n % 31;          // hónapon kívüli napok, növelni
    	int new_m = (n / 31) % 12;   // az évekből hónapok, növelni 
    	int new_y = n / (31*12);     // éveket növelni 

    	d += new_d;
     
	// Ellenőriznünk kell a túlcsordulást, és n és származékai lehetnek negatívak is
	if (d > 31){
		 ++new_m; d -= 31; }     // Napi túlcsordulás 
	if (d < 1){
		 --new_m; d += 31; }     // Napi alulmaradás 
		 
	// Módosítottuk a hónapot, ezért ellenőriznünk kell 
	if (Month::dec < (int(m)+new_m)){
	 	++new_y; }     // Hónap túlcsordulás 
	if (Month::jan > (int(m)+new_m)){
		 --new_y; }     // Hónap alulmaradás 
	m += new_m;   // m Month típusú 
    	y += new_y;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << int(d.month())
		<< ',' << d.day() << ')';
}

int main(){
	try{
	
    	Date today(1978, Month::jun, 25);

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
	
	catch(Date::Invalid)
	{
		cerr << "Invalid date" << '\n';
		return 2;	
	}
	
	catch(...)
	{
    		cerr << "Unknown exception!\n";
    		return 3;
	}
}
