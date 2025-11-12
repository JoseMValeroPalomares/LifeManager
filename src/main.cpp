#include <iostream>
#include "GestorTareas.h"
#include "GestorEntrenos.h"
#include "GestorGastos.h"

int main() {
    system("cls"); // Solo en Windows. Para Linux/Mac usa "clear" o quita esta línea.
    int opcion = 0;
    std::cout << "Bienvenido al gestor de tu vida" << std::endl;
    std::cout << "Elige una opcion: " << std::endl;
    std::cout << "|-1: Gestor de tareas" << std::endl;
    std::cout << "|-2: Gestor de entrenos y salud" << std::endl;
    std::cout << "|-3: Gestor de gastos" << std::endl << std::endl;

    std::cin >> opcion;

    switch (opcion) {
        case 1: {
            GestorTareas gestorT("C:/Users/josev/Pictures/Cosas/Proyectos/LifeManager/tareas.txt");
            gestorT.MostrarMenu();
            gestorT.cargarDeArchivo();
            break;
        }
        case 2: {
            GestorEntrenos gestorE("C:/Users/josev/Pictures/Cosas/Proyectos/LifeManager/entrenos.txt");
            gestorE.MostrarMenu();
            gestorE.cargarDeArchivo();
            break;
        }
        case 3: {
            GestorGastos gestorG("C:/Users/josev/Pictures/Cosas/Proyectos/LifeManager/gastos.txt");
            gestorG.MostrarMenu();
            gestorG.cargarDeArchivo();
            break;
        }
        default:
            std::cout << "Opcion no valida" << std::endl;
    }
    return 0;
}
