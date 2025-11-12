#ifndef LIFEMANAGER_GESTOR_H
#define LIFEMANAGER_GESTOR_H
#include <string>
#include <iostream>

class Gestor {
protected:
    std::string name;
    std::string rutaArchivo;
public:
    Gestor(const std::string& nombre, const std::string& ruta)
        : name(nombre), rutaArchivo(ruta) {}
    virtual ~Gestor() = default;

    std::string getName() const {
        return name;
    }

    virtual void MostrarMenu() = 0;

    // Funciones comunes, virtuales: se pueden sobrescribir si necesitas
    virtual void guardarEnArchivo() = 0; // virtual puro, obliga a implementar en hija
    virtual void cargarDeArchivo() = 0;
    virtual void listar() const = 0;
};

#endif //LIFEMANAGER_GESTOR_H
