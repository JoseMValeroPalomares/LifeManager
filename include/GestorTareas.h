#ifndef LIFEMANAGER_GESTORTAREAS_H
#define LIFEMANAGER_GESTORTAREAS_H

#include <vector>
#include "Gestor.h"
#include "Tarea.h"

class GestorTareas : public Gestor {
    std::vector<Tarea> tareas;

public:
    // Constructor: asigna "Tareas" como nombre y la ruta que le pases
    GestorTareas(const std::string& ruta) : Gestor("Tareas", ruta) {}

    void guardarEnArchivo() override {
        // Guarda el vector tareas en el archivo rutaArchivo
    }
    void cargarDeArchivo() override {
        // Carga el vector tareas desde rutaArchivo
    }
    void listar() const override {
        // Muestra las tareas por consola
    }

    void agregarTarea(const Tarea& t) {
        tareas.push_back(t);
    }
    void marcarComoCompletada(int indice) {
        if (indice >= 0 && indice < tareas.size())
            std::cout << std::endl;
            //tareas[indice].marcarCompletada();
    }
};

#endif //LIFEMANAGER_GESTORTAREAS_H
