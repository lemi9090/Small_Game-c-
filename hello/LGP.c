//hello.c
//실제 사용하는 스크립트 
// 헤더만 호출

//#include <stdio.h>
//#include "INFO.h"

 //int main() {
 //   struct qwer iiii = test("Lee", 40);

 //   Print_Human(&iiii);

 //   return 0;
 //}
//-----------------------------------------------

//LGP.c
#include <stdio.h>
#include <string.h>

#include "INFO.h"

#define en printf("\n")
#define bar_en printf("\n=================================================\n");

int a;
int count = 0;
int* count_ptr = &count;

my_pok my_pok_data[INITIAL_MAX_POKEMON];
my_pok* my_pok_ptr = my_pok_data;

int max_pokemon = INITIAL_MAX_POKEMON;

what_in_my_bag wimb = { 1000, 5, 0 };
what_in_my_bag* wimb_ptr = &wimb;

void play_Game(int);
extern void R_shopping(int);
extern void pok_dict_main(int);
//extern void display_wimb();
//extern void read_wimb();
extern int gogo_advanture();

int main() {

	printf("초기화면\n");
	bar_en;
	printf("Bon Poketmon Game");
	bar_en;
	printf("\n1. 새로하기 2. 불러오기");
	en;
	scanf("%d", &a);
	if (a == 1) {
		display_wimb();
		pok_dict_main(a);
	}
	else if (a == 2) {
		pok_dict_main(a);
		read_wimb();
	}

	bar_en;

	play_Game(a);
}

void play_Game(int a) {
	int choice, b;

	printf("a값 : %d\n", a);
	do {
		bar_en;
		printf("뭘 하시겠습니까?");
		en;
		printf("\n1. 모험을 떠나자! 2. 상점 3. 저장 4. 포켓몬센터 5. 포켓몬 도감 6.종료");
		bar_en;
		scanf("%d", &choice);
		switch (choice) {
		case 1: {
			gogo_advanture();
			break;
		}
		case 2: {
			
			display_wimb();
			R_shopping(a);
			break;
		}
		case 3: {
			printf("\n저장!\n");
			printf("\n3번눌러 저장하는 카운트 피티알 %d\n", *count_ptr);
			save_all_pokemon(my_pok_ptr, count_ptr);
			
			display_wimb();
			break;
		}
		case 4: {
			//pok_center();
		}

		case 5: {
			printf("\n리드 딕 인 game\n");
			read_dict_in_game(my_pok_ptr, count_ptr);
			
			break;
		}

		}
	} while (choice != 6);
	en;
	printf("저장하셨나요?\n1. 예! 2. 아니오\n");
	scanf("%d", &b);
	if (b == 1) {
		printf("다음에 또 만나요!");
		exit(1);
	}
	else {
		printf("얼른 하고 오세요!");
		en;
		play_Game(a);
	}
}