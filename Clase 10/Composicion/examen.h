#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED
#include "fecha.h"

class Examen{
    private:
    int legajo;
    float nota;
    Fecha fechaExamen;

    public:
        Examen();
        Examen(Fecha);
        Examen(int, int, int);
        void setLegajo(int);
        void setNota(float);
        void setFecha(Fecha);
        int getLegajo();
        float getNota();
        Fecha getFecha();
        void cargar();
        void mostrar();
};

#endif // EXAMEN_H_INCLUDED
