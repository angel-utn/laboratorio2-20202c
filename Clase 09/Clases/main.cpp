#include <iostream>
using namespace std;
#include <cstring>

class Auto{
    private:
        float velocidad;
        float velocidadMaxima;
        char patente[10];

    public:
        Auto();
        Auto(float);
        Auto(char *, float);
        ~Auto();
        void acelerar(float);
        float getVelocidad();
        char * getPatente();
        void setPatente(char *);
        void frenar();
};

void Auto::acelerar(float vel){
    if (vel > 0){
        velocidad += vel;
        if (velocidad > velocidadMaxima){
            velocidad = velocidadMaxima;
        }
    }
}
void Auto::frenar(){
    velocidad = 0;
}
float Auto::getVelocidad(){
    return velocidad;
}
char * Auto::getPatente(){
    return patente;
}
void Auto::setPatente(char *nuevaPatente){
    strcpy(patente, nuevaPatente);
}
Auto::Auto(){
    strcpy(patente, "");
    velocidad = 0;
    velocidadMaxima = 180;
}
Auto::Auto(float velmax){
    strcpy(patente, "");
    velocidad = 0;
    velocidadMaxima = velmax;
}
Auto::Auto(char *nuevaPatente, float velmax){
    strcpy(patente, nuevaPatente);
    velocidad = 0;
    velocidadMaxima = velmax;
}
Auto::~Auto(){
    cout << "Se destruyó el auto a " << velocidad << " km/h." << endl;
}

int main(){
    Auto coche("ANGEL001", 240);
    Auto coche2(230);

    cout << "Patente  : " << coche.getPatente() << endl;
    coche.acelerar(100);
    coche.acelerar(100);
    coche.acelerar(100);
    coche.acelerar(10);
    cout << "Velocidad: " << coche.getVelocidad() << endl;
    coche.frenar();
    cout << "Velocidad: " << coche.getVelocidad() << endl;


    return 0;
}
