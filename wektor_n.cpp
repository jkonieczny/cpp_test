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
    WektorN(string l,int size,int default_value=3);
   /**
     * Kontstruktor kopiujacy 
     * @param v
     */
    WektorN(const WektorN &v);
	/**
	*  przeladowany operator '<<'
	*/
    friend ostream& operator<<(ostream &out,WektorN &v);
	/**
	* Destruktor
	*/
    ~WektorN();
};

WektorN::~WektorN()
{
	delete [] this->array;
	this->array = NULL;
	
}

WektorN::WektorN(const WektorN& v)
{
	this->label = v.label;
	this->array = new int[v.size];
	for(int i=0;i<v.size;i++){
		this->array[i] = v.array[i];
	}
}

WektorN::WektorN(string l, int s, int default_value)
{
    this->size = s;
    this->array = new int[s];
    for(int i=0;i<s;i++)
    {
        this->array[i] = default_value;
    }
    this->label = l;
}

ostream& operator<<(ostream &out,WektorN &v)
{
    out <<  v.label + ": [";
   
    for(int i=0;i< v.size;i++){
        out << v.array[i];
        if(i<v.size-1){
            out << ",";
        }
    }
    out << "]";
}


int main(){
    
    WektorN v1("pierwszy",4);
    WektorN v2("drugi",7,10);
    
    cout << v1;
    cout << v2;
}