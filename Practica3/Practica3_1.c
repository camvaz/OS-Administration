#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdarg.h>

void menuPrincipal();

void menuTipo();

void menuCasual();

void menuEvento();


int main(int argc, char * argv[]){

    
    char opc, opcT, opcS, opcE;
    menuPrincipal();
    pid_t pidT, pidC, pidE, pidPlaya, pidDeporte, pidEjercicio, pidParque, pidCine, pidBailar, pidPresentacion, pidGraduacion, pidTrabajo;
    scanf("%c", &opc);

    switch(opc){
        case 'T':

            if((pidT = fork()) == 0){
                
                printf("Proceso TIPO INFORMAL creado, PID: %d\n", (int)getpid());
                menuTipo();

                scanf("%s", &opcT);

                switch(opcT){
                    case 'p':

                        if((pidPlaya = fork()) == 0){
                            printf("\nVestimenta informal: Tipo playa. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidPlaya, NULL, 0);
                        }
                        break;
                    
                    case 'd':

                        if((pidDeporte = fork()) == 0){
                            printf("\nVestimenta informal: Tipo deportivo. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidDeporte, NULL, 0);
                        } 
                        break;
                    
                    case 'e':

                        if((pidEjercicio = fork()) == 0){
                            printf("\nVestimenta informal: Tipo ejercicio. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidEjercicio, NULL, 0);
                        }
                        break;
                    
                    default:
                        printf("%c", opcT);
                        printf("Opcion invalida, ejecute de nuevo.");
                        break;
                }

            } else {
                waitpid(pidT, NULL, 0);
            }
            break;
        
        case 'C':

            if((pidC = fork()) == 0){
                printf("Opcion CASUAL seleccionada. PID: %d\n", (int)getpid());
                menuCasual();
                scanf("%s", &opcS);

                switch(opcS){
                    case 'p':
                        if((pidParque = fork()) == 0){
                            printf("Vestimenta Casual: Tipo Parque. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidParque, NULL, 0);
                        }
                        break;
                    
                    case 'c':
                        if((pidCine = fork()) == 0){
                            printf("Vestimenta Casual: Tipo Cine. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidCine, NULL, 0);
                        }
                        break;

                    case 'b':
                        if((pidBailar = fork()) == 0){
                            printf("Vestimenta Casual: Tipo Baile. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidBailar, NULL, 0);
                        }
                        break;
                    
                    default:
                        printf("Opcion invalida: Ejecute de nuevo.\n");
                        break;
                }
                
            } else {
                waitpid(pidC, NULL, 0);
            }
            break;
        
        case 'E':

            if((pidE = fork()) == 0){
                printf("Opcion EVENTO seleccionada. PID: %d\n", (int)getpid());
                menuEvento();
                scanf("%s", &opcE);

                switch(opcE){
                    case 'p':
                        if((pidPresentacion = fork()) == 0){
                            printf("Vestimenta Evento: Tipo Presentacion. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidPresentacion, NULL, 0);
                        }
                        break;
                    
                    case 'g':
                        if((pidGraduacion = fork()) == 0){
                            printf("Vestimenta Evento: Tipo Graduacion. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidGraduacion, NULL, 0);
                        }
                        break;

                    case 't':
                        if((pidTrabajo = fork()) == 0){
                            printf("Vestimenta Evento: Tipo Trabajo. PID: %d\n", (int)getpid());
                        } else {
                            waitpid(pidTrabajo, NULL, 0);
                        }
                        break;
                    
                    default:
                        printf("Opcion invalida: Ejecute de nuevo.\n");
                        break;
                }
                
            } else {
                waitpid(pidE, NULL, 0);
            }
            break;

        default:
            printf("Opcion invalida, ejecute de nuevo");
            break;
    }

}

void menuPrincipal(){
    printf("Menu principal: \n \n-Tipo informal: 'T'\n\n-Cita casual: 'C'\n\n-Evento formal: 'E'\n");
}

void menuTipo(){
    printf("Menu Tipo: \n\n-Playa: 'p'\n\n-Deporte: 'd'\n\n-Ejercicio: 'e'\n");
}

void menuCasual(){
    printf("Menu Casual: \n\n-Parque: 'p'\n\n-Cine: 'c'\n\n-Bailar: 'b'\n");
}

void menuEvento(){
    printf("Menu Evento: \n\n-Presentacion: 'p'\n\n-Graduacion: 'g'\n\nTrabajo: 't'\n");
}