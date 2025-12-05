#include <iostream>
#include <vector>
#include "Fraccion.h"

int main() {
    std::vector<Fraccion> fracciones(5);

    for (int i = 0; i < 5; ++i) {
        int n, d;
        std::cout << "Introduce el numerador de la fraccion " << i + 1 << ": ";
        std::cin >> n;

        do {
            std::cout << "Introduce el denominador de la fraccion " << i + 1 << " (no puede ser 0): ";
            std::cin >> d;
            if (d == 0) std::cout << "Error: El denominador no puede ser 0. Intente de nuevo.\n";
        } while (d == 0);

        fracciones[i] = Fraccion(n, d);
    }

    Fraccion sumatoria(0, 1);
    for (const auto& fraccion : fracciones) {
        sumatoria.sumar(fraccion);
    }

    std::cout << "La suma de las fracciones es: " << sumatoria.to_string() << std::endl;

    return 0;
}