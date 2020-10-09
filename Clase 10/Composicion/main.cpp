#include <iostream>
using namespace std;
#include "examen.h"

int main(){
    int vec[12]={};
    Examen e[5];
    int i;
    for(i=0; i<5; i++){
        e[i].cargar();
    }
    // Proceso de contabilización x mes
    for(i=0; i<5; i++){
        int mes = e.getFecha().getMes();
        vec[mes - 1]++;
    }
    cout << endl;
    cout << "Exámenes por mes: ";
    int i;
    for(i=0; i<12; i++){
        cout << "Mes " << i+1 << ": ";
        cout << vec[i] << endl;
    }


    return 0;
}
