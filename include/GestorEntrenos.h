//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_GESTORENTRENOS_H
#define LIFEMANAGER_GESTORENTRENOS_H

#include <vector>
#include "Gestor.h"
#include "Entreno.h"

class GestorEntrenos : public Gestor {
    std::vector<Entreno> entrenos;
public:
    GestorEntrenos(const std::string& ruta) : Gestor("Entrenos", ruta) {}

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


#endif //LIFEMANAGER_GESTORENTRENOS_H