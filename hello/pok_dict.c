//pok_dict.c

#include "INFO.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
#define bar_en printf("\n=================================================\n");
#define en printf("\n")

extern int play_Game(int);
extern int main();

void free_memory();

void reset_count() {
	printf("%���� ī��Ʈ\n");
	my_pok_ptr = (my_pok*)malloc(INITIAL_MAX_POKEMON * sizeof(my_pok));
	if (!my_pok_ptr) {
		perror("�޸� �Ҵ� ����");
		exit(EXIT_FAILURE);
	}
}

void free_memory() {
	free(count_ptr);
}

int pok_dict_main(a) {
	printf("��ũ ��Ʈ : %d\n", a);
	if (a == 1) {
		reset_count();
		printf("��ũ��22\n");
		plus_pok(a, my_pok_ptr, count_ptr);
		
		//play_Game(a);
		return;
	}

	else if (a == 2) { //�ҷ����� ���
		bar_en;
		read_dict(my_pok_ptr, count_ptr);
		bar_en;
	}
	//else if (a==3) { // �����ϱ�
	//	
	//	
	//	//free_memory(); // �̰� �ּ�ó���ϸ� �̻��ϰ� ���ϸ� ������ �̻��� ���� �� ����. 
	//}

	
	return 0;
}

