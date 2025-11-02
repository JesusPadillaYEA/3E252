#pragma once
#include <vector>
#include "Dibujo.hpp"

class Calle {
public:
    int x, y, ancho, alto;
    Dibujo dibujo_carretera;
    std::vector<Dibujo> vehiculos;

    Calle(int x, int y, int ancho, int alto, ftxui::Color color_asfalto = ftxui::Color::GrayDark)
        : x(x), y(y), ancho(ancho), alto(alto),
          dibujo_carretera(x, y, GenerarFiguraCarretera(ancho, alto), color_asfalto) {}

    static std::vector<std::u32string> GenerarFiguraCarretera(int ancho, int alto) {
        std::vector<std::u32string> figura;

        std::u32string borde_superior = U" " + std::u32string(ancho-2, U'_') + U" ";
        figura.push_back(borde_superior);

        for (int i = 0; i < alto - 2; ++i) {
            std::u32string linea = U"|";
            for (int j = 0; j < ancho - 2; ++j) {
                if (j % 8 == 3 && i == alto / 2)
                    linea += U"-";  
                else
                    linea += U" ";
            }
            linea += U"|";
            figura.push_back(linea);
        }

        std::u32string borde_inferior = U"|" + std::u32string(ancho - 2, U'_') + U"|";
        figura.push_back(borde_inferior);

        return figura;
    }

    void AgregarVehiculo(const Dibujo& vehiculo) {
        int ax = vehiculo.x;
        int ay = vehiculo.y;
        if (ax < x + 1) ax = x + 1;
        if (ax > x + ancho - 3) ax = x + ancho - 3;
        if (ay < y + 1) ay = y + 1;
        if (ay > y + alto - 3) ay = y + alto - 3;

        Dibujo vehiculo_dentro(ax, ay, vehiculo.figura, vehiculo.color);
        vehiculos.push_back(vehiculo_dentro);
    }

    void Dibujar(ftxui::Screen& screen) const {
        dibujo_carretera.Dibujar(screen);
        for (const auto& vehiculo : vehiculos)
            vehiculo.Dibujar(screen);
    }
};
