//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_GESTORGASTOS_H
#define LIFEMANAGER_GESTORGASTOS_H

#include <vector>
#include "Gestor.h"
#include "Gasto.h"
#include <fstream>
#include <iostream>


class GestorGastos : public Gestor {
    std::vector<Gasto> gastos;
public:
    GestorGastos(const std::string& ruta) : Gestor("Gastos", ruta) {}

    void guardarEnArchivo() override {
        // Lógica de guardado
    }
    void cargarDeArchivo() override {
        std::ifstream archivo(rutaArchivo);
        if (!archivo) {
            std::cout << "Archivo de guardado de tareas no encontrado." << std::endl;
            std::cout << "Creando nuevo archivo..." << std::endl;
            std::ofstream nuevoArchivo(rutaArchivo);
            nuevoArchivo.close();
            std::cout << "Archivo creado en: " << rutaArchivo << std::endl;
            return;
        }
        gastos.clear();
        std::string linea;
        while (std::getline(archivo, linea)) {
            Gasto gasto;
            if (gasto.deserializar(linea)) {
                gastos.push_back(gasto);
            }
        }

    }
    void listar() const override {
        // Lógica de listado
    }
    // Otros métodos propios


};


#endif //LIFEMANAGER_GESTOREGASTOS_H