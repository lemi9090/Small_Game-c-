//hello.c
//���� ����ϴ� ��ũ��Ʈ 
// ����� ȣ��

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

	printf("�ʱ�ȭ��\n");
	bar_en;
	printf("Bon Poketmon Game");
	bar_en;
	printf("\n1. �����ϱ� 2. �ҷ�����");
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

	printf("a�� : %d\n", a);
	do {
		bar_en;
		printf("�� �Ͻðڽ��ϱ�?");
		en;
		printf("\n1. ������ ������! 2. ���� 3. ���� 4. ���ϸ��� 5. ���ϸ� ���� 6.����");
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
			printf("\n����!\n");
			printf("\n3������ �����ϴ� ī��Ʈ ��Ƽ�� %d\n", *count_ptr);
			save_all_pokemon(my_pok_ptr, count_ptr);
			
			display_wimb();
			break;
		}
		case 4: {
			//pok_center();
		}

		case 5: {
			printf("\n���� �� �� game\n");
			read_dict_in_game(my_pok_ptr, count_ptr);
			
			break;
		}

		}
	} while (choice != 6);
	en;
	printf("�����ϼ̳���?\n1. ��! 2. �ƴϿ�\n");
	scanf("%d", &b);
	if (b == 1) {
		printf("������ �� ������!");
		exit(1);
	}
	else {
		printf("�� �ϰ� ������!");
		en;
		play_Game(a);
	}
}