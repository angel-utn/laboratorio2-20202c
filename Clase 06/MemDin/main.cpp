#include <iostream>
using namespace std;
#include <cstdlib>

int main()
{
    /*
        No se puede con la memoria stack
        int v[5000000];
    */
    int *v;
    int elementos;
    cout << "Cantidad de elementos del vector: ";
    cin >> elementos;
    v = (int *) malloc (elementos* sizeof(int));

    if (v == NULL){
        cout << "No hay memoria";
    }
    else{
        int i;
        for(i=0; i<elementos; i++){
            v[i] = i+1;
            cout << v[i] << ", ";
        }

        //cout << v[30000000] << endl;
    }
    free(v);
    return 0;
}
