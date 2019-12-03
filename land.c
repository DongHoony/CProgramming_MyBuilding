//
// Created by DongHoony on 2019-11-20.
//

#include "player.h"
#include "land.h"
#include "resident.h"
#include "money.h"

int land_buy(Player* user, Land* l){
    int number = 0;
    int i = 0;
    int (*buy_func_ptr[5])(Player*, Land*, int) = {buy_only_land, buy_villa, buy_building, buy_hotel, buy_landmark};

    while(1) {
        land_buy_menu();
        scanf("%d", &number);
        // get_number �̿��ϵ��� ���� (���߿� �ٲٸ� ��) -> ���� ������ �ʿ� ����
        // if(number>4 || number<0) printf("0~4 ���� ���� ���� �ٽ� �Է����ּ��� \n");


        for(i = 0; i < user->lap; i++){
            buy_func_ptr[i](&user, &i, i);
        }




        if(user->lap==0) {
            if(number>0 && number<=4) printf("ù ��° lap������ �ǹ��� ���� �� �����ϴ�! \n");
            else if(number==0)  {
                buy_only_land(&user, &l, i); break;
            }
        }

        if(user->lap==1) {
            if(number>1 && number<=4) printf("�� ��° lap������ ���� �̻��� �ǹ��� ���� �� �����ϴ�! \n");
            else if(number==0) 	{
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i); break;
            }
        }
        if(user->lap==2) {
            if(number>2 && number<=4) printf("�� ��° lap������ ȣ�� �̻��� �ǹ��� ���� �� �����ϴ�! \n");
            else if(number==0) 	{
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i);  break;
            }
            else if(number==2) {
                buy_building(&user, &l, &i); break;
            }
        }

        if(user->lap==3) {
            if(number==4) printf("�� ��° lap������ ���帶ũ�� ���� �� �����ϴ�! \n");
            else if(number==0) {
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i); break;
            }
            else if(number==2) {
                buy_building(&user, &l, &i); break;
            }
            else if(number==3) {
                buy_hotel(&user, &l, &i); break;
            }
        }

        if(user->lap==4) {
            if(number==0) {
                buy_only_land(&user, &l, &i); break;
            }
            else if(number==1) {
                buy_villa(&user, &l, &i);  break;
            }
            else if(number==2) {
                buy_building(&user, &l, &i);  break;
            }
            else if(number==3) {
                buy_hotel(&user, &l, &i); break;
            }
            else if(number==4) {
                buy_landmark(&user, &l, &i); break;
            }
        }
    }
}

int check_land(Land* land, int level){
// level��ŭ�� ������ land�� ���������� Ȯ���Ѵ�
    if (land->level >= level) return OK;
    else NOT_OK;
}

int buy_only_land(Player *user, Land *l, int i) {
    i = money_spend(&user, l->land_price);
    if(i == NOT_OK) printf("���� �����մϴ�! \n");
    else if(i==0) {
        printf("���� �����մϴ�! \n");
        l->level = 1;
    }
}

int buy_villa(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*villa_value);
    if(i == NOT_OK) printf("���� �����մϴ�! \n");
    else if(i==0) {
        printf("������ �����մϴ�! \n");
        rand_person_villa(&user, &people);
        l->level = 2;
    }
}

int buy_building(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
        buy_villa(&user, &l, i);
    }
    else if(l->level==1) {
        buy_villa(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*buliding_value);
    if(i==-1) printf("���� �����մϴ�! \n");
    else if(i==0) {
        printf("������ �����մϴ�! \n");
        rand_person_building(&user, &people);
        l->level = 3;
    }
}

int buy_hotel(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
    }
    else if(l->level==1) {
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
    }
    else if(l->level==2) {
        buy_building(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*hotel_value);
    if(i==-1) printf("���� �����մϴ�! \n");
    else if(i==0) {
        printf("ȣ���� �����մϴ�! \n");
        rand_person_hotel(&user, &people);
        l->level = 4;
    }
}

int buy_landmark(Player *user, Land *l, int i) {
    if(l->level==0) {
        buy_only_land(&user, &l, i);
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
        buy_hotel(&user, &l, i);
    }
    else if(l->level==1) {
        buy_villa(&user, &l, i);
        buy_building(&user, &l, i);
        buy_hotel(&user, &l, i);
    }
    else if(l->level==2) {
        buy_building(&user, &l, i);
        buy_hotel(&user, &l, i);
    }
    else if(l->level==3) {
        buy_hotel(&user, &l, i);
    }
    i = money_spend(&user, (l->land_price)*landmark_value);
    if(i==-1) printf("���� �����մϴ�! \n");
    else if(i==0) {
        printf("���帶ũ�� �����մϴ�! \n");
        l->level = 5;
    }
}

void land_buy_menu() {
    printf("==========�ø� �ǹ� ����==========\n");
    printf("0. ���� ���� \n");
    printf("1. ���� \n");
    printf("2. ���� \n");
    printf("3. ȣ�� \n");
    printf("4. ���帶ũ \n");
    printf("===================================\n");
}