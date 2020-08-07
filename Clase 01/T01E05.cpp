#include <iostream>
using namespace std;

void cargar_datos(float *, float *, float *);
void puntoA(float *, float *, float *);
void puntoB(float *, float *, float *);
void puntoC(float *, float *, float *);

int main(){
    float pais1[31]={}, pais2[31]={}, pais3[31]={};

    cargar_datos(pais1, pais2, pais3);

    puntoA(pais1, pais2, pais3);
    puntoB(pais1, pais2, pais3);
    puntoC(pais1, pais2, pais3);

    return 0;
}

void cargar_datos(float *p1, float *p2, float *p3){
    int pais, dia;
    float monto;

    cout << "Número de país: ";
    cin >> pais;
    while (pais != -1){
        cout << "Día: ";
        cin >> dia;
        cout << "Monto: $ ";
        cin >> monto;

        switch(pais){
            case 1:
                p1[dia-1] += monto;
            break;
            case 2:
                p2[dia-1] += monto;
            break;
            case 3:
                p3[dia-1] += monto;
            break;
        }

        cout << "Número de país: ";
        cin >> pais;
    }
}

void puntoA(float p1[], float p2[], float p3[]){
    cout << "PUNTO A" << endl << "---------------" << endl;
    int i;
    cout << endl << "País 1" << endl;
    for(i=0; i<31; i++){
        if(p1[i] > 0){
            cout << "Día " << i+1 << ": $ " << p1[i] << endl;
        }
    }
    cout << endl << "País 2" << endl;
    for(i=0; i<31; i++){
        if(p2[i] > 0){
            cout << "Día " << i+1 << ": $ " << p2[i] << endl;
        }
    }
    cout << endl << "País 3" << endl;
    for(i=0; i<31; i++){
        if(p3[i] > 0){
            cout << "Día " << i+1 << ": $ " << p3[i] << endl;
        }
    }
}

int contar(float v[], int tam, float valor){
    int c=0, i;
    for(i=0; i<tam; i++){
        if (v[i] == valor){
            c++;
        }
    }
    return c;
}

void puntoB(float p1[], float p2[], float p3[]){
    int cant;
    cout << endl << "PUNTO B" << endl << "---------------" << endl;

    cant = contar(p1, 31, 0);
    cout << "País 1 - Días sin recaudación: " << cant << endl;

    cant = contar(p2, 31, 0);
    cout << "País 2 - Días sin recaudación: " << cant << endl;

    cant = contar(p3, 31, 0);
    cout << "País 3 - Días sin recaudación: " << cant << endl;
}

void puntoC(float p1[], float p2[], float p3[]){
    int i;
    cout << endl << "PUNTO C" << endl << "---------------" << endl;
    for(i=0; i<31; i++){
        if (p1[i] == 0 && p2[i] == 0 && p3[i] == 0){
            cout << i+1 << endl;
        }
    }
}
