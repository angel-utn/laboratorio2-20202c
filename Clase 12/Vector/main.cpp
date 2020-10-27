#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

class Alumno{
    private:
    int legajo;
    char apenom[50];

    public:
        void cargar(){
            cout << "> Legajo: ";
            cin >> this->legajo;
            cout << "> Apellido y nombre: ";
            cin.ignore();
            cin.getline(this->apenom, 50);
        }
        void mostrar(){
            cout << "Legajo: " << legajo << endl;
            cout << "Apellido y nombre: " << apenom << endl;
        }
};

int main(){
    int i;
    vector <int> vnum; // Declaración de un vector de enteros
    vnum.push_back(10);
    vnum.push_back(50);
    vnum.push_back(70);
    vnum.push_back(80);
    cout << "Listado del vector de números:  "<< endl;
    for(i=0; i<vnum.size(); i++){
        cout << vnum.at(i) << " ";
    }
    cout << endl << endl << "Carga de alumnos: " << endl;
    vector <Alumno> valumnos;
    /// Cargarmos tres alumnos en el vector
    for(i=1; i<=3; i++){
        cout << "Alumno #" << i << endl;
        Alumno aux;
        aux.cargar();
        valumnos.push_back(aux);
    }
    cout << endl << endl;
    cout << "Listado del vector de alumnos:  "<< endl;
    for(i=0; i<valumnos.size(); i++){
        valumnos.at(i).mostrar();
    }



    return 0;
}
