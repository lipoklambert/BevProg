#include "std_lib_facilities.h"

void swap_v(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*Ez a függvény nem fordítható le, 
mivel a csak olvasható referenciákhoz próbálunk értékeket rendelni.
 Nyugodtan elhagyhatjuk.:*/

/*void swap_cr(const int& a, const int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}*/

int main(){

	int x = 7;
	int y = 9;
	
	//swap_v(x, y);
	/*Lefordítja, de nem cserél semmit, 
	mivel a swap_v csak az argumentumainak másolatait kezeli. */
	
	swap_r(x, y);  //Jól működik
	
	//swap_cr(x, y);
	
	//swap_v(7, 9);
	/*Lefordítja, de nem csinál semmit, 
	mivel a függvényben az argumentumok tárolására létrehozott 
	ideiglenes objektumok a függvény visszatérésekor megsemmisülnek,
	 és nem lehetséges az eredeti argumentumokra való hivatkozás */
	
	//swap_r(7, 9);
	/*Nem fordítható le, mivel a hivatkozás nem 
	inicializálható rvalue-val (literál), 
	mivel nincs olyan objektum, amelyre hivatkozni lehetne. */
	
	//swap_cr(7, 9);
	
	cout << "value of x: " << x << ", value of y: " << y << endl;
	
	const int cx = 7;
    	const int cy = 9;
    	
    	//swap_v(cx, cy);
    	/*Lefordítja, de nem cserél, mivel másolatokat kezel*/
    	
    	//swap_r(cx, cy);
    	/*Nem fordít. Úgy tűnik, hogy nem jó, 
    	ha egy const változóra próbálunk nem const hivatkozást tenni.*/
    	
    	//swap_cr(cx, cy);
    	
	//swap_v(7.7, 9.9);   //Azonos: swap_v(7,9)
    	
	//swap_r(7.7, 9.9);   //Azonos: swap_r(7,9)
       
	//swap_cr(7.7, 9.9);
       
	cout << "value of cx: " << cx << ", value of cy: " << cy << endl;
	
	double dx = 7.7;
    	double dy = 9.9;
    	
    	//swap_v(cx, cy);
    	/*Lefordítja, de nem cserél. Hasonló ok, mint a korábbi ok(ok).*/
    	
    	//swap_r(cx, cy);
    	/*Mivel implicit konverzióval állunk szemben a double-ből int-be,
    	 amit a függvény kap, az egy rvalue, és erre nem lehet hivatkozni.*/
    	
    	//swap_cr(cx, cy);
    	
	//swap_v(7.7, 9.9);   //Azonos: swap_v(7,9)
    	
	//swap_r(7.7, 9.9);   //Azonos: swap_r(7,9)
       
	//swap_cr(7.7, 9.9);
    	
    	cout << "value of dx: " << dx << ", value of dy: " << dy << endl;

	return 0;

}
