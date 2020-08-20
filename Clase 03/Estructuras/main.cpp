#include <iostream>
using namespace std;
#include "participante.h"

int main(){
    const int CANT = 3;
    Participante p[CANT];
    cargar_lista_participantes(p, CANT);
    mostrar_lista_participantes(p, CANT);
    return 0;
}
