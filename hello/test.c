//test.c
//헤더에서 호출된 함수의 기능을 구현함 
#include <stdio.h>
#include <string.h>

#include "INFO.h"


//
//struct qwer test(char* nm, int num) {
//	struct qwer uiop;
//
//	strcpy(uiop.nm, nm);
//	uiop.num = num;
//
//	return uiop;
//}
//
//
//int Print_Human(struct qwer* uiop) {
//	printf("Name : %s \n", uiop->nm);
//	printf("Age : %d \n", uiop->num);
//	return 0;
//}
// 
// 
//test.c

char* typename[100] = { "불꽃타입", "풀타입", "물타입" };



struct my_pok machine(char* name, char* type, int attck, int hp, int rhp) {
	struct my_pok dtc;
	char nm[20];
	char tp[20];
	strcpy(dtc.name, nm);
	strcpy(dtc.type, tp);
	dtc.attck = attck;
	dtc.hp = hp;
	dtc.rhp = rhp;

	return dtc;
}

void read_dict(struct my_pok *dtc) { //불러오기 기능
	FILE* fp = fopen("my_pok_data.txt", "r");
	if (!fp) {
		perror("파일이 없습니다.");
		printf("\n새로 시작해 주세요!\n");
		bar_en;
		return;
	}

	while (fscanf(fp, "%s %s %d %d %d",
		dtc[*worrior_num_p].name,
		dtc[*worrior_num_p].type,
		&dtc[*worrior_num_p].attck,
		&dtc[*worrior_num_p].hp,
		&dtc[*worrior_num_p].rhp) == 5) {
		printf("\n이름 : %s 속성 : %s \n공격력 : %d 체력 : %d 현재 체력 : %d\n",
			dtc[*worrior_num_p].name,
			dtc[*worrior_num_p].type,
			dtc[*worrior_num_p].attck,
			dtc[*worrior_num_p].hp,
			dtc[*worrior_num_p].rhp);
		(*worrior_num_p)++;
		if (*worrior_num_p >= max_pokemon) {
			max_pokemon *= 2;
			my_pok* new_block = realloc(dtc, max_pokemon * sizeof(my_pok));
			if (!new_block) {
				perror("\n저장 공간 부족\n");
				fclose(fp);
				return;
			}
			dtc = new_block;
		}

	}
	*worrior_num_p = 0;
	load_count(count_ptr);
	fclose(fp);
}

int read_dict_in_game(struct my_pok* dtc) {
	FILE* fp = fopen("my_pok_data.txt", "r");
	if (!fp) {
		perror("등록된 포켓몬이 없습니다.");
		bar_en;
		return;
	}
	else {
		while (fscanf(fp, "%s %s %d %d %d",
			dtc[*worrior_num_p].name,
			dtc[*worrior_num_p].type,
			&dtc[*worrior_num_p].attck,
			&dtc[*worrior_num_p].hp,
			&dtc[*worrior_num_p].rhp) == 5) {
			printf("\n이름 : %s 속성 : %s \n공격력 : %d 체력 : %d 현재 체력 : %d\n",
				dtc[*worrior_num_p].name,
				dtc[*worrior_num_p].type,
				dtc[*worrior_num_p].attck,
				dtc[*worrior_num_p].hp,
				dtc[*worrior_num_p].rhp);
			(*worrior_num_p)++;
			if (*worrior_num_p >= max_pokemon) {
				max_pokemon *= 2;
				my_pok* new_block = realloc(dtc, max_pokemon * sizeof(my_pok));
				if (!new_block) {
					perror("\n저장 공간 부족\n");
					fclose(fp);
					return;
				}
				dtc = new_block;
			}

		}
		*worrior_num_p = 0;
		load_count(count_ptr);
		fclose(fp);
		/*for (int i = 0; i < count; i++) {
			int check_worrior = (dtc[i].rhp > 0);
		}*/
	}
}

