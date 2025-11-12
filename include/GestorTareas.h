#ifndef LIFEMANAGER_GESTORTAREAS_H
#define LIFEMANAGER_GESTORTAREAS_H

#include <vector>
#include "Gestor.h"
#include "Tarea.h"
#include <fstream>
#include <iostream>

class GestorTareas : public Gestor {
    std::vector<Tarea> tareas;

public:
    // Constructor: asigna "Tareas" como nombre y la ruta que le pases
    GestorTareas(const std::string& ruta) : Gestor("Tareas", ruta) {}

    void guardarEnArchivo() override {
        // Guarda el vector tareas en el archivo rutaArchivo
    }
    void cargarDeArchivo() override {
        std::ifstream archivo(rutaArchivo);
        if (!archivo) {
            std::cout << "Archivo de guardado de tareas no encontrado." << std::endl;
            std::cout << "Creando nuevo archivo..." << std::endl;
            std::ofstream nuevoArchivo(rutaArchivo);
            nuevoArchivo.close();
            std::cout << "Archivo creado en: " << rutaArchivo << std::endl;
            // Tras crear, sal de la función porque no hay nada que leer
            return;
        }
        tareas.clear();
        std::string linea;
        while (std::getline(archivo, linea)) {
            Tarea tarea;
            if (tarea.deserializar(linea)) {
                tareas.push_back(tarea);
            }
        }
        archivo.close();
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
