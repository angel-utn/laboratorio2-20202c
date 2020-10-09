#include <iostream>
using namespace std;
#include "examen.h"

    Examen::Examen(){
        legajo = 0;
        nota = 2;
    }
    Examen::Examen(Fecha f){
        fechaExamen = f;
    }
    Examen::Examen(int d, int m, int a):fechaExamen(d, m, a){
        legajo = 1;
        nota = 10;
    }
    void  Examen::setLegajo(int l){
        legajo = l;
    }
    void  Examen::setNota(float n){
        nota = n;
    }
    void  Examen::setFecha(Fecha f){
        fechaExamen = f;
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
    }
    void  Examen::mostrar(){
        cout << "Legajo: " << legajo << endl;
        cout << "Nota  : " << nota << endl;
        cout << "Fecha : ";
        fechaExamen.mostrar();
        cout << endl;
    }
