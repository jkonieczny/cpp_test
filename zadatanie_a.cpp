#include <iostream>
#include <string>

using namespace std;

#define N 5

/*
 Struktura do zwrocenia wynikow z punktu 1.  - mozna zwrocic tylko 1 wartosc a jest napisane, zeby byla ilosc 
 * wpisanych elementow + index maksymalnego
 */
class inputArrayResult {
public:
   int max_idx;
   int size;  
};

/** 
 *  funckcja do wyswietlenia zawartosci tablicy (puntk 3)
 */
void print_array(string name,int array[],int size);

/**
 *  skopiowanie parzystych elementow z A do B  (punkt. 2)
 */
int* get_even(int size,int array[]);

/**
 *  pobranie tablicy A  (punkt 1)
 */
inputArrayResult read_from_input(int array[]);

/**
 *  Porownanie stringow (punkt 4)
 */
char* str_compare(char* s1, char* s2);


int main()
{
    int A[N];
    int* B;
    inputArrayResult result;
    char* s1;
    char* s2;
    
    // 1.
    result = read_from_input(A);
    cout << "Tablica A:\n";
    print_array("A",A,N);
    cout << "Ilosc wpisanych elementow: " << result.size << "\n";
    cout << "Index najwiekszego elementu: " << result.max_idx << "\n";
    
    // 2.
    B = get_even(result.size, A);
    
    // 3.
    cout << "Tablica B:\n";
    print_array("B",B,result.size);
    
    // 4.
    cout << "Podaj pattern: \n";
    cin >> s1;
    cout << "Podaj string, w ktorych chcesz znalezc patter: \n";
    cin >> s2;
    
    str_compare(s1,s2);
    
    
    delete B;
    B = NULL;
    return 0;      
}

int* get_even(int size,int array[])
{
    int* B = new int[size];
    
    // wypelnij nowa tablice zerami:
    for(int i=0;i<size;i++){
        B[i] = 0;
    }
    
    // zapisz parzyste elementy z A do B
    int x=0;
    for(int i=0;i<size;i++){
        if(array[i]%2 == 0 ){
            B[x] = array[i];
            x++;
        }
        
    }
    return B;
}

inputArrayResult read_from_input(int array[])
{
    int i=0;
    int input;
    
    for(int z=0;z<N;z++)
    {
        // wypelnienie tablicy zerami
        array[z]=0;
    }
    
    do{
        cout << "Podaj element tablicy ("<< i+1 <<"/"<< N<<")  :";
        cin >> input;
        
        if(input == 0){
            break;           
        }
        array[i] = input;
        i++;
    }while(i<N);
    
    inputArrayResult result;
    result.size = i;
    
    if(i>0){
      int maxIdx = 0;
      int max=array[0];
      // get max:
      for(int x=1;x<=i;x++){
          if(array[x]>max){
             max = array[x];
             maxIdx = x;
          }
      }
      result.max_idx = maxIdx;
    }
    return result;
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


char* str_compare(char* s1, char* s2)
{
    // return strstr(s1,s2);
    
    // dlugosc patternu
    int m = strlen(s1); 
    // dlugosc stringu
    int n = strlen(s2);

    int i, j;
    printf("\nstring : [%s]"
    "\nlength : [%d]"
    "\npattern : [%s]"
    "\nlength : [%d]\n\n", s1,n,s2,m);


    /* Searching */
    for (j = 0; j <= (n - m); ++j)
    {
        for (i = 0; i < m && s1[i] == s2[i + j]; ++i){
            if (i >= m) {
                
                printf("\nMatch found at\n\n->[%d]\n->[%s]\n",j,s2+j);
                return &s2[j];
            }
        }
    }
    return NULL;
}


