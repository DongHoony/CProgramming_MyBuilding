#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>

void gotoyx(int y, int x){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    printf("┌──────────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┐\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("├──────────────────┼──────────────────┴──────────────────┴──────────────────┴──────────────────┴──────────────────┴──────────────────┼──────────────────┤\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("├──────────────────┤                                                                                                                 ├──────────────────┤\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("├──────────────────┤                                                                                                                 ├──────────────────┤\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("│                  │                                                                                                                 │                  │\n");
    printf("├──────────────────┼──────────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┬──────────────────┼──────────────────┤\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("│                  │                  │                  │                  │                  │                  │                  │                  │\n");
    printf("└──────────────────┴──────────────────┴──────────────────┴──────────────────┴──────────────────┴──────────────────┴──────────────────┴──────────────────┘\n");
    gotoyx(0, 0);
    getch();

}