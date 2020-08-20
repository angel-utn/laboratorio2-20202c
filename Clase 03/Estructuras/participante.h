#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include "fecha.h"

struct Participante{
    int codigo;
    char apellidos[50];
    char nombres[50];
    char genero;
    Fecha nac;
};

Participante cargar_participante(Participante *, int);
void mostrar_participante(Participante );

void cargar_lista_participantes(Participante *, int);
void mostrar_lista_participantes(Participante *, int);
int buscar_participante(int, Participante *, int);


#endif // PARTICIPANTE_H_INCLUDED
