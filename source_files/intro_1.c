#include "../header_files/intro_1.h"
#include "../header_files/gotoyx.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")

void intro() {
	play_intro();
	gotoyx(0, 0);
	screen_1();
	Sleep(600);
	gotoyx(0, 0);
	screen_2();
	Sleep(600);
	gotoyx(0, 0);
	screen_1();
	Sleep(600);
	gotoyx(0, 0);
	screen_3();
	Sleep(600);
	gotoyx(0, 0);
	system("cls");
	play_intro_2();
	screen_4();
	gotoyx(0, 0);
}

void screen_1() {
    printf("                                                                              \n");
    printf("                                                                              \n");
	printf("                                                               "YEL"0000000                               \n");
	printf("                                                            00000000000000                           \n");
	printf("                                                          000000000000000000                         \n");
	printf("                                                       0000000000000000000000                        \n");
	printf("                                                     0000000000000000000000000                       \n");
	printf("                                                   00"BYE"0000000000000000000"YEL"0000000                      \n");
	printf("                                               "BYE"00000000000000000000000000000"YEL"0000                     \n");
	printf("                                            "BYE"000000"WHI"00000"BYE"00000000000"WHI"0000000"BYE"00000000"YEL"00000               \n");
	printf("                                          "BYE"0000"WHI"00000000000"BYE"000000"WHI"0000000000000"BYE"000000000"YEL"00000           \n");
	printf("                                         "BYE"000"WHI"0000000000000"BYE"00000"WHI"000000000000000"BYE"0000000000"YEL"000000        \n");
	printf("                                         "BYE"00"WHI"000000000000000"BYE"000"WHI"00000000000000000"BYE"000000000"YEL"0000000       \n");
	printf("                                         "BYE"0"WHI"00000000000000000"BYE"00"WHI"00000000000000000"BYE"000000000"YEL"00000         \n");
	printf("                                         "BYE"0"WHI"00000000000000000"BYE"000"WHI"0000000000000000"BYE"0000000000"YEL"00           \n");
	printf("                                        "BYE"000"WHI"00000000"BLA"0000"WHI"0000"BYE"000"WHI"000"BLA"0000"WHI"000000000"BYE"0000000000"YEL"0            \n");
	printf("                                        "BYE"000000"WHI"0000"BLA"000000"WHI"00"BYE "00000"WHI"0"BLA"000000"WHI"000"BYE"000000000000000"YEL"000          \n");
	printf("                                       "BYE"0000000000"WHI"00"BLA"0000"WHI"00"BYE"000000"WHI"00"BLA"0000"WHI"00"BYE"00000000000000000"YEL"00000        \n");
	printf("                                      "BYE"00000000000"WHI"0000000"BYE"000000000"WHI"000000"BYE"00000000000000000"YEL"000          \n");
	printf("                                     "BYE"000000000000000000000000000000000000000000000000000"YEL"0            \n");
	printf("                                     "BYE"0000000000000"RED"000"BYE"000000000000000000"RED"000"BYE"000000000000000            \n");
	printf("                                    "BYE"0000000000000000"RED"000000000000000000000"BYE"00000000000000000           \n");
	printf("                                   "BYE"0000000000000000000"RED"000000000000000000"BYE"00000000"YEL"0"BYE"000000000           \n");
	/*여기가 거기*/printf("                                   "BYE"0000000000"YEL"000"BYE"0000000"RED"000"WHI"00"RED"0000"WHI"00"RED"000"BYE"0000000000"YEL"0"BYE"00000000000          \n");
	printf("                                   "BYE"0000000000000"YEL"00"BYE"000000000000000000000000000"YEL"00"BYE"000000000000          \n");
	printf("                                    "BYE"00000000000000"YEL"00"BYE"000000000000000000000000"YEL"0"BYE"00000000000000          \n");
	printf("                                     "BYE"00000000000000"YEL"0"BYE"0000000000000000000000000"YEL"0"BYE"000000000000""00         \n");
	printf("                                       "BYE"0000000"YEL"00000"BYE"000000000000000000000000000"YEL"0000"BYE"0000000"YEL"0000        \n");
	printf("                                         "BYE"00000000000000000000000000000000000000000000000"YEL"000000       \n");
	printf("                                          "YEL"00000"BYE"0000000000000000000000000000000000000000"YEL"00000000      \n");
	printf("                                           "YEL"0000000"BYE"000000000000000000000000000000"YEL"0000000"YEL"00000000           \n");
	printf("                                           "YEL"00000000000                     000000000000  "YEL"00000000    \n");
	printf("                                           "YEL"0000000000                       00000000000     "YEL"000000          \n");
	printf("                                             "YEL"000000                           0000000                \n"RES);
	printf("                                                                              \n");
	printf("                                                                              \n");
}

