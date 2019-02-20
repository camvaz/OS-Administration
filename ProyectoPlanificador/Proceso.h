#include <iostream>
typedef unsigned int uint32;

using namespace std;

class Proceso{

    private: uint32     pid;
             uint32     t_Exe;
             uint32     Prioridad;
             uint32     t_Esp;

    public:

    Proceso();
    Proceso(uint32&, uint32&, uint32&);
    bool comparacionPEASC(Proceso&);
    bool comparacionEPASC(Proceso&);
    bool comparacionPEDESC(Proceso&);
    bool comparacionEPDESC(Proceso&);
    void print();
};