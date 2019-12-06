//
// Created by DongHoony on 2019-11-20.
//

#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "random.h"


Dice rand_dice_roll(){
    Dice d;
    d.d1 = rand_roll_dice_only();
    d.d2 = rand_roll_dice_only();
    return d;
}

int rand_roll_dice_only(){
    int ret;
    ret = rand() % DICE_MAX + 1;
    return ret;
}

int determine_double(Dice d){
    return (d.d1 == d.d2) ? DOUBLE : NOT_DOUBLE;
}

/*
int rand_roll_dice_only(){
    int ret;
    ret = rand() % DICE_MAX + 1;
    return ret;
}

int rand_roll_dice(Player* user) {
    int count = 0;

    while (1) {
        int dice_1 = rand() % 5 + 1;
        int dice_2 = rand() % 5 + 1;

        printf("%d,%d\n", dice_1, dice_2);


        if (count == 2) {
            printf("지속적인 더블로 무인도행");
            break;
        }

        user->position += dice_1 + dice_2;

        if (user->position > 21) {
            user->position -= 21;
            user->lap++;
        }

        if (dice_1 != dice_2)
            break;
        count++;
    }
	return 0;
}

int rand_house_person(){
	return 0;
}
*/