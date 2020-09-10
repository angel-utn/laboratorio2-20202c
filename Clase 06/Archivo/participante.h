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
bool modificar_participante();
void mostrar_participante(Participante);

Participante leer_participante(int);
int cantidad_participantes();
int buscar_participante(int);
void listar_participantes();
bool guardar_participante(Participante);
bool guardar_participante(Participante, int);
void listar_participante_x_id();




#endif // PARTICIPANTE_H_INCLUDED
