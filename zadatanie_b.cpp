#include <iostream>
#include <string>

using namespace std;

/**
 *  zadanie 2 (wyswietlanie tablicy
 * @param name nazwa tablicy do wyswietlenia
 * @param array tablica
 * @param size rozmiar tablicy
 */
void print_array(string name,int array[],int size);

int* generate_array(int size);


int main()
{
    // 1
    cout << "Podaj rozmiar tablicy z liczbami naturalnymi: ";
    
    return 0;      
}

void print_array(string name,int array[],int size)
{
    
    cout << name << " = [";
    for(int i=0;i<size;i++){
       cout << array[i];
       if(i<size-1){
         cout << ",";   
       }
    }
    cout << "]\n";
}

int* generate_array(int size)
{
    int* array = new int[size];
    
    for(int i=0;i<size;i++){
        array[i] = i;
    }
    return array;
}