void plus_pok(int a, struct my_pok* dtc, int *count_ptr) {

	printf("\n플러스 포크 카운트 피티알 : %d\n", *count_ptr);

	int size = 0;
	char new_name[200];

	if (count >= max_pokemon) {
		int new_size = max_pokemon * 2;
		my_pok* temp_ptr = realloc(dtc, new_size * sizeof(my_pok));
		if (!temp_ptr) {
			perror("메모리 할당 실패");
			return;
		}
		dtc = temp_ptr;
		max_pokemon = new_size;
	}

	printf("새 몬스터의 이름을 입력하세요: ");
	scanf("%s", dtc[*count_ptr].name);

	poke_reset(count_ptr, dtc);
	/////////////////////////////////
	printf("\n플러스 포크 카운트 피티알2 : %d\n", *count_ptr);
	
	printf("플러스 포크 카운터에 들어갈 새로운 놈 %s %s %d %d %d\n",
		dtc[*count_ptr].name,
		dtc[*count_ptr].type,
		dtc[*count_ptr].attck,
		dtc[*count_ptr].hp,
		dtc[*count_ptr].rhp);

	printf("\n새로운 몬스터가 등록되었습니다.\n");
	if (a == 1) {
		save_new_pok(dtc, count_ptr);
		(*count_ptr)++;
	}
	else if (a == 2) {
		save_pokmon(dtc, count_ptr);
		(*count_ptr)++;
	}
	save_count(count_ptr);
	return;
}

void save_new_pok(struct my_pok* dtc, int *count_ptr) {
	FILE* fp = fopen("my_pok_data.txt", "w");
	if (!fp) {
		perror("파일을 열 수 없습니다.");
		return;
	}
	printf("\n세이브 뉴 포크 카운트 피티알 : %d\n", *count_ptr);


	for (int i = 0; i < *count_ptr+1; i++) {

		fprintf(fp, "%s %s %d %d %d\n",
			dtc[i].name,
			dtc[i].type,
			dtc[i].attck,
			dtc[i].hp,
			dtc[i].rhp);
		printf("%s %s %d %d %d\n",
			dtc[i].name,
			dtc[i].type,
			dtc[i].attck,
			dtc[i].hp,
			dtc[i].rhp);

	}
	fclose(fp);
	
	printf("세이브 뉴우우 포크몬 몬스터 저장 완료.\n");
	
}

void save_pokmon(struct my_pok* dtc, int* count_ptr) {
	FILE* fp = fopen("my_pok_data.txt", "a");
	if (!fp) {
		perror("파일을 열 수 없습니다.");
		return;
	}
	printf("\n이건 세이브 포크 카운트 피티알 : %d\n", *count_ptr);
	printf("시작 전 포켓몬 상태 %s %s %d %d %d\n",
		enemy_pok_data->name,
		enemy_pok_data->type,
		enemy_pok_data->attck,
		enemy_pok_data->hp,
		enemy_pok_data->rhp);
	
	fprintf(fp, "%s %s %d %d %d\n",
		dtc[*count_ptr].name,
		dtc[*count_ptr].type,
		dtc[*count_ptr].attck,
		dtc[*count_ptr].hp,
		dtc[*count_ptr].rhp);
	printf("저장 후  포켓몬 상태 %s %s %d %d %d\n",
		dtc[*count_ptr].name,
		dtc[*count_ptr].type,
		dtc[*count_ptr].attck,
		dtc[*count_ptr].hp,
		dtc[*count_ptr].rhp);

		fclose(fp);
		
		printf("세이브 포크몬 몬스터 저장 완료.\n");
	}
	

void save_all_pokemon(struct my_pok* dtc, int *count_ptr) {
	FILE* fp = fopen("my_pok_data.txt", "w");
	if (!fp) {
		perror("파일을 열 수 없습니다.");
		return;
	}

	for (int i = 0; i < *count_ptr; i++) {
		fprintf(fp, "%s %s %d %d %d\n",
			dtc[i].name,
			dtc[i].type,
			dtc[i].attck,
			dtc[i].hp,
			dtc[i].rhp);
	}

	fclose(fp);
	save_count(count_ptr);
	printf("세이브 올 포크몬 모든 몬스터 데이터가 저장되었습니다.\n");
}




void poke_reset(int* count_ptr, struct my_pok* dtc) {
	int type_num = rand() % 3;
	int att = rand() % 100 + 1;
	int H = rand() % 200 + 100;
	int R = H - rand() % 15;

	strcpy(dtc[*count_ptr].type, typename[type_num]);
	dtc[*count_ptr].attck = att;
	dtc[*count_ptr].hp = H;
	dtc[*count_ptr].rhp = R;
}



 
////-----------------------------------------------
////
//
//// test.c
