#include <iostream>
using namespace std;

void cargar_vector(int *v, int tam){
    int i;
    cout <<"Ingresar valores: " << endl;
    for(i=0; i<tam; i++){
        cin >> v[i];
    }
}
void mostrar_vector(int *v, int tam){
    int *i;
    cout << endl << "Los valores ingresados fueron: " << endl;
    for(i=v; i<v+tam; i++){
        cout << *i << endl;
    }
}

int main(){
    int vec[5];
    cargar_vector(&vec[0], 5);
    mostrar_vector(vec, 5);

    return 0;
}
