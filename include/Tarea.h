//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_TAREA_H
#define LIFEMANAGER_TAREA_H

#include <string>
#include <sstream>

enum class CategoriaTarea { Personal, Trabajo, Estudio, Otro };
enum class EstadoTarea { NoCompletada, Completada };

class Tarea {
    std::string nombre;
    CategoriaTarea categoria;
    EstadoTarea estado;

public:
    Tarea(const std::string& n = "", CategoriaTarea c = CategoriaTarea::Personal, EstadoTarea e = EstadoTarea::NoCompletada) :
    nombre(n),categoria(c), estado(e) {};

    std::string getNombre() const {return nombre;}
    CategoriaTarea getCategoria() const {return categoria;}
    EstadoTarea getEstado() const {return estado;}

    void setNombre(const std::string& n) {nombre = n;}
    void setCategoria (const CategoriaTarea& c) {categoria = c;}
    void setEstado(const EstadoTarea& e) {estado = e;}

    bool deserializar(const std::string& linea) {
        std::istringstream iss(linea);
        std::string dato;
        int categoriaInt, estadoInt;
        if (std::getline(iss, nombre, ',') &&
            std::getline(iss, dato, ',') &&
            std::istringstream(dato) >> categoriaInt &&
            std::getline(iss, dato, ',') &&
            std::istringstream(dato) >> estadoInt ) {
            categoria = static_cast<CategoriaTarea>(categoriaInt); // Enum correspondiente
            estado = static_cast<EstadoTarea>(estadoInt); // Enum correspondiente
            return true;
        }
        return false;

    }


};


#endif //LIFEMANAGER_TAREA_H