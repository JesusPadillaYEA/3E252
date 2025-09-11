#pragma once
#include <EstadoFoco.hpp>

class Foco
{
private:
    EstadoFoco estado;

public:
    Foco() {
        estado = false;
    } // Constructor
    ~Foco() {} //Destructor
    void Encender(){
        estado = true;
    }
    void Apagar(){
        estado = false;
    }    
    EstadoFoco MostrarEstado(){
        return estado;
    }

};


