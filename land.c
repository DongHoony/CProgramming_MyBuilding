//
// Created by DongHoony on 2019-11-20.
//

#include <stdlib.h>
#include "player.h"
#include "land.h"
#include "resident.h"
#include "money.h"
#include "gotoyx.h"

// suppose player has enough money  (functions below)
int land_buy_build(Player* p, Land* land, Resident* r, int level){
    const char* STR[5] = {"T", "S", "M", "L", "LMRK"};
    const int PEOPLE[] = {0, 2, 3, 4};
    int book_people;
    int x_pos[5] = {NULL, land->p_b1.x, land->p_b2.x, land->p_b3.x, land->p_b1.x-1};
    int y_pos[5] = {NULL, land->p_b1.y, land->p_b2.y, land->p_b3.y, land->p_b1.y};
    int label = p->label;
    int pos = land->land_position;

    land->label = label;
	land->level[level] = 1; //�ش� �ǹ� ���������� ����
	if(level == ONLY_LAND-1) return OK;
	// level is 0-based
	if(level == 4) {
	    book_people = r->rand_person_hotel[pos] + r->rand_person_building[pos] + r->rand_person_villa[pos];
        r->res_person_landmark[pos] = book_people;
	}
	else {
	    book_people = rand() % PEOPLE[level] + 1;
        *((r->resident_info[level-1]) + pos) = book_people;
	}
    gotoyx_set_color(label == COMPUTER ? C_RED : C_BLUE);
	gotoyx_print(y_pos[level], x_pos[level], STR[level]);
	gotoyx_print_int(y_pos[level], x_pos[level] + 1, book_people);
	gotoyx_set_color(C_WHITE);
	return 0;
}
/*
int land_buy_only_land(Player* p, Land* land, Resident* r){
    land->label = p->label;
}


int land_buy_villa(Player* p, Land* land, Resident* r){
    int pos = land->land_position;
    land->label = p->label;
    rand_person_villa(p, r);
}

int land_buy_building(Player* p, Land* land, Resident* r){

}

int land_buy_hotel(Player* p, Land* land, Resident* r){

}

int land_buy_landmark(Player* p, Land* land, Resident* r){

}

int land_check_valid(){

}
*/
// 1.0 1.2 1.5 1.7 2.0

// level�� ONLY_LAND, VILLA, BUILDING, HOTEL, LANDMARK�� ������ ��!
// �̹� �� ����ϴٰ� �����Ѵ�
int land_buy(Player* p, Land* land, Resident* res, int level){
    // [12345] land villa building hotel landmark
    // User buys land with level
    const double MULTIPLY[] = {1.0, 1.2, 1.5, 1.7, 2.0};
    int price = land->land_price * MULTIPLY[level];
    // if you have enough money
    land_buy_build(p, land, res, level);
    money_spend(p, price);
    return OK;
}


void land_check_label(Player* p,Land* land){//���� ���¸� �ľ���(�̹� ���� �궥, ��붥, ��)-> �� ��Ȳ�� �°� �Լ��� �ҷ��� �ذ�(�󶥿� �ǹ� ���� �Լ�,�������� �Ӵ�� �ִ� �Լ�, ���� ������ �ǹ� �� ������ �Ǵ��ϴ� �Լ�)
	if(land->label==0);
	else if(land->label==p->label);
	else if(land->label!=p->label);
} //����

int land_check_land(Land* land, int level) { //�ǹ��� �ø����� �ݵ�� ���� �������̾�� ���� Ȯ�����ִ� �Լ�
	int i=0;
	if(level > ONLY_LAND && land->level[ONLY_LAND-1] == 0) return NOT_OK;  //���� �������� �ʰ� �ǹ� �ø��� ��� -1 ��ȯ
	else return OK; //�� ���� ��� 1��ȯ
}

int land_check_lap(Player* p, int level) {  //lap���� ���� �� �� �ִ� �ǹ� �����ϴ� �Լ�   ->   ���� �Լ��� ó�� �ؾ��ϴ°��� ���ؼ��� �ǹ�.
	if(p->lap + 1 >= level) return OK; 
	else return NOT_OK;
}

/*  ���帶ũ �������� ���帶ũ ���� �ǹ����� ��� �����ؾ� ���� �� ����.
int i=0, sum=0;
for(i=0; i<LANDMARK-1; i++) {
	sum += land->level[i];
}
if(sum == 4) return OK
else return NOT_OK;
*/
