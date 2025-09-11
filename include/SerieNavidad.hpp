#pragma once
#include <Foco.hpp>
#include <iostream>

class SerieNavidad
{
private:
    Foco focos[10];
public:
    SerieNavidad() {}
    ~SerieNavidad() {}
    void Encender(){
        for (int numFoco = 0; numFoco < 10; numFoco++)
        {
            focos[numFoco].Encender();
        }
        
    }
    void Apagar(){
        for (int numFoco = 0; numFoco < 10; numFoco++)
        {
            focos[numFoco].Apagar();
        }
        
    }
    void ImprimirSerie(){
        for (int numFoco = 0; numFoco < 10; numFoco++)
        {
            cout << focos[numFoco].MostrarEstado();
        }
        
    }

};


