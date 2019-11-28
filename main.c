#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "show.h"
#include "player.h"
#include "gotoyx.h"
#include "file.h"

int main() {
    // !!! 선 언 먼 저 합 니 다 , srand도 함 수 니 까 선 언 다 음 에 하 세 요 !!!
    int i;
    Land* gameboard;
    Land cur_land;
    Player user = { 100, 0, "", PLAYER, 0 };

    srand((unsigned)time(NULL));

    // make_user_name보다는 그냥 한번에 setting해주는 함수로 짜는 게 나을듯, 위에 100, 0, "", PLAYER 넣어주는 걸로 (단, 세세히 모듈화)
	make_user_name(&user);

	gameboard = file_get_land_info();
    if (gameboard == NULL){
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        return -1;
    }

    //check data validation
    for(i = 0; i < 21; i++){\
        cur_land = gameboard[i];
        printf("%d %s %d %s\n", cur_land.land_position, cur_land.name, cur_land.land_price, cur_land.landmark_name);
    }

    system("pause");
    system("cls");

    show_gameboard_grid();
    system("pause");
}
