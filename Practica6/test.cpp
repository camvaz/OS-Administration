#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char arreglo1[6];
    cout << sizeof(arreglo1) << endl;
    
    cout << sizeof(arreglo1[0]) << endl;

    cout << sizeof(char[6]) << endl;

    arreglo1[0] = 'a';
    arreglo1[1] = 'e';
    arreglo1[2] = 'a';
    arreglo1[3] = 'e';
    arreglo1[4] = 'e';

    cout << ((sizeof arreglo1) / (sizeof *arreglo1)) << endl;

    cout << strlen(arreglo1) << endl;  
    
    cout << sizeof(arreglo1[0]) << endl;
}