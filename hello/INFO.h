// �Լ����� ȣ����. ����� ����ü�� �̸� ���� 
//INFO.h

//typedef struct qwer {
//	char nm[20];
//	int num;
//};

//
//struct qwer test(char* nm, int num);
//int Print_Human(struct qwer* uiop);
//-----------------------------------------------
//INFO.h

#pragma once

#include <stdio.h>
#define INITIAL_MAX_POKEMON 10
#define bar_en printf("\n=================================================\n");


//�������� -------------------------------------------
extern int max_pokemon;
extern int count ;
extern int* count_ptr;
extern int a;

typedef struct my_pok {
    char name[20];
    char type[20];
    int attck;
    int hp;
    int rhp;
} my_pok;


typedef struct  what_in_my_bag {
	int money;
	int ball;
	int para;
}what_in_my_bag;

///////////////////////////////////////////

//�������� -------------------------------------------

extern what_in_my_bag wimb;
extern what_in_my_bag* wimb_ptr;
extern int worrior_num ;
extern int* worrior_num_p;
extern my_pok my_pok_data[INITIAL_MAX_POKEMON];
extern my_pok* my_pok_ptr;
extern my_pok enemy_pok;
extern my_pok* enemy_pok_data;
//�������� -------------------------------------------




extern struct my_pok machine(char* name, char* type, int attck, int hp, int rhp);


void read_dict(struct my_pok* dtc);
int read_dict_in_game(struct my_pok* dtc);
void plus_pok(int a, struct my_pok* dtc);

void poke_reset(int *count_ptr, struct my_pok* dtc);
void save_pokmon(struct my_pok* dtc, int * count_ptr);
void save_new_pok(struct my_pok* dtc, int* count_ptr);
void save_all_pokemon(struct my_pok* dtc, int* count_ptr);

void R_shopping(int);
void display_wimb();
void read_wimb();
void save_count(int* count_ptr);
void load_count(int* count_ptr);
/////////////////////////////////////////////////

//
//void read_dict(struct my_pok* dtc, int* count_ptr) {
//    FILE* fp = fopen("my_pok_data.txt", "r");
//    if (!fp) {
//        perror("������ �����ϴ�.");
//        printf("\n���� ����3�� �ּ���!\n");
//        return;
//    }
//
//    // ���� ���Ͽ��� ���ϸ��� ���� �н��ϴ�.
//    if (fscanf(fp, "%d", count_ptr) != 1) {
//        perror("���ϸ� ������ �дµ� �����߽��ϴ�.");
//        fclose(fp);
//        return;
//    }
//
//    int index = 0;
//    while (index < *count_ptr && fscanf(fp, "%s %s %d %d %d",
//        dtc[index].name,
//        dtc[index].type,
//        &dtc[index].attck,
//        &dtc[index].hp,
//        &dtc[index].rhp) == 5) {
//        printf("\n�̸� : %s �Ӽ� : %s \n���ݷ� : %d ü�� : %d ���� ü�� : %d\n",
//            dtc[index].name,
//            dtc[index].type,
//            dtc[index].attck,
//            dtc[index].hp,
//            dtc[index].rhp);
//        index++;
//    }
//
//    fclose(fp);
//}
//
//// ���� ���ϸ��� ���� �����մϴ�.
//fprintf(fp, "%d\n", count);
//for (int i = 0; i < count; i++) {
//    fprintf(fp, "%s %s %d %d %d\n",
//        dtc[i].name,
//        dtc[i].type,
//        dtc[i].attck,
//        dtc[i].hp,
//        dtc[i].rhp);
//}
//fclose(fp);