//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_GESTORENTRENOS_H
#define LIFEMANAGER_GESTORENTRENOS_H

#include <vector>
#include "Gestor.h"
#include "Entreno.h"
#include <fstream>
#include <iostream>

class GestorEntrenos : public Gestor {
    std::vector<Entreno> entrenos;
public:
    GestorEntrenos(const std::string& ruta) : Gestor("Entrenos", ruta) {}

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
        entrenos.clear();
        std::string linea;
        while (std::getline(archivo, linea)) {
            Entreno entreno;
            if (entreno.deserializar(linea)) {
                entrenos.push_back(entreno);
            }
        }
        archivo.close();
    }
    void listar() const override {
        // Lógica de listado
    }
    // Otros métodos propios

};


#endif //LIFEMANAGER_GESTORENTRENOS_H