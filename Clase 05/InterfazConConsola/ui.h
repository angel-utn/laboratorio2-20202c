#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

#define APP_BACKCOLOR 8
#define APP_FORECOLOR 15
#define APP_TITLEBACKCOLOR 1
#define APP_TITLEFORECOLOR 15
#define APP_ERRORCOLOR 4
#define APP_OKCOLOR 2
#define APP_DELAY 1000

enum Orientation{
    TEXT_LEFT,
    TEXT_RIGHT,
    TEXT_CENTER
};
void setColors(int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
void bar(int foreColor, int backColor, int y=SCREEN_HEIGHT, int width=SCREEN_WIDTH);
void title(const char *mensaje, int foreColor = APP_TITLEFORECOLOR, int backColor = APP_TITLEBACKCOLOR);
void msj(const char *mensaje, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR, int y = SCREEN_HEIGHT, Orientation o = Orientation::TEXT_LEFT);
void delline(int line, int foreColor = APP_FORECOLOR, int backColor = APP_BACKCOLOR);
#endif // UI_H_INCLUDED
