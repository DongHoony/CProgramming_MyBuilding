#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "show.h"
#include "player.h"
#include "gotoyx.h"
#include "file.h"
#include "cycle.h"

int main() {
    // !!! 선 언 먼 저 합 니 다 , srand도 함 수 니 까 선 언 다 음 에 하 세 요 !!!
    Land *gameboard;
    Player user = {200000, 15, "", PLAYER, 5};
    Player bot = {2000, 0, "", COMPUTER, 0};
	Resident resident = { {0},{0},{0} };

    show_set_cursor_disable();
    srand((unsigned) time(NULL));

    // make_user_name보다는 그냥 한번에 setting해주는 함수로 짜는 게 나을듯, 위에 100, 0, "",
    // PLAYER 넣어주는 걸로 (단, 세세히 모듈화)
    make_user_name(&user);
    gameboard = (Land *) file_get_land_info();

    // Check gameboard is successfully attatched
    if (gameboard == NULL) {
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }
    file_get_land_pos(&gameboard);
    system("cls");

    // Showing initialization
    show_gameboard_grid();
    show_dice_grid();
    resident_init(&resident);
    show_player_move(gameboard, &user, user.position, user.position);
    show_player_move(gameboard, &bot, bot.position, bot.position);

    /*
//    test code below
//    gameboard[20].level[0] = 1;
//    gameboard[20].level[1] = 1;
//    gameboard[20].level[2] = 1;
//    gameboard[20].level[3] = 1;
//    gameboard[20].level[4] = 1;
//    show_choice_building(&gameboard[20], &user);

//    show_test_gameboard(gameboard);

//    for(i = 0; i < 22; i++){
//        if (gameboard[i].land_type == SPECIAL_TYPE) continue;
//        show_build_building(gameboard, (rand()%2 == 1) ? &user : &bot, i, 3);
//    }

//  animation test
//    for(i = 0; i < 21; i++){
//        show_player_move(gameboard, &user, i, i+1);
//        _sleep(200);
//        show_player_move(gameboard, &bot, i, i+1);
//        _sleep(200);
//    }
     */
    while(1){
        gotoyx_print(34, 0,"              ");
        cycle(gameboard, &user, &resident);
        gotoyx(33, 10);
    }

    gotoyx(35, 0);
    system("pause");
}

