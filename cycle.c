//
// Created by DongHoony on 2019-11-29.
//
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "random.h"
#include "show.h"
#include "gotoyx.h"
#include "cycle.h"

Dice dice_roll(){
    Dice d;
    d.d1 = rand_roll_dice_only();
    d.d2 = rand_roll_dice_only();
    return d;
}

int determine_double(Dice d){
    return (d.d1 == d.d2) ? DOUBLE : NOT_DOUBLE;
}

// includes animation
int move_cycle(Land* gameboard, Player* p, Dice d){
    int i;
    for(i = 0; i < d.d1 + d.d2; i++){
        show_player_move(gameboard, p, p->position, (p->position + 1) % 22);
        player_move_value(p, 1);

        if (p->position == 22) {
            money_get_income(p);
            p->position = 0;
            show_player_move(gameboard, p,21, 0);
        }
        _sleep(300);
    }
    return p->position;
}

int land_cycle(Land* gameboard, Player* p, int pos){
    int land_owner = gameboard[pos].label;
    if (land_owner == NO_ONE){

    }
    else if (land_owner == p->label){

    }
    else if (land_owner != p->label){

    }
}

int cycle(Land* gameboard, Player* p){
    int pos, land_owner, label, double_count = 0;
    int is_double = 0, lap;
    int land_label, land_type;
    Dice dice;

    srand((unsigned)time(NULL));
    // label indicates whose turn now
    label = p->label;

    while (1){
        // �ֻ��� ������
        dice = dice_roll();
        show_dice_roll(dice.d1, dice.d2);

        is_double = determine_double(dice);
        double_count += is_double ? 1 : 0;

        // ���� �� ������ üũ�ϱ�, 2ȸ �̻��̸� ���ε���
        if (double_count >= 2) {
            player_move_toward(p, ABANDONED_ISLAND);
            return 1;
        }

        // �����̱�
        pos = move_cycle(gameboard, p, dice);
        lap = p->lap;

        // ������ �� Ȯ�� (���, ���ε��� ���� Ư�� Ÿ������, �Ϲ� �� Ÿ������ Ȯ��)
        land_type = gameboard[pos].land_type;

        //������ ���� �� Ÿ���̸�
        if (land_type == NORMAL_TYPE){
            land_owner = gameboard[pos].label;

            // �� ��, �� ��, �� �� Ȯ�� �� ����� ����
            // �� ���̸� �� �� ����
            if (land_owner == NO_ONE){
                show_choice_building(&gameboard[pos], p);
            }
            // �� ���̸� ������ų �� ����
            else if (land_owner == label){

            }
            // �� ���̸� ����� ��
            else if (land_owner != label && land_owner != NO_ONE){

            }
        }

        //������ ���� Ư�� Ÿ���̸�
        if (land_type == SPECIAL_TYPE){

        }

        // ������ �ƴϸ� ���� Ż���ϱ�
        if (is_double == NOT_DOUBLE) break;
    }
    return 0;
}