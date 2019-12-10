#include "player.h"
#include "money.h"
#include "land.h"
#include "show.h"
#include <stdlib.h>
#include <time.h>

int money_spend(Player* p, int value){//�ܼ� �� ����
   int i, cur_money = p->money;
   if (p->money < value) return NOT_OK;
   for(i = cur_money; i > cur_money - value; i -= 10){
       p->money -= 10;
       show_money_update(p, FALSE);
       if (i % 250 == 0)_sleep(20);
   }
   show_money_normal_update(p);
   return OK;
}
void money_earn(Player* p, int value){
    int i, cur_money = p->money;
    for(i = cur_money; i < cur_money+value; i+=10){
        p->money += 10;
        show_money_update(p, TRUE);
        if (i % 250 == 0)_sleep(20);
    }
    show_money_normal_update(p);
    return;
}
int money_trade(Player* p_from, Player* p_to, int value){
    int ret, i, cur_money = p_from->money;
    ret = money_compare(p_from->money, value);
    for(i = cur_money; i < cur_money+value; i+=10){
//        money_earn(p_to, 10);
//        money_spend(p_from, 10);

        if (p_from->money < 0) return NOT_OK;
        p_from->money -= 10;
        p_to->money += 10;
        show_money_update(p_from, FALSE);
        show_money_update(p_to, TRUE);


        if (i % 250 == 0) _sleep(20);
    }
    show_money_normal_update(p_from);
    show_money_normal_update(p_to);
    return OK;
}

void money_get_income(Player* p){
    money_earn(p, SALARY);
} //-> earn_money�� ������

int money_compare(int have, int need){
    return (have >= need) ? OK : NOT_OK;
}

int find_festival_pos(Land* l){ //��� ���� �佺Ƽ�� ���������� Ȯ���ϴ� �Լ�
    int i, sum = 0;
    for(i = 0; i < MAX_TILE; i++){
        if(l[i].land_multiply>1){
            sum = i;
            break;
        }
    }
    return sum;
}

int enemy_land_spend(Player* p,Land* l){ //���̳� ���� ������ ���� �ɸ��� ���� �����ϴ� �Լ�,������ Ȯ��
   int condition;
   int value = 0;
   value = col_land_price(l);
   condition = money_spend(p,value);//���� ���� �ִ� ��Ȳ���� Ȯ��
   return condition;//ok or not
}

int col_land_price(Land* l){
	int i;
	int sum=0;
	const double MULTIPLY_FEE[5] = {1.0, 1.1, 1.3, 1.5, 1.7};
	for(i = 0; i < 5; i++){
		if(l->level[i] == 0){
			sum+=l->land_price*MULTIPLY_FEE[i];
		}
	}
	sum *= l->land_multiply;
	return sum;
}

int make_festival(Land* gameboard,Player* p){//�� ���� �����ϰ� �ϳ� ����//�佺Ƽ�� ���� ����
	int i, cnt =0 ;
	srand((unsigned)time(NULL));

    for(i = 0; i < MAX_TILE; i++) if (gameboard[i].label == p->label) cnt++;

    if (cnt == 0) return START_LAND;

	while(1){
		i = rand() % MAX_TILE;
		if(p->label == gameboard[i].label) break;
	}
	return i;
}
int col_festival(Land* gameboard,Player* p){//2�輳���Լ�
	int origin_pos = find_festival_pos(gameboard);//���� �佺Ƽ�� ����
	int new_pos=make_festival(gameboard, p);//���ο� �佺Ƽ�� ���
	if(origin_pos != new_pos) gameboard[origin_pos].land_multiply = 1;
    gameboard[new_pos].land_multiply *= 2;
    return new_pos;
}

// �Լ��̸� ���� �ҹ��ڷ�
void all_land_rent_fee(Land* l,Player* p, Resident* r){//��� ���� ���� �Ӵ�� ��
    int i;
    for(i=0; i < MAX_TILE; i++){
        if(l[i].label==1){
            p->money+=(l[i].land_price/100)*r->rand_person_villa[i];
            p->money+=(l[i].land_price/100)*r->rand_person_building[i];
            p->money+=(l[i].land_price/100)*r->rand_person_hotel[i];
        }
    }
}

// money_get_income ����
void start_pont_income(Player* p,Land* l,Resident* r){//�ʹݶ� ����ϸ� ���ް� �Ӵ�Ḧ ���� ����
   money_get_income(p);
   all_land_rent_fee(l, p, r);
}

//�Լ��̸� �ҹ��ڷ�
void all_comland_rent_fee(Land* l,Player* p,Resident r){//��� ���� ���� �Ӵ�� ���
    int i;
    for(i = 0; i < MAX_TILE; i++){
        if(l[i].label == p->label){
            p->money+=(l[i].land_price/100)*r.rand_person_villa[i];
            p->money+=(l[i].land_price/100)*r.rand_person_building[i];
            p->money+=(l[i].land_price/100)*r.rand_person_hotel[i];
        }
    }
}