//
// Created by DongHoony on 2019-11-20.
//

#include <stdlib.h>
#include "player.h"
#include "land.h"
#include "resident.h"
#include "money.h"

// suppose player has enough money  (functions below)
int land_buy_build(Player* p, Land* land, Resident* r, int level){
	int i=0;
    const int PEOPLE[] = {0, 0, 2, 3, 4};
    int pos = land->land_position;
    land->label = p->label;
	land->level[level-1] = 1; //�ش� �ǹ� ���������� ����
	if(level == ONLY_LAND) return OK;
	if(level == LANDMARK) {
		for(i=0; i<LANDMARK-1; i++) {
			r->resident_info[LANDMARK-1][pos] += r->resident_info[i][pos];
		}
	}
	else r->resident_info[level-1][pos] = rand() % PEOPLE[level] + 1;
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
int land_buy(Player* p, Land* land, Resident* res, int level){
    // [12345] land villa building hotel landmark
    // User buys land with level
    const double MULTIPLY[] = {0, 1.0, 1.2, 1.5, 1.7, 2.0};
    int price = land->land_price * MULTIPLY[level];
    // if you have enough money
    if (money_compare(p->money, price)){
        land_buy_build(p, land, res, level);
        money_spend(p, price);
        return OK;
    }
    else return NOT_OK;
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
