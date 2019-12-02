//
// Created by DongHoony on 2019-11-20.
//
#pragma once
#include "player.h"
#include "resident.h"

#define START_LAND 0
#define ABANDONED_ISLAND 4
#define FESTIVAL 11
#define TRAVEL 15

#define NORMAL_TYPE 0
#define SPECIAL_TYPE 1

typedef struct point{
    int y;
    int x;
}Point;

// land.h -> 재욱
typedef struct land{
    int land_position;
    char* name;
    char* landmark_name;
    int land_type; // NORMAL_TYPE, SPECIAL_TYPE - 일반 땅, 스페셜 땅
    int land_price;
    int land_multiply; //배수 설정 (페스티벌)
    int label; //누구건지 NO_ONE, PLAYER, COMPUTER
    int level; //별장, 빌딩, 호텔, 랜드마크 여부 (1~5) 1: 땅만 보유 ~ 5: 랜드마크 보유
    Point p_b1, p_b2, p_b3, p_player, p_bot;
}Land;

int land_buy(Player* user, Land* l) ;
void buy_only_land(Player *user, Land *l, int i);
void buy_villa(Player* user, Land* l, int i);
void buy_building(Player* user, Land* l, int i) ;
void buy_hotel(Player* user, Land* l, int i);
void buy_landmark(Player* user, Land* l, int i);

void land_buy_menu();