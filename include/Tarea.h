//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_TAREA_H
#define LIFEMANAGER_TAREA_H

#include <string>
#include <sstream>

enum class CategoriaTarea { Personal, Trabajo, Estudio, Otro };
enum class EstadoTarea { NoCompletada, Completada };

inline std::string categoriaToString(CategoriaTarea cat) {
    switch(cat) {
        case CategoriaTarea::Personal: return "Personal";
        case CategoriaTarea::Trabajo:  return "Trabajo";
        case CategoriaTarea::Estudio:  return "Estudio";
        case CategoriaTarea::Otro:     return "Otro";
    }
    return "Desconocido";
}

inline std::string estadoToString(EstadoTarea est) {
    switch(est) {
        case EstadoTarea::NoCompletada: return "Pendiente";
        case EstadoTarea::Completada:   return "Completada";
    }
    return "Desconocido";
}

class Tarea {
    std::string nombre;
    CategoriaTarea categoria;
    EstadoTarea estado;

public:
    Tarea(const std::string& n = "", CategoriaTarea c = CategoriaTarea::Personal, EstadoTarea e = EstadoTarea::NoCompletada)
        : nombre(n), categoria(c), estado(e) {};

    std::string getNombre() const { return nombre; }
    CategoriaTarea getCategoria() const { return categoria; }
    EstadoTarea getEstado() const { return estado; }

    void setNombre(const std::string& n) { nombre = n; }
    void setCategoria(const CategoriaTarea& c) { categoria = c; }
    void setEstado(const EstadoTarea& e) { estado = e; }

    bool deserializar(const std::string& linea) {
        std::istringstream iss(linea);
        std::string dato;
        int categoriaInt, estadoInt;
        if (std::getline(iss, nombre, ',') &&
            std::getline(iss, dato, ',') &&
            std::istringstream(dato) >> categoriaInt &&
            std::getline(iss, dato, ',') &&
            std::istringstream(dato) >> estadoInt) {
            categoria = static_cast<CategoriaTarea>(categoriaInt);
            estado = static_cast<EstadoTarea>(estadoInt);
            return true;
        }
        return false;
    }

    std::string serializar() const {
        return nombre + "," +
               std::to_string(static_cast<int>(categoria)) + "," +
               std::to_string(static_cast<int>(estado));
    }
};

#endif //LIFEMANAGER_TAREA_H
