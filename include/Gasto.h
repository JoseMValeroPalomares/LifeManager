#ifndef LIFEMANAGER_GASTO_H
#define LIFEMANAGER_GASTO_H

#include <string>
#include <sstream>

enum class TipoGasto { Propio, Debo, MeDeben };
enum class NaturalezaGasto { Fisico, Digital };

class Gasto {
private:
    std::string name;            // Nombre
    int cantidad;                // Valor del gasto
    TipoGasto tipo;              // "Propio", "Debo", "MeDeben"
    NaturalezaGasto naturaleza;  // "Fisico" o "Digital"
    std::string descripcion;     // Breve info (opcional)

public:
    Gasto(std::string na = "", int c = 0, TipoGasto t = TipoGasto::Propio,
          NaturalezaGasto n = NaturalezaGasto::Digital, std::string d = "") :
          name(na), cantidad(c), tipo(t), naturaleza(n), descripcion(d) {}

    std::string getName() const { return name; }
    int getCantidad() const { return cantidad; }
    TipoGasto getTipo() const { return tipo; }
    NaturalezaGasto getNaturaleza() const { return naturaleza; }
    std::string getDescripcion() const { return descripcion; }

    void setName(const std::string& n) { name = n; }
    void setCantidad(int C) { cantidad = C; }
    void setTipo(TipoGasto T) { tipo = T; }
    void setNaturaleza(NaturalezaGasto N) { naturaleza = N; }
    void setDescripcion(const std::string& D) { descripcion = D; }

    bool deserializar(const std::string& linea) {
        std::istringstream iss(linea);
        std::string dato;

        int cantidadInt, tipoInt, naturalezaInt;
        // Formato: name,cantidad,tipo,naturaleza,descripcion

        if (
            std::getline(iss, name, ',') &&
            std::getline(iss, dato, ',') && std::istringstream(dato) >> cantidadInt &&
            std::getline(iss, dato, ',') && std::istringstream(dato) >> tipoInt &&
            std::getline(iss, dato, ',') && std::istringstream(dato) >> naturalezaInt &&
            std::getline(iss, descripcion)
        ) {
            cantidad = cantidadInt;
            tipo = static_cast<TipoGasto>(tipoInt);
            naturaleza = static_cast<NaturalezaGasto>(naturalezaInt);
            return true;
        }
        return false;
    }

    std::string serializar() const {
        return name + "," +
            std::to_string(cantidad) + "," +
                std::to_string(static_cast<int>(tipo)) + "," +
                    std::to_string(static_cast<int>(naturaleza)) + "," +
                        descripcion;
    }

};

#endif //LIFEMANAGER_GASTO_H
