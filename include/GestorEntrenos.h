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

    void MostrarMenu() override {
        int opcion = 0;
        do {
            std::cout << "Bienvenido al gestor de " << getName() << std::endl << std::endl;
            std::cout << "Elige una opcion: " << std::endl;
            std::cout << "|-1: Chekear entrenos" << std::endl;
            std::cout << "|-2: " << std::endl;
            std::cout << "|-3: " << std::endl;
            std::cout << "|-4: Volver atras" << std::endl << std::endl;
            std::cin >> opcion;

            switch (opcion) {
                case 1:
                    listar();
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    std::cout << "Opcion no valida" << std::endl;
            }
        } while (opcion != 4);

    }

    void guardarEnArchivo() override {
        std::ofstream archivo(rutaArchivo, std::ios::trunc);
        if (!archivo) {
            std::cerr << "Error al abrir archivo" << std::endl;
            return;
        }
        for (const auto& entreno : entrenos) {
            archivo << entreno.serializar() << std::endl;
        }
        archivo.close();
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