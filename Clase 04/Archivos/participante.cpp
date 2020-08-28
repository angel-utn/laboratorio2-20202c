#include <iostream>
using namespace std;
#include "participante.h"

void mostrar_participante(Participante reg){
    cout << "Código    : " << reg.codigo << endl;
    cout << "Apellidos : " << reg.apellidos<< endl;
    cout << "Nombres   : " << reg.nombres << endl;
    cout << "Género    : " << reg.genero << endl;
    cout << "Nacimiento: ";
    mostrar_fecha(reg.nac);
}
int buscar_participante(int codigo_buscado){
    Participante reg;
    FILE *f;
    int pos=0;
    f = fopen("datos/participantes.dat", "rb");
    if (f == NULL){
        return -1;
    }
    while(fread(&reg, sizeof(Participante), 1, f)){
        if (codigo_buscado == reg.codigo){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}
Participante cargar_participante(){
    Participante a, *aux;
    aux = &a;

    int codigo, pos;
    cout << "Código   : ";
    cin >> codigo;
    while(!(codigo >= 1000 && codigo <= 9999)){
        cout << "> Código   : ";
        cin >> codigo;
    }

    // Validamos el código que no se repita en la lista
    while (buscar_participante(codigo) >= 0){
        cout << "> Código   : ";
        cin >> codigo;
    }
    // Fin de la validación de código
    aux->codigo = codigo;
    cout << "Apellidos: ";
    cin.ignore();
    cin.getline(aux->apellidos, 50);
    cout << "Nombres  : ";
    cin.getline(aux->nombres, 50);
    cout << "Género   : ";
    cin >> aux->genero;
    while (aux->genero != 'M' && aux->genero != 'F' && aux->genero != 'X'){
        cout << endl <<  "> Género   : " << aux->genero << endl;
        cin >> aux->genero;
    }
    cout << "Fecha de nacimiento: ";
    cin >> aux->nac.dia;
    cin >> aux->nac.mes;
    cin >> aux->nac.anio;

    aux->estado = true;

    return a;
}
void listar_participantes(){
    Participante reg;
    FILE *f;
    int aux;
    f = fopen("datos/participantes.dat", "rb");
    if (f == NULL){
        cout << "No se puede leer el archivo.";
        return;
    }
    while(fread(&reg, sizeof(Participante), 1, f)){
        mostrar_participante(reg);
        cout << endl;
    }
    fclose(f);
}
bool guardar_participante(Participante reg){
    bool grabo;
    FILE *f;
    f = fopen("datos/participantes.dat", "ab");
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&reg, sizeof(Participante), 1, f);
    fclose(f);
    return grabo;
}

























