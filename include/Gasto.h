//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_GASTO_H
#define LIFEMANAGER_GASTO_H

#include <string>

enum class TipoGasto { Propio, Deuda };
enum class NaturalezaGasto { Fisico, Digital };

class Gasto {
private:
    int cantidad;           // Valor del gasto
    TipoGasto tipo;       // "Propio" o "Deuda"
    NaturalezaGasto naturaleza; // "Fisico" o "Digital"
    std::string descripcion;// Breve info (opcional)

public:
    Gasto (int c = 0, TipoGasto t = TipoGasto::Propio, NaturalezaGasto n = NaturalezaGasto::Digital, std::string d = "") :
        cantidad(c), tipo(t), naturaleza(n), descripcion(d) {}

    int getCantidad() const {return cantidad;}
    TipoGasto getTipo() const {return tipo;}
    NaturalezaGasto getNaturaleza() const {return naturaleza;}
    std::string getDescripcion() const {return descripcion;}

    void setCantidad(int C) {cantidad = C;}
    void setTipo(TipoGasto T) {tipo = T;}
    void setNaturaleza(NaturalezaGasto N) {naturaleza = N;}
    void setDescripcion(std::string D) {descripcion = D;}
};


#endif //LIFEMANAGER_GASTO_H