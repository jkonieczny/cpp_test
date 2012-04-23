#include <iostream>
#include <string>

using namespace std;

#define N 3

class inputArrayResult {
   int max_idx;
   int size;  
};

void print_array(string name,int array[]);
inputArrayResult read_from_input(int array[]);



int main()
{
    int A[N];
    
    read_from_input(A);
    
    print_array("A",A);
    return 0;      
}

inputArrayResult read_from_input(int array[])
{
    int i=0;
    int input;
    
    do{
        cout << "Enter element No. "<< i+1 <<" :";
        cin >> input;
        
        if(input == 0){
            break;           
        }
        array[i] = input;
        i++;
    }while(i<N);
    
    print_array("array",array);
    
    inputArrayResult result = new inputArrayResult();
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
      result.maxIdx = maxIdx;
    }
    return result;
}

void print_array(string name,int array[])
{
    int size = sizeof(array)/sizeof(int);
    
    cout << name << " = [";
    for(int i=0;i<=size;i++){
       cout << array[i];
       if(i<size){
         cout << ",";   
       }
    }
    cout << "]\n";
}


