#include <iostream>
using namespace std;
#include <cstdio>
#include "participante.h"

int main(){
    Participante reg = cargar_participante();
    if (guardar_participante(reg) == true){
        cout << "Se guardó el participante";
    }
    else{
        cout << "No se guardó el participante";
    }

    cout << endl;
    listar_participantes();

    return 0;
}
