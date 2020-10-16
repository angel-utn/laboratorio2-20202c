#include <iostream>
using namespace std;
#include "fecha.h"

 Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
void Fecha::setDia(int d){
    dia = d;
}
void Fecha::setMes(int m){
    mes = m;
}
void Fecha::setAnio(int a){
    anio = a;
}
void Fecha::mostrar(){
    cout << dia << "/" << mes << "/" << anio;
}
void Fecha::cargar(){
    cout << "Día: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;
}



