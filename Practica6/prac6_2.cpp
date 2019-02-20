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
    pid_t           pidV, pidC;
    char            bufferV[30], bufferC[30];
    int             fdV[2], fdC[2], fdW1[2], fdW2[2], countV, countC, countMain, countMain2;
    char            flagBufferV[2], flagBufferC[2], opc;
    string          input;

    countMain = 0;
    countMain2 = 0;

    pipe(fdC);
    pipe(fdV);
    pipe(fdW1);
    pipe(fdW2);

    pidV = fork();
    pidC = fork();

    if(pidV == 0){
        countV = 0;
    }

    if(pidC == 0){
        countC = 0;
    }

    while(flagBufferV[0] != 'y' && flagBufferC[0] != 'y'){
        getline(cin, input);
        if(input.length() == 1)
            opc = input[0];
        
        cout << "\nPadre recibiendo: " << opc << " PID: " << getpid();

        switch (opc)    
        {
            case 'a':
                if(pidV == 0){
                    
                    if(countV < 5){
                        read(fdV[0], bufferV, countV);
                        cout << "Agregando 'a'. PID: " << getpid() << endl;
                        bufferV[countV] = 'a';
                        ++countV;
                        write(fdV[1], bufferV, countV);
                    } else {
                        cout << "Buffer de vocales lleno. PID: " << getpid() << endl;
                        read(fdW1[0], flagBufferV, 0);
                        flagBufferV[0] = 'y';
                        write(fdW1[1], flagBufferV, 1);
                        // exit(0);   
                    }
                }
                break;

            case 'e':
                if(pidV == 0){
                    if(countV < 5){
                        read(fdV[0], bufferV, countV);
                        cout << "Agregando 'e'. PID: " << getpid() << endl;
                        bufferV[countV] = 'e';
                        ++countV;
                        write(fdV[1], bufferV, countV);
                    } else {
                        cout << "Buffer de vocales lleno. PID: " << getpid() << endl;
                        read(fdW1[0], flagBufferV, 0);
                        flagBufferV[0] = 'y';
                        write(fdW1[1], flagBufferV, 1);
                        // exit(0);   
                    }
                }
                break;

            case 'b':
                if(pidC == 0){
                    if(countC < 5){
                        read(fdC[0], bufferC, countC);
                        cout << "Agregando 'b'. PID: " << getpid() << endl;
                        bufferC[countC] = 'b';
                        ++countC;
                        write(fdC[1], bufferC, countC);
                    } else {
                        cout << "Buffer de consonantes lleno. PID: " << getpid() << endl;
                        read(fdW2[0], flagBufferC, 0);
                        flagBufferC[0] = 'y';
                        write(fdW2[1], flagBufferC, 1);
                        // exit(0);  
                    }
                } 
                break;

            case 'c':
                if(pidC == 0){
                    if(countC < 5){
                        read(fdC[0], bufferC, countC);
                        cout << "Agregando 'c'. PID: " << getpid() << endl;
                        bufferC[countC] = 'c';
                        ++countC;
                        write(fdC[1], bufferC, countC);
                    } else {
                        cout << "Buffer de consonantes lleno. PID: " << getpid() << endl;
                        read(fdW2[0], flagBufferC, 0);
                        flagBufferC[0] = 'y';
                        write(fdW2[1], flagBufferC, 1);
                        // exit(0);
                    }
                }
                break;

            default:
                cout << "Input no admitido. PID: " << getpid() << endl;
                break;
        }
    }
    
    cout << endl << flagBufferC[0] << endl;
    cout << endl << flagBufferV[0] << endl;

    for(int i = 0; i < 5; ++i){
        cout << bufferV[i];
    }
    cout << endl;
    for(int i = 0; i < 5; ++i){
        cout << bufferC[i];
    }
    cout << endl;
    kill(pidV, SIGTERM);
    kill(pidC, SIGTERM);
    exit(0);
}