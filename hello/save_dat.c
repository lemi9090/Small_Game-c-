//save_dat.c
#include "INFO.h"
#include <stdio.h>
#include <stdlib.h>
#define bar_en printf("\n=================================================\n");

what_in_my_bag wimb;

void display_wimb() { // 이건 가방 저장 함수
	FILE* fp = fopen("my_bag_data.txt", "w");
	if (!fp) {
		perror("파일을 열 수 없습니다.displya");
		return;
	}
	fprintf(fp, "%d %d %d\n", wimb.money, wimb.ball, wimb.para);
	
	printf("\n현재 가방에는 돈:  %d 몬스터볼 : %d 만병통치약 :%d 이 들어 있습니다!\n", wimb.money, wimb.ball, wimb.para);
	bar_en;
	fclose(fp);
}

void read_wimb() { // 저장된 가방 읽기. 
	FILE* fp = fopen("my_bag_data.txt", "r");
	if (!fp) {
		perror("파일을 열 수 없습니다.read");
		return;
	}
	fscanf(fp, "%d %d %d", &wimb.money, &wimb.ball, &wimb.para);
	bar_en;
	printf("\n저장된 가방에는 = 돈:  %d 몬스터볼 : %d 만병통치약 :%d 이 들어 있습니다!\n", wimb.money, wimb.ball, wimb.para);
	bar_en;
	fclose(fp);
}

void save_count(int* count_ptr) {
	FILE* fp = fopen("my_pok_data2.txt", "w");
	if (!fp) {
		perror("파일을 열 수 없습니다.display");
		return;
	}
	fprintf(fp, "%d\n", *count_ptr);

	printf("\n불러온 카운트 피티알 : %d\n", *count_ptr);
	bar_en;
	fclose(fp);
}


void load_count(int* count_ptr) {
	FILE* fp = fopen("my_pok_data2.txt", "r");
	if (!fp) {
		perror("파일을 열 수 없습니다.display");
		return;
	}

	fscanf(fp, "%d", count_ptr);

	printf("\n불러온 카운트 피티알 : %d\n", *count_ptr);
	bar_en;
	fclose(fp);
}
