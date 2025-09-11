#include <Foco.hpp>
#include <iostream>
#include <SerieNavidad.hpp>
using namespace std;
int main(int argc, char const *argv[])
{
    Foco foco;
    foco.Apagar();
    foco.Encender();
    SerieNavidad miSerieNavidad;
    miSerieNavidad.Encender();
    miSerieNavidad.ImprimirSerie();
    miSerieNavidad.Apagar();
    miSerieNavidad.ImprimirSerie();
    
    cout<<"Foco: "<<foco.MostrarEstado()<<endl;


    /* string nombre;
    cout<<"escribe tu nombre"<<endl;
    cin>>nombre;
    cout<<"Hola "<<nombre<<endl;
    cout<<"Hola mundo"<<endl;
    return 0; */
}
