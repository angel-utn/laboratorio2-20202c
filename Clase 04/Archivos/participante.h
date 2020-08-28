#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include "fecha.h"

struct Participante{
    int codigo;
    char apellidos[50];
    char nombres[50];
    char genero;
    Fecha nac;
    bool estado;
};

Participante cargar_participante();
void mostrar_participante(Participante);

int buscar_participante(int);
void listar_participantes();
bool guardar_participante(Participante);



#endif // PARTICIPANTE_H_INCLUDED
