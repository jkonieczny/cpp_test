#include <iostream>
#include <string>

using namespace std;

#define ALPHABET_LETTERS 26
/**
 *  zadanie 2 (wyswietlanie tablicy
 * @param name nazwa tablicy do wyswietlenia
 * @param array tablica
 * @param size rozmiar tablicy
 */
void print_array(string name,int array[],int size);

/**
 * zadanie 1
 * wygeneruj tablice  o rozmiarze 'size' z kolejnymi liczbami naturalnymi
 * @param size rozmiar tablicy
 * @return array pointer
 */
int* generate_array(int size);

/**
 * Zadanie 3
 * wygenerowac tablice z alfabetem A-Z
 * @param array
 */
void generate_alphabet(char* array);

/**
 * Wyswietl podana liczbe calkowita jako kod binarny
 * @param x
 */
void print_binary(int x);

int main()
{
    int size;
    char C[ALPHABET_LETTERS];
    // 1
    cout << "Podaj rozmiar tablicy z liczbami naturalnymi: ";
    cin >> size;
    int* A = generate_array(size);
    cout << "\nTablica z " << size << " liczbami naturalnymi (wliczajac 0): \n";
    
    // 2
    print_array("A",A,size);
    
    
    // 3
    generate_alphabet(C);
    cout << "Litery alfabetu:\n";
    for(int i=0;i<ALPHABET_LETTERS;i++){
        cout << (char)C[i] << " ";
    }
    cout << "\n";
    
    
    // 4
    int x;
    cout << "Podaj liczbe calkowita do przekonwertowania: ";
    cin >> x;
    print_binary(x);
    
    
    return 0;      
}

void print_binary(int x)
{
    string output;
    
    cout << "Binary: ";
    
    
    while(x>0){
        // sprawdz czy ostatni bit jest 'nieparzysty'  np.   0000001 , jesli tak zapisz odpowiednia flage do stringa output
        output.append( (x&1) == 0 ? "0": "1");
        //cout << ();
        // przesun bitowo cala liczbe w prawo, czyli   100111  ->  10011 
        x >>= 1;
    }
    const char*  output_char = output.c_str();
    for(int i=output.length()-1;i>=0;i--){
        cout << output_char[i];
    }
    cout << "\n";
}

void generate_alphabet(char* array)
{
    int i=0;
    for(char a='A';a<='Z';a++){
        array[i] = a;
        i++;
    }
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

