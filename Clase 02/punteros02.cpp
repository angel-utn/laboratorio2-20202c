#include <iostream>
using namespace std;

void mi_funcion(int *a, int *b){
    *a = 1000;
    *b = 2000;
}

int main(){
    int n1, n2;
    n1 = 10;
    n2 = 20;
    mi_funcion(&n1, &n2);
    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;

    return 0;
}
