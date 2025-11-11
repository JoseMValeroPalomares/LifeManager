//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_GESTORGASTOS_H
#define LIFEMANAGER_GESTORGASTOS_H

#include <vector>
#include "Gestor.h"
#include "Gasto.h"

class GestorGastos : public Gestor {
    std::vector<Gasto> gastos;
public:
    GestorGastos(const std::string& ruta) : Gestor("Gastos", ruta) {}

    void guardarEnArchivo() override {
        // Lógica de guardado
    }
    void cargarDeArchivo() override {
        // Lógica de carga
    }
    void listar() const override {
        // Lógica de listado
    }
    // Otros métodos propios


};


#endif //LIFEMANAGER_GESTOREGASTOS_H