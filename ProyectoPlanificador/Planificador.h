#include <iostream>
#include <Proceso.h>
#include <vector.h>
using namespace std;

class Planificador{
    private: vector<Proceso> vectorProcesos;
             uint32          NumeroProcesos;
    public:
          Planificador(uint32&);
          bool addProcess(Proceso&);
          void printPlanificador;
};