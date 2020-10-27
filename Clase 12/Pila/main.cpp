#include <stack>
#include <iostream>
using namespace std;

int main(){
    stack <int> pila;
    /// Cargamos la pila
    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.push(40);
    pila.push(50);

    cout << "Vaciamos la pila y mostramos cada elemento" << endl;
    int i;
    while(!pila.empty()){
        cout << pila.top(); //Obtiene el elemento más reciente de la pila
        pila.pop(); //Quita cada elemento de manera LIFO
        cout << endl;
    }


    return 0;
}
