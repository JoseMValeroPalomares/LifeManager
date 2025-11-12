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

    void MostrarMenu() override {
        int opcion = 0;
        do {
            std::cout << "Bienvenido al gestor de " << getName() << std::endl << std::endl;
            std::cout << "Elige una opcion: " << std::endl;
            std::cout << "|-1: Chekear todo" << std::endl;
            std::cout << "|-2: Chekear tus deudas" << std::endl;
            std::cout << "|-3: Chekear tu dinero" << std::endl;
            std::cout << "|-4: Eliminar" << std::endl;
            std::cout << "|-5: Agregar" << std::endl;
            std::cout << "|-6: Volver atras" << std::endl << std::endl;
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
        for (const auto& gasto : gastos) {
            archivo << gasto.serializar() << std::endl;
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