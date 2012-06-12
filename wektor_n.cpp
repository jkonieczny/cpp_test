#include <iostream>
using namespace std;

class WektorN {
	string label;
	int* array;
	int size;

public:
	/**
	 * Konstruktor
	 * @param l Label/Etykieta
	 * @param size Wymiar przestrzeni
	 * @param default_value Domysna wartosc wspolrzednych wektora
	 */
	WektorN(string l, int size, int default_value = 3);
	/**
	 * Kontstruktor kopiujacy 
	 * @param v
	 */
	WektorN(const WektorN &v);
	/**
	 *  przeladowany operator '<<'
	 */
	friend ostream& operator<<(ostream &out, WektorN &v);
	/**
	 * Destruktor
	 */
	~WektorN();
	/**
	 * Ustaw i-ta wspolrzedna wektora na wartosc W
     * @param i
     * @param w
     */
	void ustaw(int i,int w);
	
	/**
	 *  Przeladowany operator '+'
	 */
	friend WektorN& operator+(WektorN &v1, WektorN &v2);
};

void WektorN::ustaw(int i, int w)
{
	if(i >= this->size){
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

int main() {

	WektorN v1("pierwszy", 4);
	WektorN v2("drugi", 7, 10);

	cout << "\n" << v1;
	cout << "\n" << v2;
	
	v2.ustaw(3,666);
	cout << "\nPo ustawieniu wspolrzednej '3' na '666':   " << v2;
	
	
	cout << "\n";
}