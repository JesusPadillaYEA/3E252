#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"
#include "Calle.hpp"
using namespace ftxui;

int main() {
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));


    const std::vector<std::u32string> camion = {
    U"                             __",
    U" .-----------------------'  | ",
    U"/| _ .---. .---. .---. .---.| ",
    U"|j||||___| |___| |___| |___|| ",
    U"|=|||=======================| ",
    U"[_|j||(O)\\__________|(O)\\___] " 
    };

    const std::vector<std::u32string> carro1 = {
        U"     ______",
        U" ___//_||_\\___",
        U"|_          _|",
        U"  (o)-----(o)"
    };

    GestorDibujos gestor;


    // Crear carretera
    Calle calle(0, 10, 80, 12, ftxui::Color::GrayDark);
    calle.AgregarVehiculo(Dibujo(5, 5, carro1, ftxui::Color::Red));
    calle.AgregarVehiculo(Dibujo(40, 15, camion, ftxui::Color::Yellow));
    calle.AgregarVehiculo(Dibujo(30, 5, carro1, ftxui::Color::Blue));

    // Animación
    int frames = 150;
    for (int frame = 0; frame < frames; ++frame) {
        screen.Clear();

        // Animar movimiento de los autos
        calle.vehiculos[0].x = 5 + (frame % 70);  // se mueve a la derecha
        calle.vehiculos[1].x = 40 - (frame % 30); // se mueve a la izquierda
        calle.vehiculos[2].x = 30 + (frame % 40); // se mueve a la derecha

        gestor.DibujarTodos(screen);
        calle.Dibujar(screen);

        // Mostrar pantalla
        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }

    return 0;
}
