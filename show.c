//
// Created by DongHoony on 2019-11-20.
//

#include "land.h"
#include "gotoyx.h"
#include <stdio.h>
#include <stdlib.h>
#include <wincon.h>
#include <winbase.h>

void show_set_cursor_disable(){
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
}

void show_land_info(Land l){

}
void show_gameboard(Land* gameboard){

}
void show_player_move(Land* gameboard, Player* p, int from, int to){
    int label = p->label;
    if (label == PLAYER){
        gotoyx_set_color(C_BLUE);
        gotoyx_print(gameboard[from].p_player.y, gameboard[from].p_player.x, "  ");
        gotoyx_print(gameboard[to].p_player.y, gameboard[to].p_player.x, "PL");
        gotoyx_set_color(C_WHITE);
    }
    else{
        gotoyx_set_color(C_RED);
        gotoyx_print(gameboard[from].p_bot.y, gameboard[from].p_bot.x, "  ");
        gotoyx_print(gameboard[to].p_bot.y, gameboard[to].p_bot.x, "PC");
        gotoyx_set_color(C_WHITE);
    }
}

void show_gameboard_grid(){
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //0
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //1
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //2
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //3
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //4
    printf("��                ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������                ��\n"); //5
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //6
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //7
    printf("��          ��     ��                                                                                                     ��     ��          ��\n"); //8
    printf("��          ��     ��   ������������������������������������������������                                               ������������������������������������������������   ��     ��          ��\n"); //9
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //10
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //11
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //12
    printf("������������������������������������   ��                      ��                                               ��                      ��   ������������������������������������\n"); //13
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //14
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //15
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //16
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //17
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //18
    printf("������������������������������������   ��                      ��                                               ��                      ��   ������������������������������������\n"); //19
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //20
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //21
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //22
    printf("��          ��     ��   ������������������������������������������������                                               ������������������������������������������������   ��     ��          ��\n"); //23
    printf("��          ��     ��                                                                                                     ��     ��          ��\n"); //24
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //25
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //26
    printf("��                ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������                ��\n"); //27
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //28
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //29
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //30
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //31
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //32
    // 17 Spaces per Block in row
}

void show_test_gameboard(Land* gameboard){
    int i, y, x;
    // need to simplify below
    for(i = 0; i < 22; i++){

        y = gameboard[i].p_player.y;
        x = gameboard[i].p_player.x;
        gotoyx_print(y, x, "PL");
        y = gameboard[i].p_bot.y;
        x = gameboard[i].p_bot.x;
        gotoyx_print(y, x, "PC");

        if (i == START_LAND || i == ABANDONED_ISLAND || i == TRAVEL || i == FESTIVAL) continue;

        y = gameboard[i].p_b1.y;
        x = gameboard[i].p_b1.x;
        gotoyx_print(y, x, "SS");
        y = gameboard[i].p_b2.y;
        x = gameboard[i].p_b2.x;
        gotoyx_print(y, x, "MM");
        y = gameboard[i].p_b3.y;
        x = gameboard[i].p_b3.x;
        gotoyx_print(y, x, "LL");
    }
    gotoyx(35, 0);
    system("pause");
}

int show_build_building(Land* gameboard, Player* p, int pos, int level){
    int label, i, color;
    Point building_pos[3] = {gameboard[pos].p_b1, gameboard[pos].p_b2, gameboard[pos].p_b3};
    char* building_str[3] = {"SS", "MM", "LL"};
    label = p->label;
    color = (label == PLAYER ? C_BLUE : C_RED);
    gotoyx_set_color(color);
    for(i = 0; i < level; i++){
        gotoyx_print(building_pos[i].y, building_pos[i].x, building_str[i]);
    }
    gotoyx_set_color(C_WHITE);
    return 0;
}