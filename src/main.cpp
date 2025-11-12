#include <iostream>
#include <limits>
#include <string>
#include "GestorTareas.h"
#include "GestorEntrenos.h"
#include "GestorGastos.h"

// Variables globales para las rutas de los archivos (ahora se pueden editar)
std::string rutaTareas   = "C:/Users/josev/Pictures/Cosas/Proyectos/LifeManager/tareas.txt";
std::string rutaEntrenos = "C:/Users/josev/Pictures/Cosas/Proyectos/LifeManager/entrenos.txt";
std::string rutaGastos   = "C:/Users/josev/Pictures/Cosas/Proyectos/LifeManager/gastos.txt";

auto editarRuta = [](std::string& ruta, const std::string& descripcion) {
    std::cout << "Introduce nueva ruta para " << descripcion << " (o 0 para no modificar): ";
    std::string entrada;
    std::getline(std::cin, entrada);
    if (entrada == "0") {
        std::cout << "Ruta NO modificada.\n";
        return;
    }
    // Quitar espacios al principio y final
    entrada.erase(0, entrada.find_first_not_of(" \t\r\n"));
    entrada.erase(entrada.find_last_not_of(" \t\r\n") + 1);
    // Validación básica
    if (entrada.empty() || entrada.size() < 4 || entrada.substr(entrada.size()-4) != ".txt") {
        std::cout << "Ruta invalida. Debe acabar en .txt y no estar vacia.\n";
        std::cout << "Ruta NO modificada.\n";
        return;
    }
    ruta = entrada;
    std::cout << "Ruta modificada correctamente.\n";
};


void printCabecera(const std::string& titulo) {
    std::cout << "\n=========================================\n";
    std::cout << "          " << titulo << "\n";
    std::cout << "=========================================\n";
}

void mostrarLineaMenu(int idx, const std::string& texto) {
    std::cout << " " << idx << " | " << texto << std::endl;
}

void mostrarRutasArchivos() {
    std::cout << "\n-- RUTAS ACTUALES --\n";
    std::cout << "Tareas   : " << rutaTareas << std::endl;
    std::cout << "Entrenos : " << rutaEntrenos << std::endl;
    std::cout << "Gastos   : " << rutaGastos << std::endl;
}

void menu(bool &salir) {
    system("cls");
    int opcion = 0;
    printCabecera("GESTOR DE VIDA");
    mostrarLineaMenu(1, "Gestor de tareas");
    mostrarLineaMenu(2, "Gestor de entrenos y salud");
    mostrarLineaMenu(3, "Gestor de gastos");
    mostrarLineaMenu(4, "Editar rutas de archivos");
    mostrarLineaMenu(5, "Salir");

    std::cout << "\n==> Elige opcion (1-5): ";
    while (!(std::cin >> opcion) || opcion < 1 || opcion > 5) {
        std::cout << "Opcion no valida. Inténtalo de nuevo: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (opcion) {
        case 1: {
            system("cls");
            GestorTareas gestorT(rutaTareas);
            gestorT.cargarDeArchivo();
            gestorT.MostrarMenu();
            gestorT.guardarEnArchivo();
            break;
        }
        case 2: {
            system("cls");
            GestorEntrenos gestorE(rutaEntrenos);
            gestorE.cargarDeArchivo();
            gestorE.MostrarMenu();
            gestorE.guardarEnArchivo();
            break;
        }
        case 3: {
            system("cls");
            GestorGastos gestorG(rutaGastos);
            gestorG.cargarDeArchivo();
            gestorG.MostrarMenu();
            gestorG.guardarEnArchivo();
            break;
        }
        case 4: {
            system("cls");
            printCabecera("EDICION DE RUTAS DE ARCHIVO");
            mostrarRutasArchivos();
            std::cout << "\nElige la ruta a editar\n";
            mostrarLineaMenu(1, "Ruta tareas");
            mostrarLineaMenu(2, "Ruta entrenos");
            mostrarLineaMenu(3, "Ruta gastos");
            mostrarLineaMenu(4, "Volver");
            int rutaOpt = 0;
            std::cout << "\n==> Opcion (1-4): ";
            while (!(std::cin >> rutaOpt) || rutaOpt < 1 || rutaOpt > 4) {
                std::cout << "Opcion no valida. Intentalo de nuevo: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (rutaOpt) {
                case 1: {
                    editarRuta(rutaTareas, "tareas");
                    break;
                }
                case 2: {
                    editarRuta(rutaEntrenos, "entrenos");
                    break;
                }
                case 3: {
                    editarRuta(rutaGastos, "gastos");
                    break;
                }
                case 4:
                    std::cout << "Volviendo al menú principal.\n";
                    break;
            }
            break;
        }
        case 5: {
            printCabecera("Saliendo del programa...");
            salir = true;
            break;
        }
    }
}

int main() {
    bool salir = false;
    while (!salir) {
        menu(salir);
    }
    return 0;
}
