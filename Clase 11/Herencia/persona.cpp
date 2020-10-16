#include <iostream>
using namespace std;
#include <cstring>
#include "persona.h"

        Persona::Persona(){
            edad = 0;
            strcpy(apenom, "NN");
        }
        int Persona::getEdad(){
            return edad;
        }
        char * Persona::getApenom(){
            return apenom;
        }
        void Persona::setEdad(int e){
            edad = e;
        }
        void Persona::setApenom(char *ap){
            strcpy(apenom, ap);
        }
        void Persona::cargar(){
            cout << "Edad: ";
            cin >> edad;
            cout << "Altura: ";
            cin >> altura;
            cout << "Apellido y nombres: ";
            cin >> apenom;

        }
        void Persona::mostrar(){
            cout << "Edad: " << edad << endl;
            cout << "Altura: " << altura << endl;
            cout << "Apellido y nombres: " << apenom << endl;
       }
