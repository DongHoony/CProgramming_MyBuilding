#include "../header_files/ending.h"
#include <stdio.h>
#include <memory.h>

void open_word(End e[]){
	FILE* pfile=NULL;
	//char str[100];
	//char* pstr;
	int i = 0;
	pfile=fopen("..\\data\\ending_credit.txt","r");
	for(i = 0; i < 50; i++){
		if(fgets(e[i].word, sizeof(e[i].word), pfile) == NULL) break;
		//if(i>1) printf("%s",e[i-1].word);
    }
	fclose(pfile);
}
void open_x(End e[]){
	FILE* pfile;
	int i = 0;
	pfile = fopen("..\\data\\x_pos.txt", "r");
	for(i = 0; i < 50; i++){
		fscanf(pfile, "%d", &e[i].x_pos);
    }
	fclose(pfile);
}
void open_y(End e[]){
	FILE* pfile;
	int i = 0;
	pfile = fopen("..\\data\\y_pos.txt","r");
	for(i = 0; i < 50; i++){
		fscanf(pfile, "%d", &e[i].y_pos);
    }
	fclose(pfile);
}