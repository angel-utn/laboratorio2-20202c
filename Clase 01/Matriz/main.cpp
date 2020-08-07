#include <iostream>
using namespace std;

void cargar_datos(float [][3]);
void puntoA(float [][3]);
void puntoB(float [][3]);
void puntoC(float [][3]);

int main(){
    float recaudacion[31][3]={};
    cargar_datos(recaudacion);

    puntoA(recaudacion);
    puntoB(recaudacion);
    puntoC(recaudacion);
    return 0;
}

void cargar_datos(float m[][3]){
    int pais, dia;
    float monto;

    cout << "Número de país: ";
    cin >> pais;
    while (pais != -1){
        cout << "Día: ";
        cin >> dia;
        cout << "Monto: $ ";
        cin >> monto;

        m[dia-1][pais-1]+= monto;

        cout << "Número de país: ";
        cin >> pais;
    }
}

void puntoA(float m[][3]){
    cout << "PUNTO A" << endl << "---------------" << endl;
    int i, j;
    for(i=0; i<3; i++){
        cout << "País " << i+1 << endl;
        for(j=0; j<31; j++){
            if(m[j][i] != 0){
                cout << "Día " << j+1 << ": $";
                cout << m[j][i] << endl;
            }
        }
        cout << endl;
    }

    /*cout << endl << "País 1" << endl;
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
    }*/
}
/*
int contar(float v[], int tam, float valor){
    int c=0, i;
    for(i=0; i<tam; i++){
        if (v[i] == valor){
            c++;
        }
    }
    return c;
}
*/
void puntoB(float m[][3]){
    int cant, i, j;
    cout << endl << "PUNTO B" << endl << "---------------" << endl;

    for(i=0; i<3; i++){
        cant = 0;
        for(j=0; j<31; j++){
            if (m[j][i] == 0){
                cant++;
            }
        }
        cout << "País " << i+1 << " - Días sin recaudación: " << cant << endl;
    }
}
void puntoC(float m[][3]){
    int i, j;
    cout << endl << "PUNTO C" << endl << "---------------" << endl;
    bool recaudo;
    for(i=0; i<31; i++){
        recaudo = false;
        for(j=0; j<3; j++){
            if (m[i][j] > 0){
                recaudo = true;
            }
        }
        if (recaudo == false){
            cout << i+1 << " ";
        }
    }
}
