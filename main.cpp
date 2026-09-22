#include <iostream>
#include "centroDespacho.h"

int main() {
    CentroDespacho centro;
    int opcion = 0;

    centro.cargarCSV("Emergencia.csv");

    while (opcion != 3) {
        std::cout << "\n====================================\n";
        std::cout << "    SISTEMA DE DESPACHO 911\n";
        std::cout << "====================================\n";
        std::cout << "1. Mostrar emergencias sin ordenar\n";
        std::cout << "2. Ordenar emergencias por urgencia (Priorizar)\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                centro.mostrarEmergencias();
                break;
            case 2:
                centro.ordenarPorUrgencia();
                std::cout << "\n¡Emergencias reordenadas por urgencia!\n";
                centro.mostrarEmergencias();
                break;
            case 3:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        };
    }

    return 0;
}
