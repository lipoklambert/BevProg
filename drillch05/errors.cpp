#include "std_lib_facilities.h"

int main(){

	try{
	
		/* 1. feladat
		Eredeti kód:
		Cout << "Success!\n"; 
		Hiba:
		C betű naggyal van írva (kicsivel kell)
		Javított:
		*/
		cout << "Success!\n";
		
		/*
		2. feladat
		Eredeti kód:
		cout << "Success!\n;
		Hiba:
		Sztring nincs lezárva		
		Javított:
		*/
		cout << "Success!\n";
		
		/*
		3. feladat
		Eredeti kód:
		cout << "Success" << !\n"
		Hiba:
		Lezáratlan sztring, pontosvessző hiánya
		Javított:
		*/
		cout << "Success" << "!\n";
		
		/*
		4. feladat
		Eredeti kód:
		cout << success << '\n';
		Hiba:
		Idézőjelek hiánya
		Javított:
		*/
		cout << "success" << '\n';
		
		/*
		5. feladat
		Eredeti kód:
		string res = 7;
		vector<int> v(10);
		v[5] = res;
		cout << "Success!\n";
		Hiba:
		Int vektor eleme nem lehet sztring
		Javított:
		*/
		int res = 7;
		vector<int> v5(10);
		v5[5] = res;
		cout << "Success!\n";
		
		/*
		6. feladat
		Eredeti kód:
		vector<int> v(10);
		v(5) = 7;
		if(v(5) != 7)
			cout << "Success!\n";
		Hiba:
		Hogy hanyadik elem szögletes zárójelben kell jelezni, a feltétel pedig egyenlő (nem 		nem egyenlő)
		Javított:
		*/
		vector<int> v6(10);
		v6[5] = 7;
		if(v6[5] == 7)
			cout << "Success!\n";
			
		/*7. feladat
		Eredeti kód:
		if (cond)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		Hiba:
		Feltétel hiányzik, nincs deklarálva
		Javított:
		*/	
		bool cond = true;
		if (cond)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
			
		/*8. feladat
		Eredeti kód:
		bool c = false;
		if (c)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
		Hiba:
		Az eredmény Fail a változó miatt
		Javított:
		*/
		bool c8 = true;
		if (c8)
			cout << "Success!\n";
		else
			cout << "Fail!\n";
			
		/*9. feladat
		Eredeti kód:
		string s = "ape";
		boo c = "fool" < s;
		if (c)
			cout << "Success!\n";
		Hiba:
		Bool-ból l lemaradt, a logikai értékünk hamis így nem ír ki semmit
		Javított:
		*/
		string s9 = "ape";
		bool c9 = "fool" < s9;
		if (!c9)
			cout << "Success!\n";
			
		/*10. feladat
		Eredeti kód:
		string s = "ape";
    		if (s == "fool") 
    			cout << "Success!\n";
		Hiba:
		Nem ír ki semmit, a feltételt ezért változtatni kell
		Javított:
		*/
		string s10 = "ape";
    		if (s10 != "fool") 
    			cout << "Success!\n";
    			
    		/*11. feladat
		Eredeti kód:
		string s = "ape";
    		if (s == "fool") 
    			cout < "Success!\n";
		Hiba:
		cout után egy relaciós jel van (kettő kell), és ezzel a feltétellel nem ír ki semmit
		Javított:
		*/
		string s11 = "ape";
    		if (s11 != "fool") 
    			cout << "Success!\n";
    			
    		/*12. feladat
		Eredeti kód:
		string s = "ape";
    		if (s + "fool") 
    			cout < "Success!\n";
		Hiba:
		cout után egy relaciós jel van (kettő kell), és nincs feltétel vizsgálat megadva az 		if-en belül
		Javított:
		*/
		string s12 = "ape";
    		if (s12 != "fool") 
    			cout << "Success!\n";
    		
    		/*13. feladat
		Eredeti kód:
		vector<char> v(5);
    		for (int i=0; 0<v.size(); ++i)
    		     cout << "Success!\n";
		Hiba:
		Végtelen loop, nulla mindig kisebb mint vektorhossz ebben az esetben (nulla cseréje 		i-re)
		Javított:
		*/
		vector<char> v13(5);
    		for (int i=0; i < v13.size(); ++i)
    		     cout << "Success!\n";
    		
    		/*14. feladat
		Eredeti kód:
		vector<char> v(5);
    		for (int i=0; i<=v.size(); ++i)
    		     cout << "Success!\n";
    		Nincs hiba*/
    		     
    		vector<char> v14(5);
    		for (int i=0; i <= v14.size(); ++i)
    		     cout << "Success!\n";
    		     
    		/*15. feladat
		Eredeti kód:
		string s = "Success!\n";
    		for (int i=0; i<6; ++i)
    			cout << s[i];
		Hiba:
		Nem fog kiíródni a teljes szöveg, amit szeretnénk 
		Javított:
		*/
		string s15 = "Success!\n";
    		for (int i=0; i < s15.size(); ++i)
    			cout << s15[i];
    			
    		/*16. feladat
		Eredeti kód:
		if (true) then
    			cout << "Success!\n";
    		else 
    			cout << "Fail\n";
		Hiba:
		Then nem kell és az elágazásnak sincs értelme, elég lenne csak a cout...
		Javított:
		*/
		if (true)
    			cout << "Success!\n";
    		else 
    			cout << "Fail\n";
    			
    		/*17. feladat
		Eredeti kód:
		int x = 2000;
    		char c = x;
    		if (c == 2000) cout << "Success!\n";
		Hiba:
		Az int-ből char-ba való átlépés nem várt eredményt ad (változtat az értéken)
		Javított:
		*/
		int x17 = 2000;
    		if (x17 == 2000) cout << "Success!\n";
    		
    		/*18. feladat
		Eredeti kód:
		string s = "Success!\n";
    		for (int i=0; i<10; ++i)
    			cout << s[i];
		Hiba:
		Lefut, de a sztring esetleges meghosszabítása esetén már hiba lenne 
		mert lefutásnak i < 10-et adtunk meg
		Javított:
		*/
		string s18 = "Success!\n";
    		for (int i=0; i < s18.size(); ++i)
    			cout << s18[i];
    			
    		/*19. feladat
		Eredeti kód:
		vector v(5);
    		for (size_t i=0; i<v.size(); ++i)
        		cout << "Success!\n";
		Hiba:
		Nem adtuk meg a vektoradatok típusát
		Javított:
		*/	
    		vector<int> v19(5);
    		for (int i=0; i < v19.size(); ++i)
        		cout << "Success!\n";
        	
        	/*20. feladat
		Eredeti kód:
		int i = 0;
    		int j = 9;
    		while (i < 10)
        		++j;
    		if (j < i)
        		cout << "Success!\n";
		Hiba:
		Végtelen loop, mert az i-t vizsgáljuk, de a j-t növeljük
		Javított:
		*/
		int i20 = 0;
    		int j20 = 9;
    		while (i20 < 10)
        		++i20;
    		if (j20 < i20)
        		cout << "Success!\n";
        		
        	/*21. feladat
		Eredeti kód:
		int x = 2;
    		double d = 5/(x-2);
    		if (d == 2*x+0.5)
    			cout << "Success!\n";
		Hiba:
		Nullával való osztás következne be, és amúgy sem valami jól 
		érthető, hogy mit akarna a kód, számomra lehetséges megoldása:
		Javított:
		*/
		int x21 = 2;
    		double d21 = 5.0/x21+2;
    		if (d21 == 2*x21+0.5)
        		cout << "Success!\n";
        		
        	/*22. feladat
		Eredeti kód:
		string<char> s = "Success!\n";
    		for (int i=0; i<=10; ++i)
        		cout << s[i];
		Hiba:
		Sztringnél van használva a vektornál használatos adattípus 
		meghatározás, és a for-on belül is biztosabb, ha az i-t s.size()-ig futtatjuk
		Javított:
		*/
		string s22 = "Success!\n";
    		for (int i=0; i<s22.size(); ++i)
        		cout << s22[i];
        		
        	/*23. feladat
		Eredeti kód:
		int i = 0;
    		while (i < 10)
    			++j;
    		if (j < i)
    			cout << "Success!\n";
		Hiba:
		j változó nem lett deklarálva, de ha csak szimplán deklaráljuk azzal is csak
		egy végtelen loopot hozunk létre (while-on belül i-t kell növelni)
		Javított:
		*/
		int i23 = 0;
    		int j23 = 0;
    		while (i23 < 10)
        		++i23;
    		if (j23 < i23)
        		cout << "Success!\n";
        		
        	/*24. feladat
		Eredeti kód:
		int x = 4;
    		double d = 5/(x-2);
    		if (d = 2*x+0.5)
    			cout << "Success!\n";
		Hiba:
		Kiír, de csak azért mert a feltételnek változó megadás van adva nem hasonlítás.
		Ha javítjuk összehasonlításra (==), akkor viszont már nem jó. 
		Javított:
		*/
		int x24 = 4;
    		double d24 = 5/(x24-2);
    		if (d24 = x24/2+0.5)
    			cout << "Success!\n";
    			
    		/*25. feladat
		Eredeti kód:
    		cin << "Success!\n";
		Hiba:
		cin-nel bekérünk adatot, kiírni cout-tal kell
		Javított:
		*/
		cout << "Success!\n";
    			
	}
	
	catch (exception& e){
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	
	catch (...){
		cerr << "Oops: unknown exception!\n";
		return 2;
	}

}

