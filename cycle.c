#include <stdlib.h>
#include <time.h>
#include <conio.h>
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
            p->position = 0;
            p->lap++;
            show_lap_update(p);
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
//                _sleep(300);
            }
        }
        free(selected_building);
    }

        // �� ���̸� ����� ��
    else {
        predicted_price = land_calculate_cost(land, res);
        valid = money_trade(p, p_2, predicted_price);

        if (valid == NOT_OK) return NOT_OK;
    }

    return OK;
}

int land_cycle(Land* gameboard, Land* land, Player* p, Player* p_2, Resident* res){
    int fest_pos, before_fest_pos;
    int land_type = land->land_type;
    int signal;

    before_fest_pos = find_festival_pos(gameboard);
    //������ ���� �� Ÿ���̸�
        if (land_type == NORMAL_TYPE){
            signal = land_normal_cycle(land, p, p_2, res);
            if (signal == NOT_OK) return NOT_OK;
    }

    //������ ���� Ư�� Ÿ���̸�
    if (land_type == SPECIAL_TYPE) {
        switch(land->land_position){
            case TRAVEL:
                signal = travel_cycle(gameboard, p, p_2, res);
                if (signal == NOT_OK) return NOT_OK;
                break;
            case FESTIVAL:
                fest_pos = col_festival(gameboard, p);
                gotoyx(34, 0); printf("FESTIVAL AT %d!! ", fest_pos);
                show_festival(&gameboard[before_fest_pos], &gameboard[fest_pos]);
                gotoyx(12, 71); gotoyx_set_color(C_GREEN);
                if (fest_pos != START_LAND) printf("%5dx", gameboard[fest_pos].land_multiply);
                break;
            case START_LAND:
                show_lap_update(p);
                break;
            case ABANDONED_ISLAND:
                p->abandon_island_count = 1;
                break;
        }
    }
    return OK;
}

int travel_cycle(Land* gameboard, Player* p, Player* p_2, Resident* res){
    int signal, pos;
    int destination = show_travel_choice(gameboard);
    Dice d = {0, (destination > 15) ? destination-15 : 7 + destination};
    p->position = move_cycle(gameboard, p, d);
    pos = p->position;

    signal = land_cycle(gameboard, &gameboard[pos], p, p_2, res);
    if (signal == NOT_OK) return NOT_OK;
}

int game_cycle(Land* gameboard, Player* p, Player* p_2, Resident* res, int cheat){
    // CYCLE : ROLL -> MOVE -> LAND -> END PHASE
    int pos, double_count = 0;
    int is_double = 0, signal;
    Dice dice;
    srand((unsigned)time(NULL));

    while (1){
        // CHECK ABANDON ISLAND PHASE
        if (p->abandon_island_count > 0){
            p->abandon_island_count--;
            _sleep(500);
            return 1;
        }

        // ROLL PHASE
        if (cheat != '1') getch();
        dice = rand_dice_roll();

        //test for control dice below 4 lines
        if (cheat == '1'){
            gotoyx(33, 50);
            printf("DICE :         ");
            gotoyx(33, 57);
            scanf("%d %d", &dice.d1, &dice.d2);
        }
        //enable below if normal stance
        else{
            show_dice_roll(dice.d1, dice.d2);
            show_dice_big_size(dice.d1 + dice.d2);
        }


        is_double = determine_double(dice);
        double_count += is_double ? 1 : 0;

        // ���� �� ������ üũ�ϱ�, 2ȸ �̻��̸� ���ε���
        if (double_count >= 2) {
            show_player_move(gameboard, p, p->position, ABANDONED_ISLAND);
            player_move_toward(p, ABANDONED_ISLAND);
            p->abandon_island_count = 1;
            return 1;
        }

        // MOVE PHASE
        p->position = move_cycle(gameboard, p, dice);
        pos = p->position;

        //temporary added thing that indicates player's position
        gotoyx(33,0);
        printf("NOW AT %02d", p->position);

        // LAND PHASE
        signal = land_cycle(gameboard, &gameboard[pos], p, p_2, res);
        if (signal == NOT_OK) return NOT_OK;

        // END PHASE, ������ �ƴϸ� ���� Ż���ϱ�
        if (is_double == NOT_DOUBLE || p->position == ABANDONED_ISLAND) break;
    }
    return OK;
}

int tie_breaker(Land* gameboard, Resident* res){
    int i, j, p1_land_cnt, p2_land_cnt, p1_res_cnt = 0, p2_res_cnt = 0;
    for(i = 0; i < MAX_TILE; i++){
        if (gameboard[i].label == PLAYER) {
            p1_land_cnt++;
            for(j = 0; j < 3; j++) p1_res_cnt += res->resident_info[j][i];
        }
        else if (gameboard[i].label == COMPUTER) {
            p2_land_cnt++;
            for(j = 0; j < 3; j++) p2_res_cnt += res->resident_info[j][i];
        }
    }
    if (p1_land_cnt == p2_land_cnt){
        return (p1_res_cnt > p2_res_cnt) ? PLAYER : COMPUTER;
    }
    else return (p1_land_cnt > p2_land_cnt) ? PLAYER : COMPUTER;
}