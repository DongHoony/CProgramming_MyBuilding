//
// Created by DongHoony on 2019-11-20.
//
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include "player.h"

// constants for after use
#define NO_ONE 0
#define PLAYER 1
#define COMPUTER 2

int rand_roll_dice(Player* user) {
	int count = 0;

	while (1) {
		int dice_1 = rand() % 5 + 1;
		int dice_2 = rand() % 5 + 1;

		printf("%d,%d\n", dice_1, dice_2);


		if (count == 2) {
			printf("�������� ����� ���ε���");
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
}

void* make_user_name(Player* user) {
	user->name = (Player*)malloc(sizeof(Player));
	printf("����� �̸� : ");
	scanf("%s", user->name);
	user->label = PLAYER;
}

int rand_house_person(Land) {
	
}
