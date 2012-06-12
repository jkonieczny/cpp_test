#include <iostream>
using namespace std;


class WektorN {
  private:
    string label;
    int* array;
    
  public:
    WektorN(string l,int size,int default_value=3);
    friend ostream& operator<<(ostream &out,WektorN &v);
};

ostream& operator<<(ostream &out,WektorN &v)
{
    out <<  v.label + ": [";
    int s = sizeof(v.array)/sizeof(int);
    for(int i=0;i< s;i++){
        out << v.array[i];
        if(i<s-1){
            out << ",";
        }
    }
    out << "]";
}


int main(){
    
    WektorN v1("pierwszy",4);
    WektorN v2("drugi",5,10);
    
    cout << v1;
    cout << v2;
}