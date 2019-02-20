#include "Planificador.cpp"
#include "Proceso.cpp"

using namespace std;

int
main(){
    Proceso p1(0, 4, 1);
    Proceso p2(1, 6, 2);
    Proceso p3(3, 7, 6);

    Planificador planner(3);

    planner.addProcess(p1);
    planner.addProcess(p2);
    planner.addProcess(p3);

    planner.printPlanificador();
    
    return 0;
}