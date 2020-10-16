#include <iostream>
using namespace std;
#include "persona.h"
#include "alumno.h"

int main()
{
    Alumno obj;
    obj.cargar();
    cout << endl;
    obj.mostrar();

    return 0;
}
