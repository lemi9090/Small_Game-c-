//save_dat.c
#include "INFO.h"
#include <stdio.h>
#include <stdlib.h>
#define bar_en printf("\n=================================================\n");

what_in_my_bag wimb;

void display_wimb() { // �̰� ���� ���� �Լ�
	FILE* fp = fopen("my_bag_data.txt", "w");
	if (!fp) {
		perror("������ �� �� �����ϴ�.displya");
		return;
	}
	fprintf(fp, "%d %d %d\n", wimb.money, wimb.ball, wimb.para);
	
	printf("\n���� ���濡�� ��:  %d ���ͺ� : %d ������ġ�� :%d �� ��� �ֽ��ϴ�!\n", wimb.money, wimb.ball, wimb.para);
	bar_en;
	fclose(fp);
}

void read_wimb() { // ����� ���� �б�. 
	FILE* fp = fopen("my_bag_data.txt", "r");
	if (!fp) {
		perror("������ �� �� �����ϴ�.read");
		return;
	}
	fscanf(fp, "%d %d %d", &wimb.money, &wimb.ball, &wimb.para);
	bar_en;
	printf("\n����� ���濡�� = ��:  %d ���ͺ� : %d ������ġ�� :%d �� ��� �ֽ��ϴ�!\n", wimb.money, wimb.ball, wimb.para);
	bar_en;
	fclose(fp);
}

void save_count(int* count_ptr) {
	FILE* fp = fopen("my_pok_data2.txt", "w");
	if (!fp) {
		perror("������ �� �� �����ϴ�.display");
		return;
	}
	fprintf(fp, "%d\n", *count_ptr);

	printf("\n�ҷ��� ī��Ʈ ��Ƽ�� : %d\n", *count_ptr);
	bar_en;
	fclose(fp);
}


void load_count(int* count_ptr) {
	FILE* fp = fopen("my_pok_data2.txt", "r");
	if (!fp) {
		perror("������ �� �� �����ϴ�.display");
		return;
	}

	fscanf(fp, "%d", count_ptr);

	printf("\n�ҷ��� ī��Ʈ ��Ƽ�� : %d\n", *count_ptr);
	bar_en;
	fclose(fp);
}
