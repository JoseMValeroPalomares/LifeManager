#ifndef LIFEMANAGER_GESTORTAREAS_H
#define LIFEMANAGER_GESTORTAREAS_H

#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include "Gestor.h"
#include "Tarea.h"

// Función global o miembro para limpiar consola multiplataforma
inline void limpiarConsola() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

inline void esperarEnter() {
    std::cout << "\nPulsa ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

class GestorTareas : public Gestor {
    std::vector<Tarea> tareas;

    void mostrarLineaMenu(int idx, const std::string& texto) const {
        std::cout << " " << idx << " | " << texto << std::endl;
    }
    void printCabecera(const std::string& titulo) const {
        std::cout << "\n=========================================\n";
        std::cout << "         " << titulo << "\n";
        std::cout << "=========================================\n";
    }
    void printTablaCabecera() const {
        std::cout << std::setw(1) << "Ind"
                  << " | " << std::setw(18) << "Nombre"
                  << " | " << std::setw(8) << "Categoria"
                  << " | " << std::setw(8) << "Estado"
                  << std::endl;
        std::cout << "----|--------------------|-----------|---------" << std::endl;
    }
    void printTareaFila(size_t i, const Tarea& t) const {
        char estadoChar = (t.getEstado() == EstadoTarea::Completada) ? '*' : ' ';
        std::cout << std::setw(1) << (i + 1) << " " << estadoChar << " | ";
        std::cout << std::setw(18) << t.getNombre().substr(0,20) << " | ";
        std::cout << std::setw(9) << categoriaToString(t.getCategoria()) << " | ";
        std::cout << std::setw(8) << estadoToString(t.getEstado()) << std::endl;
    }

    int elegirTarea(const std::string& accion) const {
        if (tareas.empty()) {
            std::cout << "No hay tareas.\n";
            esperarEnter();
            return -1;
        }
        listarTareas();
        std::cout << "\nIntroduce el número de la tarea para " << accion << " (0 para cancelar): ";
        int idx = -1;
        std::cin >> idx;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (idx <= 0 || idx > static_cast<int>(tareas.size())) return -1;
        return idx - 1;
    }

    void listar() const override {}

    void listarTareas(const std::vector<Tarea>* vec = nullptr) const {
        printCabecera("LISTA DE TAREAS");
        printTablaCabecera();
        const std::vector<Tarea>& vt = vec ? *vec : tareas;
        if (vt.empty()) std::cout << "   (Sin tareas)\n";
        for (size_t i = 0; i < vt.size(); ++i)
            printTareaFila(i, vt[i]);
        std::cout << "\n---- Fin de la lista ----\n";
    }

public:
    GestorTareas(const std::string& ruta) : Gestor("Tareas", ruta) {}

    void MostrarMenu() override {
        int opcion = 0;
        do {
            limpiarConsola();
            printCabecera("MENU PRINCIPAL: TAREAS");
            mostrarLineaMenu(1, "Ver todas las tareas");
            mostrarLineaMenu(2, "Anadir nueva tarea");
            mostrarLineaMenu(3, "Eliminar una tarea");
            mostrarLineaMenu(4, "Marcar tarea como completada");
            mostrarLineaMenu(5, "Editar tarea");
            mostrarLineaMenu(6, "Filtrar tareas");
            mostrarLineaMenu(7, "Ordenar tareas");
            mostrarLineaMenu(8, "Volver al menu principal");
            std::cout << "\n==> Elige opcion (1-8): ";
            std::cin >> opcion;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (opcion) {
                case 1:
                    limpiarConsola();
                    listarTareas();
                    esperarEnter();
                    break;
                case 2: {
                    limpiarConsola();
                    std::string nombre;
                    int categoriaInt = 0, estadoInt = 0;
                    std::cout << "Introduce el nombre de la tarea: ";
                    std::getline(std::cin, nombre);
                    std::cout << "Categoria [0-Personal, 1-Trabajo, 2-Estudio, 3-Otro]: ";
                    std::cin >> categoriaInt; std::cin.ignore();
                    std::cout << "Estado [0-Pendiente, 1-Completada]: ";
                    std::cin >> estadoInt; std::cin.ignore();
                    Tarea nuevaTarea(nombre, static_cast<CategoriaTarea>(categoriaInt), static_cast<EstadoTarea>(estadoInt));
                    agregarTarea(nuevaTarea);
                    std::cout << "\nTarea agregada correctamente.\n";
                    esperarEnter();
                    break;
                }
                case 3: {
                    limpiarConsola();
                    int idx = elegirTarea("eliminar");
                    if (idx >= 0) {
                        std::cout << "Tarea '" << tareas[idx].getNombre() << "' eliminada.\n";
                        tareas.erase(tareas.begin() + idx);
                        esperarEnter();
                    }
                    break;
                }
                case 4: {
                    limpiarConsola();
                    int idx = elegirTarea("marcar como completada");
                    if (idx >= 0) {
                        tareas[idx].setEstado(EstadoTarea::Completada);
                        std::cout << "Tarea '" << tareas[idx].getNombre() << "' marcada como completada.\n";
                        esperarEnter();
                    }
                    break;
                }
                case 5: {
                    limpiarConsola();
                    int idx = elegirTarea("editar");
                    if (idx >= 0) {
                        std::string nuevoNombre;
                        int nuevaCat = -1, nuevoEst = -1;
                        std::cout << "Nombre actual: " << tareas[idx].getNombre() << "\n";
                        std::cout << "Nuevo nombre (Enter para no cambiar): ";
                        std::getline(std::cin, nuevoNombre);
                        if (!nuevoNombre.empty()) tareas[idx].setNombre(nuevoNombre);
                        std::cout << "Categoría actual: " << categoriaToString(tareas[idx].getCategoria()) << "\n";
                        std::cout << "Nueva categoría [0-Personal, 1-Trabajo, 2-Estudio, 3-Otro, -1 no cambiar]: ";
                        std::cin >> nuevaCat; std::cin.ignore();
                        if (nuevaCat >= 0 && nuevaCat <= 3) tareas[idx].setCategoria(static_cast<CategoriaTarea>(nuevaCat));
                        std::cout << "Estado actual: " << estadoToString(tareas[idx].getEstado()) << "\n";
                        std::cout << "Nuevo estado [0-Pendiente, 1-Completada, -1 no cambiar]: ";
                        std::cin >> nuevoEst; std::cin.ignore();
                        if (nuevoEst == 0 || nuevoEst == 1) tareas[idx].setEstado(static_cast<EstadoTarea>(nuevoEst));
                        std::cout << "Tarea editada correctamente.\n";
                        esperarEnter();
                    }
                    break;
                }
                case 6: {
                    limpiarConsola();
                    int fcat, fest;
                    std::cout << "Filtrar por (0 = Todos):\n";
                    std::cout << "Categoría [0-Todas, 1-Personal, 2-Trabajo, 3-Estudio, 4-Otro]: "; std::cin >> fcat; std::cin.ignore();
                    std::cout << "Estado [0-Todos, 1-Pendiente, 2-Completada]: "; std::cin >> fest; std::cin.ignore();
                    std::vector<Tarea> filtradas;
                    for (const auto& t : tareas) {
                        bool ok = true;
                        if (fcat >= 1 && fcat <= 4)
                            ok = ok && (static_cast<int>(t.getCategoria()) == fcat - 1);
                        if (fest == 1)
                            ok = ok && (t.getEstado() == EstadoTarea::NoCompletada);
                        if (fest == 2)
                            ok = ok && (t.getEstado() == EstadoTarea::Completada);
                        if (ok) filtradas.push_back(t);
                    }
                    listarTareas(&filtradas);
                    esperarEnter();
                    break;
                }
                case 7: {
                    limpiarConsola();
                    int tipoOrd;
                    std::cout << "Ordenar: 1-Nombre, 2-Categoria, 3-Estado: ";
                    std::cin >> tipoOrd; std::cin.ignore();
                    switch (tipoOrd) {
                        case 1:
                            std::sort(tareas.begin(), tareas.end(), [](const Tarea& a, const Tarea& b) {
                                return a.getNombre() < b.getNombre();
                            });
                            std::cout << "Tareas ordenadas por nombre.\n";
                            break;
                        case 2:
                            std::sort(tareas.begin(), tareas.end(), [](const Tarea& a, const Tarea& b) {
                                return a.getCategoria() < b.getCategoria();
                            });
                            std::cout << "Tareas ordenadas por categoría.\n";
                            break;
                        case 3:
                            std::sort(tareas.begin(), tareas.end(), [](const Tarea& a, const Tarea& b) {
                                return a.getEstado() < b.getEstado();
                            });
                            std::cout << "Tareas ordenadas por estado.\n";
                            break;
                        default:
                            std::cout << "Opcion de ordenacion no válida.\n";
                    }
                    esperarEnter();
                    break;
                }
                case 8:
                    std::cout << "Volviendo al menu principal...\n";
                    esperarEnter();
                    break;
                default:
                    std::cout << "Opcion no valida. Introduce un numero entre 1 y 8.\n";
                    esperarEnter();
            }
        } while (opcion != 8);
    }
    void guardarEnArchivo() override {
        std::ofstream archivo(rutaArchivo, std::ios::trunc);
        for (const auto& tarea : tareas) archivo << tarea.serializar() << '\n';
        archivo.close();
    }
    void cargarDeArchivo() override {
        std::ifstream archivo(rutaArchivo);
        tareas.clear();
        std::string linea;
        while (std::getline(archivo, linea)) {
            Tarea tarea;
            if (tarea.deserializar(linea)) tareas.push_back(tarea);
        }
        archivo.close();
    }
    void agregarTarea(const Tarea& t) {
        tareas.push_back(t);
    }
};

#endif //LIFEMANAGER_GESTORTAREAS_H
