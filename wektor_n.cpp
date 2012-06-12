#include <iostream>
using namespace std;

class WektorN {
	string label;
	int* array;
	int size;

public:
	/**
	 *  a)
	 * 
	 * Konstruktor
	 * @param l Label/Etykieta
	 * @param size Wymiar przestrzeni
	 * @param default_value Domysna wartosc wspolrzednych wektora
	 */
	WektorN(string l, int size, int default_value = 3);
	/**
	 * b)
	 * 
	 * Kontstruktor kopiujacy 
	 * @param v
	 */
	WektorN(const WektorN &v);

	/**
	 * c)
	 * 
	 * Destruktor
	 */
	~WektorN();

	/**
	 * d)
	 * 
	 * Ustaw i-ta wspolrzedna wektora na wartosc W
	 * @param i
	 * @param w
	 */
	void ustaw(int i, int w);


	/**
	 * e)
	 * 
	 *  Przeladowany operator '+'
	 */
	friend WektorN operator+(const WektorN &v1, const WektorN &v2);


	/**
	 * f)
	 * 
	 *  przeladowany operator '<<'
	 */
	friend ostream& operator<<(ostream &out, WektorN &v);




};

WektorN operator+(const WektorN &v1, const WektorN &v2) {
	if (v1.size != v2.size) {
		throw "Rozmiary podanych wektorow sie nie zgadzaja";
	}
	WektorN v(v1.label + " + " + v2.label, v1.size);
	for (int i = 0; i < v.size; i++) {
		v.ustaw(i, v1.array[i] + v2.array[i]);
	}
	return v;
}

void WektorN::ustaw(int i, int w) {
	if (i >= this->size) {
		throw "parametr 'i' musi miescic sie w rozmiarze tablicy";
	}
	this->array[i] = w;
}

WektorN::~WektorN() {
	delete [] this->array;
	this->array = NULL;

}

WektorN::WektorN(const WektorN& v) {
	this->label = v.label;
	this->array = new int[v.size];
	this->size = v.size;
	for (int i = 0; i < v.size; i++) {
		this->array[i] = v.array[i];
	}
}

WektorN::WektorN(string l, int s, int default_value) {
	this->size = s;
	this->array = new int[s];
	for (int i = 0; i < s; i++) {
		this->array[i] = default_value;
	}
	this->label = l;
}

ostream& operator<<(ostream &out, WektorN &v) {
	out << v.label + ": [";

	for (int i = 0; i < v.size; i++) {
		out << v.array[i];
		if (i < v.size - 1) {
			out << ",";
		}
	}
	out << "]";
}


// g)

int main() {

	// a)
	WektorN v1("pierwszy", 4);
	WektorN v2("drugi", 7, 10);
	WektorN v3("trzeci", 4, 8);
	// b)
	WektorN vc(v2);
	// e)
	WektorN vs = v1 + v3;

	// f)
	cout << "\nv1: " << v1;
	cout << "\nv2: " << v2;
	cout << "\nv3: " << v3;

	// d)
	v2.ustaw(3, 666);
	cout << "\nWektor v2 Po ustawieniu wspolrzednej '3' na '666':   " << v2;


	cout << "\nKopia wektora v2 sprzed zmiany wspolrzednej nr. 3:   " << vc;


	cout << "\nSuma v1+v3 =  " << vs;

	cout << "\nProbojemy dodac wektory o roznych rozmiarach: \n";


	// e) exception
	try {
		WektorN vError = v1 + v2;
		cout << "\nSuma v1+v2  (nie powinno tutaj dojsc) =  " << vError;
	} catch (...) {
		cout << "ERROR! Nie mozna dodawac wektorow o roznych rozmiarach!";
	}


	cout << "\n";
}