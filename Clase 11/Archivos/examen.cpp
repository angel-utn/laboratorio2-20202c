#include <iostream>
using namespace std;
#include "examen.h"
#include <cstdio>
#include <iomanip>

    Examen::Examen(){
        legajo = 0;
        nota = 0;
        tipo = 0;
    }
    void  Examen::setLegajo(int legajo){
        this->legajo = legajo;
    }
    void  Examen::setNota(float n){
        nota = n;
    }
    void  Examen::setFecha(Fecha f){
        fechaExamen = f;
    }
    void Examen::setTipo(int t){
        tipo = t;
    }
    int Examen::getTipo(){
        return tipo;
    }
    int   Examen::getLegajo(){
        return legajo;
    }
    float Examen::getNota(){
        return nota;
    }
    Fecha Examen::getFecha(){
        return fechaExamen;
    }
    void  Examen::cargar(){
        cout << "Legajo: ";
        cin >> legajo;
        cout << "Nota: ";
        cin >> nota;
        cout << "Fecha: ";
        /*int dia, mes, anio;
        cin >> dia >> mes >> anio;
        fechaExamen.setDia(dia);
        fechaExamen.setMes(mes);
        fechaExamen.setAnio(anio);*/
        fechaExamen.cargar();
        cout << "Tipo: ";
        cin >> tipo;
    }
    void  Examen::mostrar(){
        cout << "Legajo: " << legajo << endl;
        cout << "Nota  : " << nota << endl;
        cout << "Fecha : ";
        fechaExamen.mostrar();
        cout << endl;
        cout << "Tipo  : " << tipo << endl;
    }
    bool Examen::guardarEnDisco(int posicion){
        bool grabo;
        FILE *p;
        if (posicion == -1){
            p = fopen("examenes.dat", "ab");
            if (p == NULL){
                return false;
            }
        }
        else{
            p = fopen("examenes.dat", "rb+");
            if (p == NULL){
                return false;
            }
            fseek(p, posicion * sizeof(Examen), 0);
        }
        grabo = fwrite(this, sizeof(Examen), 1, p);
        fclose(p);
        return grabo;
    }
    bool Examen::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen("examenes.dat", "rb");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof(Examen), 0);
        leyo = fread(this, sizeof(Examen), 1, p);
        fclose(p);
        return leyo;
    }

    void listado_examenes(){
        Examen aux;
        int i = 0;
        cout << left;
        cout << setw(12) << "FECHA" << setw(8) << "LEGAJO" << setw(6) << "NOTA" << setw(15) << "TIPO" << endl;
        while (aux.leerDeDisco(i++)){
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFecha().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << aux.getFecha().getMes();
            cout << "/";
            cout << setw(6);
            cout << aux.getFecha().getAnio();

            cout << setw(8);
            cout << aux.getLegajo();
            cout << setw(6);
            cout << aux.getNota();
            cout << setw(15);
            switch(aux.getTipo()){
                case 1:
                    cout << "Parcial";
                break;
                case 2:
                    cout << "Trabajo práctico";
                break;
                case 3:
                    cout << "Final";
                break;
            }
            cout << endl;
        }
    }








