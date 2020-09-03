#include <iostream>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "participante.h"

const char *FILE_PARTICIPANTES = "datos/participantes.dat";

Participante leer_participante(int pos){
    Participante reg;
    FILE *p = fopen(FILE_PARTICIPANTES, "rb");
    if (p == NULL){
        reg.codigo = 0;
        return reg;
    }
    fseek(p, pos * sizeof(Participante), SEEK_SET);
    fread(&reg, sizeof(Participante), 1, p);
    fclose(p);
    return reg;
}

int cantidad_participantes(){
    FILE *p = fopen(FILE_PARTICIPANTES, "rb");
    if (p == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END); // SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Participante);
    return cant;
}

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
        return -2;
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
    cls();
    title("CARGA DE PARTICIPANTE NUEVO");
    gotoxy(1, 3);
    Participante a, *aux;
    aux = &a;
    int codigo, pos;
    bool validado;
    do{
        delline(3);
        gotoxy(1, 3);
        cout << "Código   : ";
        cin >> codigo;
        if (!(codigo >= 1000 && codigo <= 9999)){
            validado = false;
            msj("Código de participante incorrecto.", APP_FORECOLOR, APP_ERRORCOLOR);
        }
        else if(buscar_participante(codigo) >= 0){
            validado = false;
            msj("Código de participante repetido.", APP_FORECOLOR, APP_ERRORCOLOR);
        }
        else{
            validado = true;
        }
    }while(!validado);
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
bool modificar_participante(){
    cls();
    title("MODIFICAR PARTICIPANTE");
    gotoxy(1, 5);
    int codigo, pos;
    cout << "Código: ";
    cin >> codigo;
    pos = buscar_participante(codigo);
    if (pos >= 0){
        cout << endl << "Participante a modificar: " << endl;
        cout << "---------------------------" << endl;
        Participante reg = leer_participante(pos);
        mostrar_participante(reg);
        cout << endl;
        cout << "Nuevo nombre: ";
        cin.ignore();
        cin.getline(reg.nombres, 50);
        if (guardar_participante(reg, pos) == true){
            msj("Participante guardado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            return true;
        }
        else{
            msj("El participante no se guardó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            return true;

        }
    }
    else{
        msj("No existe el participante", 15, 3);
        return false;
    }
}

void listar_participante_x_id(){
    cls();
    title("LISTADO DE PARTICIPANTE x ID");
    gotoxy(1, 5);
    int codigo, pos;
    cout << "Código: ";
    cin >> codigo;
    pos = buscar_participante(codigo);
    if (pos >= 0){
        mostrar_participante(leer_participante(pos));
    }
    else{
        msj("No existe el participante", 15, 3);
    }
}
void listar_participantes(){
    cls();
    title("LISTADO DE PARTICIPANTES");
    gotoxy(1, 5);
    int cant =  cantidad_participantes();
    for(int i = 0; i<cant; i++){
        Participante reg = leer_participante(i);
        mostrar_participante(reg);
        cout << endl;
    }
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
bool guardar_participante(Participante reg, int pos){
    bool grabo;
    FILE *f;
    f = fopen(FILE_PARTICIPANTES, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f, pos * sizeof(Participante), SEEK_SET);
    grabo = fwrite(&reg, sizeof(Participante), 1, f);
    fclose(f);
    return grabo;
}
























