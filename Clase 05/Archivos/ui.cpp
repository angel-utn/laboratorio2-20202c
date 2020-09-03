#include <iostream>
using namespace std;
#include <cstring>
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;

void setColors(int foreColor, int backColor){
    setColor(foreColor);
    setBackgroundColor(backColor);
}

void bar(int foreColor, int backColor, int y, int width){
    if (width > SCREEN_WIDTH)
        width = SCREEN_WIDTH;
    if (y > SCREEN_HEIGHT)
        y = SCREEN_HEIGHT;

    setColors(foreColor, backColor);
    for (int x=1; x<=width; x++){
        gotoxy(x, y);
        cout << " ";
    }
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
    resetColor();
}
void msj(const char *mensaje, int foreColor, int backColor, int y, Orientation o){
    bar(foreColor, backColor, y, SCREEN_WIDTH);
    setColors(foreColor, backColor);

    //TODO: Analizar la orientación
    gotoxy(1, y);
    cout << mensaje;
    cin.ignore();
    getch();
    resetColor();
    bar(APP_FORECOLOR, APP_BACKCOLOR, y, SCREEN_WIDTH);
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
void title(const char *mensaje, int foreColor, int backColor){
    bar(foreColor, backColor, 1, SCREEN_WIDTH);
    setColors(foreColor, backColor);
    int centro = (SCREEN_WIDTH - strlen(mensaje))/2;
    gotoxy(centro, 1);
    cout << mensaje;
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
void delline(int line, int foreColor, int backColor){
    setColors(foreColor, backColor);
    for(int x=0; x<=SCREEN_WIDTH; x++){
        gotoxy(x, line);
        cout << " ";
    }
    resetColor();
    setColors(APP_FORECOLOR, APP_BACKCOLOR);
}
