#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int
main(){
    pid_t               pidV, pidC;
    char                bufferV[30], bufferC[30];    
    int                 fdV[2], fdC[2];
    char                opc;

    pipe(fdC);
    pipe(fdV);

    if((pidV = fork()) == 0){
        int counterV = 0;
        while(cin >> opc && counterV < 5){
            if(opc == 'a' || opc == 'e'){
                read(fdV[0], bufferV, counterV);
                bufferV[counterV] = opc;
                ++counterV;
                write(fdV[1], bufferV, counterV);
                cout << endl << "Escribiendo en el hijo " << getpid() << ": " << opc <<endl;
            } else {
                sleep(1);
            }
        }
    } else {
        
        if((pidC = fork()) == 0){
            int counterC = 0;
            while(cin >> opc && counterC < 5){
            if(opc == 'b' || opc == 'c'){
                read(fdC[0], bufferC, counterC);
                bufferC[counterC] = opc;
                ++counterC;
                write(fdC[1], bufferC, counterC);
                cout << endl << "Escribiendo en el hijo " << getpid() << ": " << opc << endl;
            } else {
                sleep(1);
            }
        }} else {
            waitpid(pidC, NULL, 0);
            
            read(fdV[0], bufferV, 5);
            read(fdC[0], bufferC, 5);
            
            for(int i = 0; i < 5; ++i){
                cout << bufferV[i];
            }
            cout << endl;
            for(int i = 0; i < 5; ++i){
                cout << bufferC[i];
            }
            cout << endl;
        }
    }
}