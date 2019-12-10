
#include <windows.h>
#include <stdio.h>

void gotoyx(int y, int x){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gotoyx_print(int y, int x, char* arg){
    gotoyx(y, x);
    printf("%s", arg);
}
void gotoyx_print_int(int y, int x, int n){
    gotoyx(y, x);
    printf("%d", n);
}
void gotoyx_set_color(int color){
    color &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (0xf & 0) | color);
}

