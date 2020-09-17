#include <iostream>
using namespace std;
#include <iomanip>
#include <cstdio>
#include "rlutil.h"
using namespace rlutil;
#include "ui.h"
#include "reportes.h"
#include "captura.h"
#include "participante.h"
/*
    Por cada tipo de especie, indicar la
    cantidad de peces capturados.
*/

void reporte1(){
    cls();
    int vespecies[10]={}, cant = cantidad_capturas();
    for(int i=0; i<cant; i++){
        Captura aux = leer_captura(i);
        vespecies[aux.especie-1]++;
    }
    title("--- CAPTURAS POR ESPECIE ----");
    cout << endl << endl << endl;
    cout << "ID\tCANTIDAD" << endl;
    for(int i=0; i<10; i++){
        cout << i+1 << "\t" << vespecies[i] << endl;
    }
}

void reporte1_B(){
    cls();
    int vespecies[10]={};
    FILE *p;
    p = fopen("datos/capturas.dat", "rb");
    if (p == NULL){
        return;
    }
    Captura aux;
    while(fread(&aux, sizeof(Captura), 1, p) == 1){
        vespecies[aux.especie-1]++;
    }
    fclose(p);

    title("CAPTURAS POR ESPECIE");
    cout << endl << endl << endl;
    cout << "ID\tCANTIDAD" << endl;
    for(int i=0; i<10; i++){
        cout << i+1 << "\t" << vespecies[i] << endl;
    }
}

void poner0(float *v, int t){
    for(int i=0;i<t; i++){
        v[i] = 0;
    }
}

void totalizar_capturas(float *vec){
    int cant = cantidad_capturas(), pos;
    for(int i=0; i<cant; i++){
        Captura aux = leer_captura(i);
        pos = buscar_participante(aux.idParticipante);
        vec[pos] += aux.peso;
    }
}
void podio(Participante *vpar, float *vkgs, int cant){

    int i, j, posmax;
    Participante aux1;
    float aux2;

    for(i=0; i<cant-1; i++){
        posmax = i;

        for(j=i+1; j<cant; j++){
            if (vkgs[j] > vkgs[posmax]){
                posmax = j;
            }
        }
        aux1 = vpar[i];
        aux2 = vkgs[i];
        vpar[i] = vpar[posmax];
        vkgs[i] = vkgs[posmax];
        vpar[posmax] = aux1;
        vkgs[posmax] = aux2;
    }
}
/*
Listar apellido, nombre, género y total de kilos del podio (top 3) de participantes
al finalizar la competencia. Los mejores se determinarán a partir de la
sumatoria de kilos de las especies capturadas.
*/
void reporte2(){
    cls();
    float *kgs;
    Participante *vec;
    int cant_participantes = cantidad_participantes();
    kgs = (float *) malloc(sizeof(float) * cant_participantes);
    if (kgs == NULL){
        return;
    }
    vec = (Participante *) malloc(sizeof(Participante) * cant_participantes);
    if (vec == NULL){
        free(kgs);
        return;
    }
    poner0(kgs, cant_participantes);
    if (leer_participantes(vec, cant_participantes) == cant_participantes){
        totalizar_capturas(kgs);
        podio(vec, kgs, cant_participantes);

        int i=0, c=0;
        cout << left;
        while(c<3){
            //cout << setw(15) << vec[i].apellidos << setw(15) << vec[i].nombres << setw(4) << kgs[i] << endl;

            if (vec[i].estado == true){
                c++;
                if (c == 1){
                    setColor(YELLOW);
                }
                else{
                    setColor(WHITE);
                }
                cout << "Puesto #" << c << endl;
                cout << vec[i].apellidos << endl;
                cout << vec[i].nombres << endl;
                cout << vec[i].genero << endl;
                cout << kgs[i] << endl;
                cout << endl;
            }
            i++;
        }
    }
    else{
        msj("Hubo un error al reportar.", APP_FORECOLOR, APP_ERRORCOLOR);
    }

    free(kgs);
    free(vec);
    return;
}
