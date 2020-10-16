#include <iostream>
using namespace std;
#include "alumno.h"

    Alumno::Alumno(){
        legajo = 0;
    }
    void Alumno::setLegajo(int l){
        legajo = l;
    }
    int Alumno::getLegajo(){
        return legajo;
    }
    void Alumno::cargar(){
        Persona::cargar();
        cout << "Legajo : ";
        cin >> legajo;
    }
    void Alumno::mostrar(){
        Persona::mostrar();
        cout << "Legajo : " << legajo << endl;
    }