void screen_2() {
    printf("                                                                              \n");
    printf("                                                                              \n");
	printf("                                                               "YEL"0000000                               \n");
	printf("                                                            00000000000000                           \n");
	printf("                                                          000000000000000000                         \n");
	printf("                                                       0000000000000000000000                        \n");
	printf("                                                     0000000000000000000000000                       \n");
	printf("                                                   00"BYE"0000000000000000000"YEL"0000000                      \n");
	printf("                                               "BYE"00000000000000000000000000000"YEL"0000                     \n");
	printf("                                            "BYE"000000"WHI"00000"BYE"00000000000"WHI"0000000"BYE"00000000"YEL"00000               \n");
	printf("                                          "BYE"0000"WHI"00000000000"BYE"000000"WHI"0000000000000"BYE"000000000"YEL"00000           \n");
	printf("                                         "BYE"000"WHI"0000000000000"BYE"00000"WHI"000000000000000"BYE"0000000000"YEL"000000        \n");
	printf("                                         "BYE"00"WHI"000000000000000"BYE"000"WHI"00000000000000000"BYE"000000000"YEL"0000000       \n");
	printf("                                         "BYE"0"WHI"00000000000000000"BYE"00"WHI"00000000000000000"BYE"000000000"YEL"00000         \n");
	printf("                                         "BYE"0"WHI"00000000000000000"BYE"000"WHI"0000000000000000"BYE"0000000000"YEL"00           \n");
	printf("                                        "BYE"000"WHI"00000000"BLA"0000"WHI"0000"BYE"000"WHI"000"BLA"0000"WHI"000000000"BYE"0000000000"YEL"0            \n");
	printf("                                        "BYE"000000"WHI"0000"BLA"000000"WHI"00"BYE "00000"WHI"0"BLA"000000"WHI"000"BYE"000000000000000"YEL"000          \n");
	printf("                                       "BYE"0000000000"WHI"00"BLA"0000"WHI"00"BYE"000000"WHI"00"BLA"0000"WHI"00"BYE"00000000000000000"YEL"00000        \n");
	printf("                                      "BYE"00000000000"WHI"0000000"BYE"000000000"WHI"0000000"BYE"0000000000000000"YEL"000          \n");
	printf("                                     "BYE"000000000000000000000000000000000000000000000000000"YEL"0            \n");
	printf("                                     "BYE"0000000000000"RED"00"BYE"00000000000000000000"RED"00"BYE"000000000000000            \n");
	printf("                                    "BYE"0000000000000000"RED"000000000000000000000"BYE"00000000000000000           \n");
	printf("                                   "BYE"0000000000000000000"RED"000000000000000000"BYE"00000000"YEL"0"BYE"000000000           \n");
	printf("                                   "BYE"0000000000"YEL"000000"BYE"0000"RED"000"WHI"00"RED"0000"WHI"00"RED"000"BYE"000000000"YEL"00"BYE"00000000000          \n");
	printf("                                   "BYE"0000000000000000"YEL"00"BYE"0000000000000000000000"YEL"000"BYE"0000000000000          \n");
	printf("                                    "BYE"000000000000000"YEL"00"BYE"000000000000000000000"YEL"0"BYE"0000000000000000          \n");
	printf("                                     "BYE"0000000000000"YEL"00"BYE"0000000000000000000000"YEL"0"BYE"000000000000000""00         \n");
	printf("                                       "BYE"0000000"YEL"000"BYE"00000000000000000000000000"YEL"000"BYE"00000000000"YEL"0000        \n");
	printf("                                         "BYE"00000000000000000000000000000000000000000000000"YEL"0000000       \n");
	printf("                                          "YEL"00000"BYE"0000000000000000000000000000000000000000"YEL"000000000      \n");
	printf("                                           "YEL"0000000"BYE"000000000000000000000000000000"YEL"0000000"YEL"0000000000      \n");
	printf("                                           "YEL"00000000000                     000000000000    "YEL"000000000   \n");
	printf("                                           "YEL"0000000000                       00000000000       "YEL"00000000   \n");
	printf("                                             "YEL"000000                           0000000                \n"RES);
	printf("                                                                              \n");
	printf("                                                                              \n");

}
void screen_3() {
    printf("                                                                              \n");
    printf("                                                                              \n");
	printf("                                                               "YEL"0000000                               \n");
	printf("                                                            00000000000000                           \n");
	printf("                                                          000000000000000000                         \n");
	printf("                                                       0000000000000000000000                        \n");
	printf("                                                     0000000000000000000000000                       \n");
	printf("                                                   00"BYE"0000000000000000000"YEL"0000000                      \n");
	printf("                                               "BYE"00000000000000000000000000000"YEL"0000                     \n");
	printf("                                            "BYE"000000"WHI"00000"BYE"00000000000"WHI"0000000"BYE"00000000"YEL"00000               \n");
	printf("                                          "BYE"0000"WHI"00000000000"BYE"000000"WHI"0000000000000"BYE"000000000"YEL"00000           \n");
	printf("                                         "BYE"000"WHI"0000000000000"BYE"00000"WHI"000000000000000"BYE"0000000000"YEL"000000        \n");
	printf("                                         "BYE"00"WHI"000000000000000"BYE"000"WHI"00000000000000000"BYE"000000000"YEL"0000000       \n");
	printf("                                         "BYE"0"WHI"00000000000000000"BYE"00"WHI"00000000000000000"BYE"000000000"YEL"00000         \n");
	printf("                                         "BYE"0"WHI"00000000000000000"BYE"000"WHI"0000000000000000"BYE"0000000000"YEL"00           \n");
	printf("                                        "BYE"000"WHI"00000000"BLA"0000"WHI"0000"BYE"000"WHI"000"BLA"0000"WHI"000000000"BYE"0000000000"YEL"0            \n");
	printf("                                        "BYE"000"WHI"0000000"BLA"000000"WHI"00"BYE "00000"WHI"0"BLA"000000"WHI"000000"BYE"000000000000"YEL"000          \n");
	printf("                                       "BYE"00000"WHI"0000000"BLA"0000"WHI"00"BYE"000000"WHI"00"BLA"0000"WHI"000000"BYE"0000000000000"YEL"00000        \n");
	printf("                                      "BYE"00000000000"WHI"0000000"BYE"000000000"WHI"0000000000"BYE"0000000000000"YEL"000          \n");
	printf("                                     "BYE"000000000000000000000000000000000000000000000000000"YEL"0            \n");
	printf("                                     "BYE"0000000000000"RED"000"BYE"000000000000000000"RED"000"BYE"000000000000000            \n");
	printf("                                    "BYE"0000000000000000"RED"000000000000000000000"BYE"00000000000000000           \n");
	printf("                                   "BYE"0000000000000000000"RED"000000000000000000"BYE"00000000"YEL"0"BYE"000000000           \n");
	/*여기가 거기*/printf("                                   "BYE"00000000"YEL"00"BYE"0000000000"RED"000"WHI"00"RED"0000"WHI"00"RED"000"BYE"000000000000"YEL"00"BYE"00000000          \n");
	printf("                                   "BYE"000000"YEL"00"BYE"0000000000000000000000000000000000000000"YEL"000"BYE"00000          \n");
	printf("                                    "BYE"0000"YEL"00"BYE"00000000000000000000000000000000000000000000"YEL"0"BYE"0000          \n");
	printf("                                     "BYE"000"YEL"0"BYE"000000000000000000000000000000000000000000000"YEL"0"BYE"000""00         \n");
	printf("                                       "BYE"00"YEL"00000"BYE"00000000000000000000000000000000000"YEL"0000"BYE"000"YEL"0000        \n");
	printf("                                         "BYE"00000000000000000000000000000000000000000000000"YEL"0000000       \n");
	printf("                                          "YEL"00000"BYE"0000000000000000000000000000000000000000"YEL"000000000      \n");
	printf("                                           "YEL"0000000"BYE"000000000000000000000000000000"YEL"0000000"YEL"0000000000      \n");
	printf("                                           "YEL"00000000000                     000000000000    "YEL"000000000   \n");
	printf("                                           "YEL"0000000000                       00000000000       "YEL"00000000   \n");
	printf("                                             "YEL"000000                           0000000                \n"RES);
	printf("                                                                              \n");
	printf("                                                                              \n");


}

