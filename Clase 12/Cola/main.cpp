#include <queue>
#include <iostream>
using namespace std;

int main(){
    queue <int> cola;
    /// Cargamos la cola
    cola.push(10);
    cola.push(20);
    cola.push(30);
    cola.push(40);
    cola.push(50);

    cout << "Vaciamos la cola y mostramos cada elemento" << endl;
    int i;
    while(!cola.empty()){
        cout << cola.front(); //Obtiene el elemento más antiguo de la cola
        cola.pop(); //Quita cada elemento de manera FIFO
        cout << endl;
    }


    return 0;
}
