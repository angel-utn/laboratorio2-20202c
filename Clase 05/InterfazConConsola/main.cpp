#include <iostream>
using namespace std;
#include <cstdio>
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

int main(){
    title("UTN");;
    int n1, n2, n3;
    gotoxy(1, 5);
    cout << "Ingrese primer número: ";
    cin >> n1;
    while(n1 < 0){
        msj("Error: El número debe ser positivo", APP_FORECOLOR, APP_ERRORCOLOR);
        delline(5);
        gotoxy(1, 5);
        cout << "Ingrese primer número: ";
        cin >> n1;
    }
    gotoxy(1, 6);
    cout << "Ingrese segundo número: ";
    cin >> n2;
    while(n2 > 100){
        msj("Error: El número debe ser menor a 100", APP_FORECOLOR, APP_ERRORCOLOR);
        delline(6);
        gotoxy(1, 6);
        cout << "Ingrese segundo número: ";
        cin >> n2;
    }
    msj("Todo OK", APP_FORECOLOR, APP_OKCOLOR);


    return 0;
}
