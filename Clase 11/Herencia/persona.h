#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona{
    protected:
        int edad;
        char apenom[50];
        float altura;
    public:
        Persona();
        int getEdad();
        char * getApenom();
        void setEdad(int);
        void setApenom(char *);
        void cargar();
        void mostrar();
};

#endif // PERSONA_H_INCLUDED
