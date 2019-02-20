#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>
#include <fstream>
#include <string.h>

using namespace std;
void menuPrincipal();

int main(){
    
    //Variables:
    char opc;
    char buff[30];
    string fileName;
    fstream archivo;
    pid_t pidRead, pidWrite;

    menuPrincipal();

    cin >> opc;

    switch(opc){

        case 'n':

            cout << "Ingresa el nombre del archivo: \n-";
            cin >> fileName;
            archivo.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
            archivo.close();
        
            break;
                
        case 'r':

            cout << "Ingresa el nombre del archivo: \n-";
            cin >> fileName;
            
            if((pidRead = fork()) == 0){
                
                cout << "Proceso de lectura creado. PID: " << getpid() << "\n";
                archivo.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
                archivo.read(buff, 30);
                cout << "Imprimiendo contenido de archivo:\n" << buff << "\n";
                archivo.close();

            } else {

                waitpid(pidRead, NULL, 0);
                archivo.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
                archivo.read(buff, 30);
                cout << "Lectura del padre: "<< buff <<"\n";
                archivo.close();

            }
            break;
        
        case 'w':

            cout << "Ingresa el nombre del archivo: \n-";
            cin >> fileName;

            if((pidWrite = fork()) == 0){

                cout << "Proceso de escritura creado. PID: " << getpid() << "\n";
                archivo.open(fileName, ios::out | ios::binary | std::fstream::app);
                cout << "Escribe: \n-";
                cin.ignore();
                cin.getline(buff, 30, '\n');
                archivo.write(buff, 30);
                archivo.close();

            } else {

                waitpid(pidWrite,NULL,0);
                archivo.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
                archivo.read(buff, 30);
                cout << "Lectura del padre: "<< buff <<"\n";
                archivo.close();

            }
            break;
    }
    
}

void menuPrincipal(){
    cout << "MENU: \n\n Crear archivo: 'n' \n\n Leer archivo: 'r' \n\n Escribir archivo: 'w'\n\n-";
}
