//
// Created by DongHoony on 2019-11-20.
//
#include <malloc.h>
#include <stdio.h>
#include "../header_files/land.h"
#include <string.h>

#define START_CHAR '!'

int file_is_nullptr(FILE* f){
    if (f == NULL){
        printf("NULLPTR\n");
        return 1;
    }
    else return 0;
}

void get_chars_until_specific_char(FILE* f, char specific_char){
    char c;
    while (1){
        c = fgetc(f);
        if(c == specific_char) break;
        else printf("%c", c);
    }
}

// returns Land* array => Land**
Land* file_get_land_info(){
    int land_price, land_number, i, j;
    char land_name[100], landmark_name[100];
    Land temp_land;
    // land tmp;
    // land array <Struct array>
    Land* land_array = (Land*) malloc(sizeof(Land) * 21);

    // LAND_INFO
    FILE* f = fopen("..\\data\\LAND_INFO", "r");

    if (file_is_nullptr(f)) return NULL;
    get_chars_until_specific_char(f, START_CHAR);

    for(i = 0; i < MAX_TILE; i++){
        memset(land_name, 0x0, 100);
        memset(landmark_name, 0x0, 100);

        fscanf(f, "%d", &land_number);
        fscanf(f, "%s", land_name);
        fscanf(f, "%d", &land_price);
        fscanf(f, "%s", landmark_name);

        //initialization
        memset(temp_land.level, 0x0, sizeof(temp_land.level));
        temp_land.name = (char*) malloc(sizeof(char) * strlen(land_name) + 1);
        strcpy(temp_land.name, land_name);
        temp_land.landmark_name = (char*) malloc(sizeof(char) * strlen(landmark_name) + 1);
        strcpy(temp_land.landmark_name, landmark_name);
        temp_land.land_price = land_price;
        temp_land.land_position = land_number;
        temp_land.label = NO_ONE;
        temp_land.land_multiply = 1;
        temp_land.land_type = (i == ABANDONED_ISLAND || i == START_LAND || i == FESTIVAL || i == TRAVEL || i == MINIGAME) ? SPECIAL_TYPE : NORMAL_TYPE;
        land_array[i] = temp_land;


        // test codes below
        /*
        tmp = land_array[i];
        printf("%d %s %d %s\n", tmp.land_position, tmp.name, tmp.land_price, tmp.landmark_name);
        */
        //test code ends

    }
    fclose(f);
    return land_array;
}

int file_get_land_pos(Land **land_arr_addr){
    int i, num;
    Point p_b1, p_b2, p_b3, p_player, p_bot, p_land;
    Land* land_arr = *land_arr_addr;
    FILE* f = fopen("..\\data\\LAND_POS_INFO", "r");

    if (file_is_nullptr(f)) return NULL;
    get_chars_until_specific_char(f, START_CHAR);

    for(i = 0; i < MAX_TILE; i++){
        fscanf(f, "%d", &num);
        if (num != i) {
            printf("WRONG MATCH!\n");
            return NULL;
        }
        fscanf(f, "%d %d", &p_b1.y, &p_b1.x);
        fscanf(f, "%d %d", &p_b2.y, &p_b2.x);
        fscanf(f, "%d %d", &p_b3.y, &p_b3.x);
        fscanf(f, "%d %d", &p_player.y, &p_player.x);
        fscanf(f, "%d %d", &p_bot.y, &p_bot.x);
        fscanf(f, "%d %d", &p_land.y, &p_land.x);

        if (land_arr[i].land_type == NORMAL_TYPE){
            land_arr[i].p_b1 = p_b1;
            land_arr[i].p_b2 = p_b2;
            land_arr[i].p_b3 = p_b3;
        }
        land_arr[i].p_bot = p_bot;
        land_arr[i].p_player = p_player;
        land_arr[i].p_land = p_land;
    }
    fclose(f);
	return OK;
}

int file_modify(Land** gameboard){
    *gameboard = (Land *) file_get_land_info();
    // Check gameboard is successfully attached in program
    if (*gameboard == NULL) {
        printf("!! FUNCTION RETURNED NULLPTR !!\n");
        system("pause");
        return NOT_OK;
    }
    file_get_land_pos(gameboard);
    system("cls");
}