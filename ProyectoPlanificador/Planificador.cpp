#include "Planificador.h"
using namespace std;

Planificador::Planificador(uint32 &size):NumeroProcesos(size){
    vectorProcesos.reserve(NumeroProcesos);
}

bool Planificador::addProcess(Proceso &tmp){
    // vector<Proceso>::iterator i;
    // *i = tmp;
    vectorProcesos.push_back(tmp);
    return 1;
}

void Planificador::printPlanificador(){
    for(vector<Proceso>::iterator i = vectorProcesos.begin(); i != vectorProcesos.end(); ++i){   
        (*i).print();
    }
}