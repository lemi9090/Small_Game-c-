//test.c
//������� ȣ��� �Լ��� ����� ������ 
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

char* typename[100] = { "�Ҳ�Ÿ��", "ǮŸ��", "��Ÿ��" };



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

void read_dict(struct my_pok *dtc) { //�ҷ����� ���
	FILE* fp = fopen("my_pok_data.txt", "r");
	if (!fp) {
		perror("������ �����ϴ�.");
		printf("\n���� ������ �ּ���!\n");
		bar_en;
		return;
	}

	while (fscanf(fp, "%s %s %d %d %d",
		dtc[*worrior_num_p].name,
		dtc[*worrior_num_p].type,
		&dtc[*worrior_num_p].attck,
		&dtc[*worrior_num_p].hp,
		&dtc[*worrior_num_p].rhp) == 5) {
		printf("\n�̸� : %s �Ӽ� : %s \n���ݷ� : %d ü�� : %d ���� ü�� : %d\n",
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
				perror("\n���� ���� ����\n");
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
		perror("��ϵ� ���ϸ��� �����ϴ�.");
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
			printf("\n�̸� : %s �Ӽ� : %s \n���ݷ� : %d ü�� : %d ���� ü�� : %d\n",
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
					perror("\n���� ���� ����\n");
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

	printf("\n�÷��� ��ũ ī��Ʈ ��Ƽ�� : %d\n", *count_ptr);

	int size = 0;
	char new_name[200];

	if (count >= max_pokemon) {
		int new_size = max_pokemon * 2;
		my_pok* temp_ptr = realloc(dtc, new_size * sizeof(my_pok));
		if (!temp_ptr) {
			perror("�޸� �Ҵ� ����");
			return;
		}
		dtc = temp_ptr;
		max_pokemon = new_size;
	}

	printf("�� ������ �̸��� �Է��ϼ���: ");
	scanf("%s", dtc[*count_ptr].name);

	poke_reset(count_ptr, dtc);
	/////////////////////////////////
	printf("\n�÷��� ��ũ ī��Ʈ ��Ƽ��2 : %d\n", *count_ptr);
	
	printf("�÷��� ��ũ ī���Ϳ� �� ���ο� �� %s %s %d %d %d\n",
		dtc[*count_ptr].name,
		dtc[*count_ptr].type,
		dtc[*count_ptr].attck,
		dtc[*count_ptr].hp,
		dtc[*count_ptr].rhp);

	printf("\n���ο� ���Ͱ� ��ϵǾ����ϴ�.\n");
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
		perror("������ �� �� �����ϴ�.");
		return;
	}
	printf("\n���̺� �� ��ũ ī��Ʈ ��Ƽ�� : %d\n", *count_ptr);


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
	
	printf("���̺� ����� ��ũ�� ���� ���� �Ϸ�.\n");
	
}

void save_pokmon(struct my_pok* dtc, int* count_ptr) {
	FILE* fp = fopen("my_pok_data.txt", "a");
	if (!fp) {
		perror("������ �� �� �����ϴ�.");
		return;
	}
	printf("\n�̰� ���̺� ��ũ ī��Ʈ ��Ƽ�� : %d\n", *count_ptr);
	printf("���� �� ���ϸ� ���� %s %s %d %d %d\n",
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
	printf("���� ��  ���ϸ� ���� %s %s %d %d %d\n",
		dtc[*count_ptr].name,
		dtc[*count_ptr].type,
		dtc[*count_ptr].attck,
		dtc[*count_ptr].hp,
		dtc[*count_ptr].rhp);

		fclose(fp);
		
		printf("���̺� ��ũ�� ���� ���� �Ϸ�.\n");
	}
	

void save_all_pokemon(struct my_pok* dtc, int *count_ptr) {
	FILE* fp = fopen("my_pok_data.txt", "w");
	if (!fp) {
		perror("������ �� �� �����ϴ�.");
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
	printf("���̺� �� ��ũ�� ��� ���� �����Ͱ� ����Ǿ����ϴ�.\n");
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
