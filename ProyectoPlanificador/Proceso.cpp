#include "Proceso.h"

using namespace std;

Proceso::Proceso(){
    pid = 0;
    t_Exe = 0;
    Prioridad = 0;
    t_Esp = 0;
}

Proceso::Proceso(uint32& newPid, uint32& newExe, uint32& newPrioridad): 
    pid(newPid), t_Exe(newExe), Prioridad(newPrioridad), t_Esp(0) {}

bool Proceso::comparacionPEASC(Proceso &tmp){
    if(this->Prioridad < tmp.Prioridad){
        return true;
    } else if(tmp.Prioridad < this->Prioridad) {
        return false;
    }

    if(this->t_Exe > tmp.t_Exe){
        return true;
    } else if(tmp.t_Exe < this->t_Exe){
        return false;
    }

    if(this->pid >tmp.pid){
        return true;
    } else if(this->pid < tmp.pid){
        return false;
    }

    return true;
}

bool Proceso::comparacionEPASC(Proceso &tmp){
    if(this->t_Exe < tmp.t_Exe){
        return true;
    } else if(tmp.t_Exe < this->t_Exe) {
        return false;
    }

    if(this->Prioridad > tmp.Prioridad){
        return true;
    } else if(tmp.Prioridad < this->Prioridad){
        return false;
    }

    if(this->pid >tmp.pid){
        return true;
    } else if(this->pid < tmp.pid){
        return false;
    }

    return true;
}

bool Proceso::comparacionPEDESC(Proceso &tmp){
    if(this->Prioridad < tmp.Prioridad){
        return true;
    } else if(tmp.Prioridad < this->Prioridad) {
        return false;
    }

    if(this->t_Exe > tmp.t_Exe){
        return true;
    } else if(tmp.t_Exe < this->t_Exe){
        return false;
    }

    if(this->pid < tmp.pid){
        return true;
    } else if(this->pid > tmp.pid){
        return false;
    }

    return true;
}

bool Proceso::comparacionEPDESC(Proceso &tmp){
    if(this->t_Exe < tmp.t_Exe){
        return true;
    } else if(tmp.t_Exe < this->t_Exe) {
        return false;
    }

    if(this->Prioridad > tmp.Prioridad){
        return true;
    } else if(tmp.Prioridad < this->Prioridad){
        return false;
    }

    if(this->pid < tmp.pid){
        return true;
    } else if(this->pid > tmp.pid){
        return false;
    }

    return true;
}

void Proceso::print(){
    cout << "\nPID: " << pid << "\nPrioridad: " << Prioridad << "\nTiempo de ejecucion: " << t_Exe << "\nTiempo de espera: " << t_Esp << endl; 
}