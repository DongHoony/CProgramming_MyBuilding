//
// Created by DongHoony on 2019-11-20.
//

#include <stdlib.h>
#include "../header_files/player.h"
#include "../header_files/land.h"
#include "../header_files/resident.h"
#include "../header_files/money.h"
#include "../header_files/gotoyx.h"
#include "../header_files/show.h"

int land_check_landmark(Land* land) {
    int i=0, sum=0;
    for(i=0; i<LANDMARK-1; i++) {
        sum += land->level[i];
    }
    if(sum == 4) return OK;
    else return NOT_OK;
}

int land_check_land(Land* land, int level) { //�ǹ��� �ø����� �ݵ�� ���� �������̾�� ���� Ȯ�����ִ� �Լ�
    int i=0;
    if(level > ONLY_LAND && land->level[ONLY_LAND-1] == 0) return NOT_OK;  //���� �������� �ʰ� �ǹ� �ø��� ��� -1 ��ȯ
    else return OK; //�� ���� ��� 1��ȯ
}

int land_check_lap(Player* p, int level) {  //lap���� ���� �� �� �ִ� �ǹ� �����ϴ� �Լ�   ->   ���� �Լ��� ó�� �ؾ��ϴ°��� ���ؼ��� �ǹ�.
    if(p->lap + 1 >= level) return OK;
    else return NOT_OK;
}

// suppose player has enough money  (functions below)
int land_buy_build(Player* p, Land* land, Resident* r, int level){
    int book_people;
    int label = p->label;
    int pos = land->land_position;

	if(land_check_lap(p, level)==OK && land_check_land(land, level)==OK) {
        land->label = label;
        land->level[level] = 1; //�ش� �ǹ� ���������� ����
        show_land_building_only_land(land, p);

        if(level == ONLY_LAND-1) return OK;
        // level is 0-based
        if(level == 4 && land_check_landmark(land) == OK) {
            book_people = res_set_landmark_residents(r, pos);
            show_land_building_landmark_residents(land, book_people);
        }
        else {
            book_people = res_set_residents(r, pos, level);
            show_land_building_residents(land, level, book_people);
        }
        gotoyx_set_color(C_WHITE);
	}
    return 0;
}

// 1.0 1.2 1.5 1.7 2.0

// level�� ONLY_LAND, VILLA, BUILDING, HOTEL, LANDMARK�� ������ ��!
// �̹� �� ����ϴٰ� �����Ѵ�
int land_buy(Player* p, Land* land, Resident* res, int level){
    // [12345] land villa building hotel landmark
    // User buys land with level
    const int MULTIPLY[] = {10, 12, 15, 17, 20}; // ���Ű��� (���� �� ��)
    int price = land->land_price * MULTIPLY[level] / 10;
    // if you have enough money
    land_buy_build(p, land, res, level);
    money_spend(p, price);
    return OK;
}

int land_calculate_cost(Land* land, Resident* res){
    // ����� = (���� ����) * (1 + (���󼼴�� * 0.1) + (��������� * 0.2) + (ȣ�ڼ���� * 0.3))
    // ������ ��� ����� = (���� ����) * (1 + (��������� * 0.5))
    int i, ret = 0, land_only_total_price = 0;
    const int BUY_MULTIPLY[] = {10, 12, 15, 17, 20};
    const int FEE_MULTIPLY[] = {10, 12, 14, 16, 18};
    const int RES_MULTIPLY[] = {1, 2, 3, 5};
    int multiply = 0;
    gotoyx(34, 15);
    for(i = 0; i < 4; i++){
        if (land->level[i] == 1) {
            land_only_total_price += land->land_price * FEE_MULTIPLY[i] / 10;
            multiply += RES_MULTIPLY[i] * res->resident_info[i][land->land_position];
            printf("%d : %d ", i,  res->resident_info[i][land->land_position]);
        }
    }
    if (land->level[4] == 1) multiply = 5 * res->res_person_landmark[land->land_position];
    gotoyx(34, 4);
    ret = land_only_total_price * (10 + multiply) / 10;
    ret *= land->land_multiply;
    printf("%d %d", multiply + 10, ret);
    return ret;
}