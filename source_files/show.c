//
// Created by DongHoony on 2019-11-20.
//

#include <windows.h>
#include "../header_files/land.h"
#include "../header_files/gotoyx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include "../header_files/show.h"
#include "../header_files/money.h"
#include "../header_files/intro_1.h"

void show_set_cursor_disable(){
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);
}


void show_player_move(Land* gameboard, Player* p, int from, int to){
    int label = p->label;
    if (label == PLAYER){
        gotoyx_set_color(C_BLUE);
        gotoyx_print(gameboard[from].p_player.y, gameboard[from].p_player.x, "  ");
        gotoyx_print(gameboard[to].p_player.y, gameboard[to].p_player.x, "P1");
        gotoyx_set_color(C_WHITE);
    }
    else{
        gotoyx_set_color(C_RED);
        gotoyx_print(gameboard[from].p_bot.y, gameboard[from].p_bot.x, "  ");
        gotoyx_print(gameboard[to].p_bot.y, gameboard[to].p_bot.x, "P2");
        gotoyx_set_color(C_WHITE);
    }
}

void show_gameboard_grid(){
    gotoyx(0, 0);
    gotoyx_set_color(C_WHITE);
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //0
    printf("�� MUINDO         ��        +       ��        +       ��        +       ��        +       ��        +       ��        +       �� FESTIVAL       ��\n"); //1
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //2
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //3
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //4
    printf("��                ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������                ��\n"); //5
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //6
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //7
    printf("��          ��     ��                                                                                                     ��     ��          ��\n"); //8
    printf("��          ��     ��   ������������������������������������������������                                               ������������������������������������������������   ��     ��          ��\n"); //9
    printf("�� +        ��     ��   ��     P L A Y E R 1    ��               T U R N  :                      ��     P L A Y E R 2    ��   ��     ��         +��\n"); //10
    printf("��          ��     ��   ��                      ��               TURN LEFT:                      ��                      ��   ��     ��          ��\n"); //11
    printf("��          ��     ��   ��                      ��               FEST MULT:     --               ��                      ��   ��     ��          ��\n"); //12
    printf("������������������������������������   ��                      ��                                               ��                      ��   ������������������������������������\n"); //13
    printf("��                ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //14
    printf("��                ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //15
    printf("�� M I N I G A M E��   ��                      ��                                               ��                      ��   ��     ��         +��\n"); //16
    printf("��                ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //17
    printf("��                ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //18
    printf("������������������������������������   ��                      ��                                               ��                      ��   ������������������������������������\n"); //19
    printf("��          ��     ��   ��  LAP :               ��                                               ��  LAP :               ��   ��     ��          ��\n"); //20
    printf("��          ��     ��   ��                      ��                                               ��                      ��   ��     ��          ��\n"); //21
    printf("�� +        ��     ��   ��  MONEY :             ��                                               ��  MONEY :             ��   ��     ��         +��\n"); //22
    printf("��          ��     ��   ������������������������������������������������                                               ������������������������������������������������   ��     ��          ��\n"); //23
    printf("��          ��     ��                                                                                                     ��     ��          ��\n"); //24
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //25
    printf("�� START          ��                ��                ��                ��                ��                ��                �� TRAVEL         ��\n"); //26
    printf("��                ��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������                ��\n"); //27
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //28
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //29
    printf("��                ��                ��                ��                ��                ��                ��                ��                ��\n"); //30
    printf("��                ��        +       ��        +       ��        +       ��        +       ��        +       ��        +       ��                ��\n"); //31
    printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"); //32
    // 17 Spaces per Block in row
}


int show_landmark_satisfy(int* arr){
    int i;
    for(i = 0; i < 4; i++){
        if (arr[i] != 1) return NOT_OK;
    }
    return OK;
}

void show_update_predict_price(Player* p, int predict_price){
    gotoyx_print(20, 68, "          ");
    gotoyx_set_color((money_compare(p->money, predict_price) == OK) ? C_CYAN : C_RED);
    gotoyx_print_int(20, 68, predict_price);
    gotoyx_set_color(C_WHITE);
}

int show_predict_price(Land* land, Player* p, int* selected_building, int now_price, int cur){
    const int MULTIPLY[5] = {10, 12, 15, 17, 20};
    int predict_price = now_price;
    predict_price += (land->land_price * MULTIPLY[cur] * ((selected_building[cur] == 1) ? 1 : -1)) / 10;
    show_update_predict_price(p, predict_price);
    return predict_price;
}

int show_predict_price_with_cur_zero(Land* land, Player* p, int* selected_building){
    const int X_COR[] = {53, 60, 67, 74, 81};
    int i;
    if (selected_building[0] == 0 && land->level[0] == 0){
        gotoyx_set_color(C_RED);
        for(i = 1; i < 5; i++){
            gotoyx_print(21, X_COR[i], " XX ");
            selected_building[i] = -1;
        }
        gotoyx_set_color(C_WHITE);
        show_update_predict_price(p, 0);
        return 0;
    }
    gotoyx_set_color(C_YELLOW);
    gotoyx_print(21, X_COR[0], " VV ");
    selected_building[0] = 1;
    for(i = 1; i < 4; i++) {
        if (i > p->lap){
            gotoyx_set_color(C_RED);
            gotoyx_print(21, X_COR[i], " XX ");
            selected_building[i] = -1;
        }
        else{
            gotoyx_set_color(C_GREEN);
            gotoyx_print(21, X_COR[i], " -- ");
            selected_building[i] = 0;
        }
        gotoyx_set_color(C_WHITE);
    }
    show_update_predict_price(p, land->land_price);
    return land->land_price;
}

int* show_choice_building(Land* land, Player* p){
    const int X_COR[] = {53, 60, 67, 74, 81};
    const char* STR_SET[] = {"LAND", "VILA", "BLDG", "HTEL", "LMRK"};
    const int CUR_MAX = 4;
    int lap = p->lap;
    int i, cur = 0;
    int key;
    int* selected_building;
    int valid_check, predict_price = 0;
    selected_building = (int*) malloc(sizeof(int) * 5);
    memset(selected_building, 0x0, _msize(selected_building));

    gotoyx_set_color(C_GREEN);
    gotoyx_print(18, 50, "��������������������������������������������������������������������������");
    gotoyx_print(19, 50, "��         SELECT BUILDING.          ��");
    gotoyx_print(20, 50, "��          COST :                   ��");
    gotoyx_print(21, 50, "��   --     --     --     --     --  ��");
    gotoyx_print(22, 50, "��  LAND   VILA   BLDG   HTEL   LMRK ��");
    gotoyx_print(23, 50, "��������������������������������������������������������������������������");

    valid_check = show_landmark_satisfy(land->level);
    for(i = 0; i < 5; i++){
        if (i > lap){
            gotoyx_set_color(C_RED);
            gotoyx_print(21, X_COR[i], " XX ");
            selected_building[i] = -1;
        }
        else if (land->level[i] == 1){
            gotoyx_set_color(C_BLUE);
            gotoyx_print(21, X_COR[i], " OK ");
            selected_building[i] = -1;
        }
        if ((i == 4 && valid_check == NOT_OK) || (i != 4 && i > 0 && selected_building[0] == 0 && land->level[i] == 0)){
            gotoyx_set_color(C_RED);
            gotoyx_print(21, X_COR[i], " XX ");
            selected_building[i] = -1;
        }
    }
    gotoyx_set_color(C_CYAN);

    gotoyx_print(22, X_COR[cur], STR_SET[cur]);

    while(1){
        key = getch();
        if (key == KEY_ENTER) {
            if (money_compare(p->money, predict_price) == OK) break;
        }
        if (key == KEY_INTRO || key == KEY_SPACE){
            if (key == KEY_INTRO) key = getch();
            gotoyx_set_color(C_GREEN);
            switch(key){
                case KEY_RIGHT:
                case KEY_LEFT:
                    gotoyx_print(22, X_COR[cur], STR_SET[cur]);
                    if (key == KEY_RIGHT) cur = (cur == CUR_MAX) ? 0 : cur + 1;
                    else cur = (cur == 0) ? CUR_MAX : cur - 1;
                    gotoyx_set_color(C_CYAN);
                    gotoyx_print(22, X_COR[cur], STR_SET[cur]);
                    break;

                case KEY_SPACE:
                    if(selected_building[cur] == -1) continue;
                    selected_building[cur] = (selected_building[cur] == 1) ? 0 : 1;

                    //print predicted price
                    if (cur == 0) predict_price = show_predict_price_with_cur_zero(land, p, selected_building);
                    else predict_price = show_predict_price(land, p, selected_building, predict_price, cur);

                    gotoyx_set_color(selected_building[cur] == 1 ? C_YELLOW : C_GREEN);
                    gotoyx_print(21, X_COR[cur], selected_building[cur] == 1 ? " VV " : " -- ");
                    break;
            }
        }
    }
    gotoyx_set_color(C_WHITE);
    for(i = 0; i < 6; i++){
        gotoyx_print(18+i, 50, "                                     ");
    }
    return selected_building;
}

void show_dice_roll(int dice_v1, int dice_v2){
    const char* Y[6] = {NULL, " 1 ", " 2 ", " 3 ", " 4 ", " 5 "};
    const int DICEY = 14;
    const int DICEX[2] = {63, 73};
    int k;
    int rand1, rand2;
    for(k = 20; k < 50; k++){
        rand1 = rand() % 5 + 1;
        rand2 = rand() % 5 + 1;
        gotoyx_print(DICEY, DICEX[0], Y[rand1]);
        gotoyx_print(DICEY, DICEX[1], Y[rand2]);
        _sleep(k);
    }
    gotoyx_print(DICEY, DICEX[0], Y[dice_v1]);
    gotoyx_print(DICEY, DICEX[1], Y[dice_v2]);
}

void show_dice_grid(){
    int i, x = 10;
    gotoyx_set_color(C_CYAN);
    for(i = 0; i < 2; i++){
        gotoyx_print(13, 60 + i*x, "��������������");
        gotoyx_print(14, 60 + i*x, "��     ��");
        gotoyx_print(15, 60 + i*x, "��������������");
    }
    gotoyx_set_color(C_WHITE);
}

void show_money_update(Player* p, int is_increase){
    gotoyx_set_color((is_increase == TRUE) ? C_GREEN : C_RED);
    show_money_normal_update(p);
    gotoyx_set_color(C_WHITE);
}

void show_money_normal_update(Player* p){
    int label = p->label;
    const int X_POS[3] = {NULL, 32, 103};
    gotoyx_print(22, X_POS[label], "       ");
    gotoyx(22, X_POS[label]);
    printf("%7d", p->money);
}

void show_lap_update(Player* p){
    const int Y = 20;
    const int X[] = {30, 101};
    int label = p->label;
    gotoyx(Y, X[(label == COMPUTER) ? 1 : 0]);
    printf("%3d", p->lap);
}
void show_init_update(Player* p1, Player* p2){

    show_lap_update(p1);
    show_lap_update(p2);
    show_money_normal_update(p1);
    show_money_normal_update(p2);
    gotoyx(0, 0);
}


void show_travel_selected_highlight(Land* gameboard, int cur, int is_highlight, int is_clear){
    int y, x;
    if (cur == TRAVEL) return;
    y = (gameboard[cur].p_player.y + gameboard[cur].p_bot.y) / 2;
    x = (gameboard[cur].p_player.x + gameboard[cur].p_bot.x) / 2;
    gotoyx_set_color((is_highlight == TRUE) ? C_GREEN : C_YELLOW);
    if (is_clear == TRUE) gotoyx_print(y, x, "  ");
    else gotoyx_print_int(y, x, cur);
    gotoyx_set_color(C_GREEN);
}

int show_travel_choice(Land* gameboard){
    int key, cur = 0, i;
    gotoyx_set_color(C_GREEN);
    gotoyx_print(18, 50, "��������������������������������������������������������������������������");
    gotoyx_print(19, 50, "��       SELECT LAND TO TRAVEL       ��");
    gotoyx_print(20, 50, "��                                   ��");
    gotoyx_print(21, 50, "��  LAND NUMBER :                    ��");
    gotoyx_print(22, 50, "��                                   ��");
    gotoyx_print(23, 50, "��������������������������������������������������������������������������");
    for(i = 0; i < MAX_TILE; i++) show_travel_selected_highlight(gameboard, i, FALSE, FALSE);
    gotoyx(21, 67);
    printf("%02d", cur);
    while(1){
        key = getch();
        if (key == KEY_ENTER) break;
        if (key == KEY_INTRO){
            key = getch();
            switch(key){
                case KEY_DOWN:
                case KEY_UP:
                    show_travel_selected_highlight(gameboard, cur, FALSE, FALSE);
                    if (key == KEY_DOWN) {
                        if (cur == 0) cur = MAX_TILE - 1;
                        else if (cur == TRAVEL + 1) cur = TRAVEL - 1;
                        else cur -= 1;
                    }
                    else {
                        if (cur == MAX_TILE - 1) cur = 0;
                        else if (cur == TRAVEL - 1) cur = TRAVEL + 1;
                        else cur += 1;
                    }
                    gotoyx(21, 67);
                    printf("%02d", cur);
                    show_travel_selected_highlight(gameboard, cur, TRUE, FALSE);
                    gotoyx_print(22, 60, "                          ");
                    gotoyx(22, 60);
                    printf("%25s", gameboard[cur].name);
            }
        }
    }
    for(i = 0; i < MAX_TILE; i++) show_travel_selected_highlight(gameboard, i, FALSE, TRUE);
    for(i = 0; i < 6; i++) gotoyx_print(18+i, 50, "                                     ");
    return cur;
}

void show_turn_update(int turn, int label){
    turn /= 2;
    gotoyx(10, 70);
    gotoyx_set_color(label == PLAYER ? C_GREEN : C_RED);
    printf("%7s", label == PLAYER ? "P1" : "P2");
    gotoyx_set_color(C_GREEN);
    gotoyx(11, 70);
    printf("%7d", turn);
    gotoyx_set_color(C_WHITE);
    return;
}

void show_dice_big_size(int sum){
    int i, digit1, digit2;
    int x = 62;
    const char* num0[] = {"  ___  ",  " __ ", " ___  ",  " ____  ", " _  _   ", " _____ ", "   __  ",  " ______ ",  "  ___  ", "  ___  "};
    const char* num1[] = {" / _ \\ ","/_ |", "|__ \\ ", "|___ \\ ", "| || |  ", "| ____|", "  / /  ",  "|____  |",  " / _ \\ "," / _ \\ "};
    const char* num2[] = {"| | | |",  " | |", "   ) |",  "  __) |", "| || |_ ", "| |__  ", " / /_  ",  "    / / ",  "| (_) |" ,"| (_) |"};
    const char* num3[] = {"| | | |",  " | |", "  / / ",  " |__ < ", "|__   _|", "|___ \\ ","| '_ \\ ", "   / /  "  ," > _ < ", " \\__, |"};
    const char* num4[] = {"| |_| |",  " | |", " / /_ ",  " ___) |", "   | |  ", " ___) |", "| (_) |",  "  / /   "  ,"| (_) |", "   / / "};
    const char* num5[] = {" \\___/ ", " |_|", "|____|",  "|____/ ", "   |_|  ", "|____/ ", " \\___/ ", " /_/    "  ," \\___/ ","  /_/  "};
    const char** nums[] = {num0, num1, num2, num3, num4, num5};
    digit1 = sum / 10;
    digit2 = sum % 10;

    if (sum != 10) x -= 3;
    for(i = 0; i < 6; i++){
        gotoyx_print(16+i, 62, "                             ");
        if(sum == 10) gotoyx_print(16+i, x, nums[i][digit1]);
        gotoyx_print(16+i, x+7, nums[i][digit2]);
    }
    _sleep(800);
    for(i = 0;i < 6; i++){
        gotoyx_print(16+i, x, "                             ");
    }
}

void show_winner(int winner){
    gotoyx(36,0);
    if(winner == PLAYER) printf("PLAYER1 WINS!");
    else printf("PLAYER2 WINS");
    gotoyx(35, 0);
    getch();
}

void show_festival(Land* land_before, Land* land_after){
    if (land_after->land_position == START_LAND) return;
    int y_before, x_before, y_after, x_after;
    if (land_before->land_position != START_LAND){
        y_before = land_before->p_land.y;
        x_before = land_before->p_land.x;
    }
    x_after = land_after->p_land.x;
    y_after = land_after->p_land.y;
    gotoyx(34, 50);
    if (land_before->land_position != START_LAND){
        gotoyx_set_color((land_before->label == COMPUTER) ? C_RED : C_BLUE);
        gotoyx_print(y_before, x_before, "+");
    }
    gotoyx_set_color(C_GREEN);
    gotoyx_print(y_after, x_after, "+");

    gotoyx(12, 71);
    if (land_after->land_position != START_LAND) printf("%5dx", land_after->land_multiply);
    gotoyx_set_color(C_WHITE);
}

char show_window_init(Land* gameboard, Player* user, Player* bot){
    HWND hwnd = GetConsoleWindow();
    char key;
    system("cls");

    gotoyx_print(15, 20, "SET WINDOW SIZE MAXIMUM, SET FONT TO RASTER FONT");
    gotoyx_print(18, 20, "INPUT ANY KEY TO CONTINUE...");
    key = getch();
    system("cls");
    if (hwnd != NULL) MoveWindow(hwnd, 0, 0, 1430, 950, TRUE);
    show_set_cursor_disable();
    intro();
    show_gameboard_grid();
    show_dice_grid();
	play_intro_3();
    show_player_move(gameboard, user, 0, 0);
    show_player_move(gameboard, bot, 0, 0);
    show_init_update(user, bot);
    return key;
}

void show_land_building_residents(Land* land, int level, int book_people){
    const char* STR[5] = {"T", "S", "M", "L", "LMRK"};
    int x_pos[5] = {NULL, land->p_b1.x, land->p_b2.x, land->p_b3.x, land->p_b1.x-1};
    int y_pos[5] = {NULL, land->p_b1.y, land->p_b2.y, land->p_b3.y, land->p_b1.y};
    gotoyx_print(y_pos[level], x_pos[level], STR[level]);
    gotoyx_print_int(y_pos[level], x_pos[level] + 1, book_people);
}

void show_land_building_landmark_residents(Land* land, int book_people){
    gotoyx_print(land->p_b1.y, land->p_b1.x, "  ");
    gotoyx_print(land->p_b2.y, land->p_b2.x, "  ");
    gotoyx_print(land->p_b3.y, land->p_b3.x, "  ");
    gotoyx_print(land->p_b1.y, land->p_b1.x-1, "LMRK");
    gotoyx(land->p_b3.y, land->p_b3.x);
    printf("%2d", book_people);
    gotoyx_set_color(C_YELLOW);
    gotoyx_print(land->p_b2.y, land->p_b2.x, "��");
}

void show_land_building_only_land(Land* land, Player* p){
    gotoyx_set_color(p->label == PLAYER ? C_BLUE : C_RED);
    gotoyx_print(land->p_land.y, land->p_land.x, "+");
}