void play_intro() {
	PlaySound(TEXT(netmarble), NULL, SND_FILENAME | SND_ASYNC | 1);
}
void play_intro_2() {
	PlaySound(TEXT(netmarble_2), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | 1);
}

void play_intro_3() {
	int choice = rand() % 3;
	if(choice ==0)
		PlaySound(TEXT(netmarble_3), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	if(choice==1)
		PlaySound(TEXT(netmarble_4), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	if(choice==2)
		PlaySound(TEXT(netmarble_5), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void screen_4() {
    printf("                                                                                  \n");
    printf("                                                                                  \n");
    printf("                                                                                  \n");
    printf("                                                                                  \n");
	printf(YEL"                       ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("                        ■■■      ■■    ■■      ■■■      ■■■  ■■■      ■■■  ■■■    ■■■■■\n");
	printf("                         ■■  ■■■■  ■  ■  ■■  ■■  ■■■■■    ■■  ■■■■■    ■■  ■  ■■■■\n");
	printf("                          ■■      ■  ■■  ■      ■■  ■■■■■  ■  ■  ■■■■■  ■  ■  ■■  ■■■\n");
	printf("                           ■■  ■■■  ■  ■  ■  ■■■  ■■■■        ■  ■■■■        ■  ■  ■■■\n");
	printf("                            ■■  ■■■    ■■  ■  ■■■      ■  ■■■  ■      ■  ■■■  ■    ■■■\n");
	printf(BLU"                     ■■■■■■■■■"YEL"■■■■■■■■■■■■■■■■■■■■■■■"BLU"■■■"YEL"■"BLU"■■■■"YEL"■"BLU"■■■■\n");
	printf("                     ■              ■  ■■■■■■■■■■■■■■■■■■■■■■■  ■■■    ■  ■    ■\n");
	printf("                     ■    ■■■    ■■■            ■■■■■■■  ■            ■  ■■■    ■■■    ■\n");
	printf("                     ■    ■■■    ■■    ■■■■■■■      ■■  ■    ■■    ■  ■■■              ■\n");
	printf("                     ■    ■■■    ■■  ■■■■■■■    ■    ■  ■    ■■    ■      ■    ■■■    ■\n");
	printf("                     ■■          ■■■    ■■■■■■■      ■■  ■    ■■    ■  ■■■■          ■■\n");
	printf("                     ■■■■  ■■■■■■            ■■■■■■■  ■■        ■■  ■■■■■■■■■■■■\n");
	printf("                   ■■■■■  ■■■■■■■■■■■■■              ■■■■■■■■  ■■                  ■\n");
	printf("                   ■                                    ■■■■■■  ■            ■  ■■■■■■■■■■■■\n");
	printf("                   ■■■■■■■■■■■■■■  ■■■■■■■■■■  ■            ■■■  ■              ■\n");
	printf("                                             ■  ■                ■■■                    ■■■■■■    ■\n");
	printf("                                             ■■■                                          ■            ■■\n");
	printf("                                                                                             ■    ■■■■■■\n");
	printf("                                                                                             ■■            ■\n");
	printf("                                                                                              ■■■■■■■■\n"RES);
	printf("\n\n                                                         <Press Any Key>");
	getch();
	PlaySound(NULL, 0, 0);
}