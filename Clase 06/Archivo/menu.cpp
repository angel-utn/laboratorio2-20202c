#include <iostream>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "menu.h"
#include "participante.h"

void menuPrincipal(){
    initUI();
    title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

    while(true){
        cls();
        title("MENÚ PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5);
        cout << "1 - PARTICIPANTES" << endl;
        cout << "2 - CAPTURAS" << endl;
        cout << "3 - REPORTES" << endl;
        cout << "4 - CONFIGURACIÓN" << endl;
        cout << "------------------" << endl;
        cout << "0 - SALIR" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                menuParticipantes();
            break;
            case 2:
                menuCapturas();
            break;
            case 3:
            break;
            case 4:
            break;
            case 0:
                return;
            break;
        }
    }
}

void menuParticipantes(){
    while(true){
        cls();
        title("MENÚ PARTICIPANTES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5);
        cout << "1 - NUEVO" << endl;
        cout << "2 - EDITAR" << endl;
        cout << "3 - LISTAR X ID" << endl;
        cout << "4 - LISTAR TODOS" << endl;
        cout << "------------------" << endl;
        cout << "0 - VOLVER" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                Participante reg;
                reg = cargar_participante();
                if (guardar_participante(reg)){
                    cout << "Participante registrado.";
                }
                else{
                    cout << "No se pudo registrar el participante.";
                }
            break;
            case 2:
                modificar_participante();
            break;
            case 3:
                listar_participante_x_id();
            break;
            case 4:
                listar_participantes();
            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
}

void menuCapturas() {
    while (true) {
        cls();
        title("MENÚ CAPTURAS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5);
        cout << "1 - NUEVA CAPTURA" << endl;
        cout << "2 - MODIFICAR CAPTURA" << endl;
        cout << "3 - LISTAR CAPTURA POR ID" << endl;
        cout << "4 - LISTAR TODAS LAS CAPTURAS (ORDENADAS x PESO) " << endl;
        cout << "------------------" << endl;
        cout << "0 - VOLVER" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch (pos) {
        case 1:
            msj("Presiona cualquier tecla para continuar.", rlutil::WHITE, rlutil::GREEN);
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 0:
                return;
            break;
        }
      
    }
}
