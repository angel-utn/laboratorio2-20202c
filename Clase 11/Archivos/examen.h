#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#include "fecha.h"

class Examen{
    private:
    int legajo, tipo;
    float nota;
    Fecha fechaExamen;

    public:
        Examen();
        void mostrarDireccion();
        void setLegajo(int);
        void setNota(float);
        void setFecha(Fecha);
        void setTipo(int);
        int getLegajo();
        float getNota();
        int getTipo();
        Fecha getFecha();
        void cargar();
        void mostrar();
        bool guardarEnDisco(int = -1);
        bool leerDeDisco(int);
};

// Función global
void listado_examenes();

#endif // EXAMEN_H_INCLUDED
