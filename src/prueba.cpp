#include <iostream>
#include <string>
#include <thread>
#include<chrono>
#include <ftxui/screen/screen.hpp>
using namespace std;
using namespace ftxui;

#include <Contenido.hpp>

int main(int argc, char const *argv[])
{

    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(20)
    );
    
    Dibujo escena1({
string("                                         __(._  )   d0P				 "),
string("                                           <  (D)  .MP				 "),
string("                                         .~ \\ /~```M-. 			 "),
string("                                       .~    V    Mo_ \\   			 "),          
string("==((((}{)                              (   (___. {:)-./				 "),
string("                                        ~._____.(:}       			 "),
string("                                         /     .M\\   				 "),
string("                                        /      "" \\				 "),
string("                                        |    /\\   |				 "),
string("                                        /   /  \\   \\				 "),
string("                                       /   /    \\   \\				 "),
string("                                       \\__/      \\__/				 "),
string("                                       / /        | |				 "),
string("                                      .^V^.      .^V^.				 "),
string("                                       +-+        +-+				 ")
});
    Dibujo escena2({
string("                                         __(._  )   d0P				 "),
string("                                           <  (D)  .MP				 "),
string("                                         .~ \\ /~```M-. 			 "),
string("                                       .~    V    Mo_ \\   			 "),          
string("====((((}{)                            (   (___. {:)-./ 			 "),
string("                                        ~._____.(:}      			 "),
string("                                         /     .M\\   				 "),
string("                                        /      "" \\				 "),
string("                                        |    /\\   |				 "),
string("                                        /   /  \\   \\				 "),
string("                                       /   /    \\   \\				 "),
string("                                       \\__/      \\__/				 "),
string("                                       / /        | |				 "),
string("                                      .^V^.      .^V^.				 "),
string("                                       +-+        +-+				 ")
});


    while(true){
        
        escena2.MoverDerecha();
        escena1.Imprimir(pantalla);
        escena2.Imprimir(pantalla);
        pantalla.Print();
        
        this_thread::sleep_for(chrono::seconds(50));
        
        pantalla.Clear();
        cout << pantalla.ResetPosition();    
    
    }

    return 0;
}