#include "std_lib_facilities.h"

//Bemenetből modellez egy nyelvtani tokent
struct Token {
	/*kind-ra mindig szükség van, míg a value és a name inicializálása az egyes fajták igényei 		szerint történik. Így három különálló konstruktor van meghatározva. */

	char kind;
	double value; //számoknál: egy value
	string name;
	Token(char ch) :kind(ch), value(0) { } //Tokent csinál char-ból
	Token(char ch, double val) :kind(ch), value(val) { } //Tokent csinál char-ból és double-ből
	//Hiányzó konstruktor volt:
	Token(char ch, string n) :kind(ch), name(n) { }
};

//A cin-t Token stream-ként modellezi
class Token_stream {
	bool full; //van Token a bufferben?
	Token buffer;  //itt tartunk egy Tokent visszahelyezve a putback() segítségével 
public:
	//full(0)-ról inkább full(false)
	Token_stream() :full(false), buffer(0) { } //Token_stream, ami cin-ből olvas
							// : ... nincs Token a bufferben
	Token get(); //kap egy Tokent (get() máshol van definiálva)
	//unget() helyett inkább putback(), a könyv azt használja
	void putback(Token t) { buffer = t; full = true; } //visszatesz egy Tokent
								//(Token_stream buffer-ébe)
	void ignore(char);
};

//Token fajták:
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char squareroot = 's';
const char power = 'p';

Token Token_stream::get()
//Feldolgozza a cin-t hogy végső szimbólumokat kapjon
{
	/*Ha már van pufferelt token, küldje vissza,
	 és hagyjon helyet a következőnek */
	if (full) { full = false; return buffer; }
	
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
	case let:
		return Token(ch); //Ezek a literálok közvetlenül meghatározzák a Token fajtát (kind)
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	// Numerikus literálok
	{	cin.putback(ch);	//helyezze vissza a számjegyet a bemeneti stream-be
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
	    /*Sztringekre is számíthatunk. Ezek kulcsszavak a deklarációhoz
	     és a programból való kilépéshez vagy a változónevekhez. */
		if (isalpha(ch)) {
			string s;
			s += ch;
			//Hozzá kellene hogy adja a char-t a sztringhez, s = ch helyett s += ch:
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == "exit") return Token(quit);
			if (s == "sqrt") return Token(squareroot);
			if (s == "pow") return Token(power);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
/*Token_streamben lévő aktuális Token eldobásra kerül,
 ha a Token fajtája az argumentum által jelzett token típusú
 (szám, let, név ...). A karaktereket is eltávolítja a cinből,
 amíg meg nem találjuk a c token típusát. Röviden: törölje inputot, míg nincs meg c*/ 
{
	//Először ellenőrizze, hogy egy c típusú token nincs-e pufferelve 
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	//Pufferelt token elvetése 
	full = false;

	//és közvetlenül a cin-n dolgozzon 
	char ch;
	while (cin>>ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;	//biztosítja a get()-et, ignore()-t és a putback()-et 

double expression();	//deklaráció, hogy a primary() meghívhassa expression()-t

double sqrt_and_pow(char c)
// Kiértékeli a c funkcióját. A következő bemenet Expression kell, hogy legyen 
{
    vector<double> args;    // Vektor a függvényargumentumok tárolására.  
                        
    Token t = ts.get();
    if (t.kind != '(') error("Definition is not correctly written");

    // Argumentumlista kezelése
    switch (c) {
    case squareroot:
        args.push_back(expression());
        break;
    case power:
        args.push_back(expression());
        t = ts.get();
        if (t.kind != ',') error("Definition is not correctly written");
        args.push_back(expression());
        break;
    }

    t = ts.get();
    if (t.kind != ')') error("Definition is not correctly written");

    // Kiértékelés és korlátozások implementálása
    switch (c) {
    case squareroot:
        if (args[0] < 0) error("sqrt() is undefined for negative numbers");
        return sqrt(args[0]);
    case power:
        return pow(args[0], narrow_cast<int>(args[1]));
    }
}

//Zárójelekkel, számokkal, előjelekkel... foglalkozik
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	//Hiba: ')' expected, nem pedig '('
	if (t.kind != ')') error("')' expected");
	//Hiba volt: Ha siker, nincs semmi return-ölve, tehát kell return d:
	return d;
	}
	case '-':	//Negatív előjelű számok 
		return -primary();
	case '+':	//Pozitív előjelű számok 
		return +primary();
	case number:
		return t.value;
	case name:     //Változó: értéket kap a táblázatból
		return get_value(t.name);
	case squareroot:{
		return sqrt_and_pow(t.kind);}
	case power:{
    		return sqrt_and_pow(t.kind);}
		
	default:
		error("primary expected");
	}
}

//Szorzással, osztással és maradékos osztással foglalkozik
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{
		double d = primary();
		if (d == 0) error("divide by zero");
		left = fmod(left, d); /*fmod() függvény kiszámítja a
					 számláló/nevező lebegőpontos maradékát */
		break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//Összeadással és kivonással foglalkozik
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration()
{
	//Részenként ellenőrizze a Deklaráció nyelvtani szabályát a "let" mögött
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);	/*Az input (bevitel) elvetése mindaddig,
				 amíg egy print parancsot 
				 vagy új sort nem talál*/
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();  
		if (t.kind == quit) return;
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();  //Dobja el a fennmaradó inputot, és kérje újra a felhasználót
	}
}

int main()

try {

	//előre definiált változó 
	names.push_back(Variable("k", 1000)); /*Azért "k" és nem 'k', mert a Variable struktúrában
						string van megadva*/

	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "exception\n";
	return 2;
}

