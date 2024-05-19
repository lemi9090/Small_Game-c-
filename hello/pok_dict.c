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
	printf("%리셋 카운트\n");
	my_pok_ptr = (my_pok*)malloc(INITIAL_MAX_POKEMON * sizeof(my_pok));
	if (!my_pok_ptr) {
		perror("메모리 할당 실패");
		exit(EXIT_FAILURE);
	}
}

void free_memory() {
	free(count_ptr);
}

int pok_dict_main(a) {
	printf("포크 딕트 : %d\n", a);
	if (a == 1) {
		reset_count();
		printf("포크딕22\n");
		plus_pok(a, my_pok_ptr, count_ptr);
		
		//play_Game(a);
		return;
	}

	else if (a == 2) { //불러오기 기능
		bar_en;
		read_dict(my_pok_ptr, count_ptr);
		bar_en;
	}
	//else if (a==3) { // 저장하기
	//	
	//	
	//	//free_memory(); // 이거 주석처리하면 이상하게 포켓몬 저장이 이상한 놈이 또 생김. 
	//}

	
	return 0;
}

