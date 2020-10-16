#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include "persona.h"

class Alumno:public Persona{
    private:
    int legajo;

    public:
        Alumno();
        void setLegajo(int);
        int getLegajo();
        void cargar();
        void mostrar();
};


#endif // ALUMNO_H_INCLUDED
