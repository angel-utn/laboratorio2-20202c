#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct Fecha{
  int dia, mes, anio;
};

Fecha cargar_fecha();
void mostrar_fecha(Fecha);

#endif // FECHA_H_INCLUDED
