#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

int 
main(int argc, char * argv[]){

    pid_t           pidC, pidV;
    int             fdV[2];
    int             fdC[2];
    char            bufferC[6];
    char            bufferV[6];
    char            flagBufferV[3];
    char            flagBufferC[3];
    char            opc;
    int             *contadorV, *contadorC;

    contadorV = 0;
    contadorC = 0;
    pipe(fdC);
    pipe(fdV);

    pidC = fork();
    pidV = fork();
    
    while((flagBufferV[0]!='y' && flagBufferC[0]!='y') && cin >> opc) {

        if(opc == 'a' || opc == 'e'){
            
            if(pidV == 0){
                read(fdV[0], contadorV, 4);
                read(fdV[0], bufferV, *contadorV);
                if(*contadorV < 5){
                    // int idx = strlen(bufferV);
                    bufferV[*contadorV] = opc;
                    ++contadorV;
                    cout << "Escribiendo : " << opc << endl;
                    write(fdV[1], bufferV, *contadorV);
                    write(fdV[1], contadorV, 4);
                } else {
                    read(fdV[0], flagBufferV, 0);
                    flagBufferV[0] = 'y';
                    write(fdV[1], flagBufferV, 1);
                }
            } else {
                waitpid(pidV, NULL, 0);
            }
        }

        else if(opc == 'b' || opc == 'c'){
            
            if(pidC == 0){
                read(fdC[0], contadorC, 4);
                read(fdC[0], bufferC, *contadorC);
                if(*contadorC < 5){
                    // int idx = strlen(bufferC);
                    bufferC[*contadorC] = opc;
                    ++contadorC;
                    cout << "Escribiendo : " << opc << endl;
                    write(fdC[1], bufferC, *contadorC);
                    write(fdC[1], contadorC, 4);
                } else {
                    read(fdC[0], flagBufferC, 0);
                    flagBufferC[0] = 'y';
                    write(fdC[1], flagBufferC, 1);
                }
            } else {
                waitpid(pidV, NULL, 0);
            }} else {
            cout << "Opcion invalida. \n";
            sleep(3);
        }       
    }

    for(int i = 0; i <  strlen(bufferV); ++i){
        cout << bufferV[i];
    }
    cout << endl;

    for(int i = 0; i < strlen(bufferV); ++i){
        cout << bufferC[i];
    }
} 