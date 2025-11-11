//
// Created by josev on 11/11/2025.
//

#ifndef LIFEMANAGER_ENTRENO_H
#define LIFEMANAGER_ENTRENO_H


#include <string>

enum class ObjetivoEntreno { Volumen, Definicion, Mantenimiento };
enum class TipoEntreno { Gym, Judo, Cardio, Ayuno, Otro };

class Entreno {
private:
    TipoEntreno tipo;
    ObjetivoEntreno objetivo;
    int duracionMin;      // Duración (minutos)
    int kcalQuemadas;     // Calorías consumidas en la sesión
    int horasDormidas;    // Horas dormidas la noche anterior
    float peso;           // Peso corporal (kg)
    std::string fecha;    // Fecha del entreno (puedes usar std::string para simplificar)

public:
    Entreno(
        TipoEntreno tipo = TipoEntreno::Gym,
        ObjetivoEntreno objetivo = ObjetivoEntreno::Mantenimiento,
        int duracionMin = 0,
        int kcalQuemadas = 0,
        int horasDormidas = 0,
        float peso = 0.0f,
        std::string fecha = ""
    )
    : tipo(tipo), objetivo(objetivo), duracionMin(duracionMin),
      kcalQuemadas(kcalQuemadas), horasDormidas(horasDormidas),
      peso(peso), fecha(fecha) {}

    TipoEntreno getTipo() const { return tipo; }
    ObjetivoEntreno getObjetivo() const { return objetivo; }
    int getDuracionMin() const { return duracionMin; }
    int getKcalQuemadas() const { return kcalQuemadas; }
    int getHorasDormidas() const { return horasDormidas; }
    float getPeso() const { return peso; }
    std::string getFecha() const { return fecha; }

    void setTipo(TipoEntreno t) { tipo = t; }
    void setObjetivo(ObjetivoEntreno o) { objetivo = o; }
    void setDuracionMin(int d) { duracionMin = d; }
    void setKcalQuemadas(int k) { kcalQuemadas = k; }
    void setHorasDormidas(int h) { horasDormidas = h; }
    void setPeso(float p) { peso = p; }
    void setFecha(const std::string& f) { fecha = f; }
};

#endif //LIFEMANAGER_ENTRENO_H