#include <iostream>
using namespace std;


class WektorN {
    string label;
    int* array;
    int size;
    
  public:
    WektorN(string l,int size,int default_value=3);
    friend ostream& operator<<(ostream &out,WektorN &v);
};





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