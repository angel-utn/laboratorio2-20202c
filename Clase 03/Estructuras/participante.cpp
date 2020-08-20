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
int buscar_participante(int codigo_buscado, Participante *lista, int tam){
    int i;
    for(i=0; i<tam; i++){
        if (codigo_buscado == lista[i].codigo){
            return i;
        }
    }
    return -1;
}
Participante cargar_participante(Participante *lista, int tam){
    Participante a, *aux;
    aux = &a;
    // Validamos el código que no se repita en la lista
    int codigo, pos;
    cout << "Código   : ";
    cin >> codigo;
    while(!(codigo >= 1000 && codigo <= 9999)){
        cout << "> Código   : ";
        cin >> codigo;
    }
    pos = buscar_participante(codigo, lista, tam);

    while (pos >= 0){
        cout << "> Código   : ";
        cin >> codigo;

        while(!(codigo >= 1000 && codigo <= 9999)){
        cout << "> Código   : ";
        cin >> codigo;
    }
        pos = buscar_participante(codigo, lista, tam);
    }
    // Ver de resolver con un do-while
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

    return a;
}

void cargar_lista_participantes(Participante *vec, int tam){
    int i;
    for(i=0; i<tam; i++){
        vec[i] = cargar_participante(vec, i);
        cout << endl;
    }
}
void mostrar_lista_participantes(Participante *vec, int tam){
    int i;
    cout << endl << endl;
    for(i=0; i<tam; i++){
        mostrar_participante(vec[i]);
        cout << "--------------------------------" << endl;
    }

}












