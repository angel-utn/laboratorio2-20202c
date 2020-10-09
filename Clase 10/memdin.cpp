#include <iostream>
using namespace std;

class Fecha{
    private:
    int dia, mes, anio;

    public:
        Fecha(int=0, int=0, int=0);
        void mostrar();
};

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}
void Fecha::mostrar(){
    cout << dia << "/" << mes << "/" << anio;
}

int main(){
    int cant;
    cout << "Cantidad de fechas a crear: ";
    cin >> cant;
    Fecha *vec = new Fecha[cant];
    int i;
    for(i=0; i<cant; i++){
        cout << "Fecha #" << i+1 << ": ";
        vec[i].mostrar();
        cout << endl;
    }
    delete vec;
    cout << endl << endl;
    /* Otro ejemplo con int */
    int *p;
    cout << "Cantidad de enteros a crear: ";
    cin >> cant;
    p = new int[cant];
    for(i=0; i<cant; i++){
        p[i] = i+1;
        cout << p[i] << endl;
    }
    delete p;



    return 0;
}
