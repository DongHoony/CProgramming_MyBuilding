//
// Created by DongHoony on 2019-11-29.
//
#include <stdlib.h>
#include <time.h>
#include "cycle.h"
#include "player.h"
#include "random.h"
#include "show.h"
#include "gotoyx.h"
#include "money.h"

// includes animation
int move_cycle(Land* gameboard, Player* p, Dice d){
    int i;
    for(i = 0; i < d.d1 + d.d2; i++){
        show_player_move(gameboard, p, p->position, (p->position + 1) % MAX_TILE);
        player_move_value(p, 1);

        if (p->position == MAX_TILE) {
            money_get_income(p);

            show_money_update(p, TRUE);
            p->position = 0;
            p->lap++;
            show_player_move(gameboard, p,21, 0);
        }
        _sleep(150);
    }
    return p->position;
}

int land_normal_cycle(Land* land, Player* p, Player* p_2, Resident* res){
    int land_owner = land->label;
    int label = p->label;
    int* selected_building = NULL;
    int i, predicted_price, valid;

    // �� ��, �� ��, �� �� Ȯ�� �� ����� ����

    // �� ���̰ų� �� ���̸� ��� ��
    if (land_owner == NO_ONE || land_owner == label){
        // �� �� ����ݾ� -> show_choice���� ����
        selected_building = show_choice_building(land, p);
        for(i = 0; i < 5; i++){
            if (selected_building[i] == 1){
//                        gotoyx_print(34, 0, "Attempt to buy..");
                land_buy(p, land, res, i);
                _sleep(300);
                show_money_update(p, FALSE);
            }
        }
        free(selected_building);
        money_spend(p, predicted_price);
        show_money_update(p, FALSE);
    }

        // �� ���̸� ����� ��
    else {
        predicted_price = land_calculate_cost(land);
        valid = money_trade(p, p_2, predicted_price);
        show_player_update(p);
        show_player_update(p_2);
        if (valid == NOT_OK) return NOT_OK;
    }

    return OK;
}

int land_cycle(Land* land, Player* p, Player* p_2, Resident* res){
    int land_type = land->land_type;
    int signal;

    //������ ���� �� Ÿ���̸�
    if (land_type == NORMAL_TYPE){
            signal = land_normal_cycle(land, p, p_2, res);
            if (signal == NOT_OK) return NOT_OK;
    }

    //������ ���� Ư�� Ÿ���̸�
    if (land_type == SPECIAL_TYPE) {

    }
    return OK;
}

int game_cycle(Land* gameboard, Player* p, Player* p_2, Resident* res){
    // CYCLE : ROLL -> MOVE -> LAND -> END PHASE
    int pos, label, double_count = 0;
    int is_double = 0, signal;
    Dice dice;

    srand((unsigned)time(NULL));

    // label indicates whose turn now
    label = p->label;

    while (1){
        // ROLL PHASE
        dice = rand_dice_roll();

        //test for control dice below 4 lines
        gotoyx(33, 50);
        printf("DICE :         ");
        gotoyx(33, 57);
        scanf("%d %d", &dice.d1, &dice.d2);
        //enable below if normal stance
        //show_dice_roll(dice.d1, dice.d2);

        is_double = determine_double(dice);
        double_count += is_double ? 1 : 0;

        // ���� �� ������ üũ�ϱ�, 2ȸ �̻��̸� ���ε���
        if (double_count >= 2) {
            show_player_move(gameboard, p, p->position, ABANDONED_ISLAND);
            player_move_toward(p, ABANDONED_ISLAND);
            return 1;
        }

        // MOVE PHASE
        p->position = move_cycle(gameboard, p, dice);
        pos = p->position;

        //temporary added thing that indicates player's position
        gotoyx(33,0);
        printf("NOW AT %02d", p->position);

        // LAND PHASE
        signal = land_cycle(&gameboard[pos], p, p_2, res);
        if (signal == NOT_OK) return NOT_OK;

        // END PHASE, ������ �ƴϸ� ���� Ż���ϱ�
        if (is_double == NOT_DOUBLE) break;
    }
    return OK;
}