//gogo_advan.c
#include "INFO.h"
#include <stdio.h>
#include<string.h> 
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#define bar_en printf("\n=================================================\n");

int worrior_num = 0;
int *worrior_num_p = &worrior_num;

my_pok enemy_pok;
my_pok* enemy_pok_data = &enemy_pok;

what_in_my_bag wimb;

void warning();
void what_do(int* worrior_num_p);
void print_f_pok(int* worrior_num_p);
void load_pok(int* worrior_num_p);
void attack(int* worrior_num_p, int c);
void reverse_attack(int* worrior_num_p, int c);
void critical(int* worrior_num_p);
void battle(int* worrior_num_p);
int run_away(int* worrior_num_p);
int death_pok(int* worrior_num_p, int* result_p);


void walking() {
    srand((unsigned)time(NULL));
    int walk = rand() % 4 + 1;
    bar_en;
    printf("���� �� .. ���� �� ... ���� �� ...\n");
    bar_en;
    fflush(stdout);
    Sleep(walk * 1000);

}



void warning() {
    int type_num = rand() % 3;
    int att = rand() % 100 + 1;
    int H = rand() % 200 + 100;
    int R = H - rand() % 15;

    enemy_pok_data->attck = att;
    enemy_pok_data->hp = H;
    enemy_pok_data->rhp = R;
    int attr_index = rand() % 3;

    const char* attributes[3] = { "�Ҳ�Ÿ��", "ǮŸ��", "��Ÿ��" };
    strcpy(enemy_pok_data->name, "�߻��� ���ϸ�");
    strcpy(enemy_pok_data->type, attributes[attr_index]);

    bar_en;
    printf("                               �߻��� ���ϸ��� ��Ÿ����!\n");
    printf("                                 �ɷ�ġ�� ��Ȯ���� �ʴ�..!\n");
    printf("\n                                 �Ӽ� : %s \n                                 ü�� : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
    printf("                                 ���� ü�� : %d\n                                 ���ݷ� : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);
    bar_en;
    return;
}


void load_pok(int *worrior_num_p) {
    printf("\n�ε��Դϴ�~~~\n");
    printf("Warrior %d: �̸�=%s, �Ӽ�=%s, ���ݷ�=%d, ü��=%d, ���� ü��=%d\n",
        *worrior_num_p +1, my_pok_ptr[*worrior_num_p].name, my_pok_ptr[*worrior_num_p].type, my_pok_ptr[*worrior_num_p].attck, my_pok_ptr[*worrior_num_p].hp, my_pok_ptr[*worrior_num_p].rhp);
    printf("\n�ε� ��!\n");
    return;
}


void print_f_pok(int* worrior_num_p) {
    printf("\n����Ʈ ���� ī��Ʈ : %d \n", *worrior_num_p);
    bar_en;
    printf("\n                               �߻��� ���ϸ�\n");
    printf("\n                                 �Ӽ� : %s \n                                 ü�� : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
    printf("                                 ���� ü�� : %d\n                                 ���ݷ� : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);

 
    printf("Warrior %d: �̸�=%s, \n�Ӽ�=%s,  ü��=%d, \n���ݷ�=%d, ���� ü��=%d\n",
        *worrior_num_p + 1, my_pok_ptr[*worrior_num_p].name, my_pok_ptr[*worrior_num_p].type, my_pok_ptr[*worrior_num_p].hp, my_pok_ptr[*worrior_num_p].attck, my_pok_ptr[*worrior_num_p].rhp);
    bar_en;
    return;
}

void attack(int* worrior_num_p, int c) {
    printf("\n ���� ī��Ʈ : %d \n", *worrior_num_p);
    int m_attck = my_pok_ptr[*worrior_num_p].attck * 0.2;
    int e_attck = enemy_pok_data->attck * 0.2;

    enemy_pok_data->rhp -= (rand() % (m_attck + c));
    my_pok_ptr[*worrior_num_p].rhp -= (rand() % (e_attck + c));
    return;
}

void reverse_attack(int* worrior_num_p, int c) {
    printf("\n������ ���� ī��Ʈ : %d \n", *worrior_num_p);
    int m_attck = my_pok_ptr[*worrior_num_p].attck * 0.2;
    int e_attck = enemy_pok_data->attck * 0.2;

    enemy_pok_data->rhp -= (rand() % (m_attck + c));
    my_pok_ptr[*worrior_num_p].rhp -= (rand() % (e_attck + c));
    return;
}


void critical(int *worrior_num_p) {
    printf("\n���� �Լ� �Դϴ�~~\n");
    printf("\nũ��Ƽ�� ī��Ʈ : %d \n", *worrior_num_p);
    int sun = rand() % 2;
    int en_type_num, my_type_num, c = 0;
    int critical = 20;
    int critical2 = 30;

    char* type[] = { "ǮŸ��", "�Ҳ�Ÿ��",  "��Ÿ��" };


    for (int i = 0; i < 3; i++) {
        if (strcmp(type[i], enemy_pok_data->type) == 0) {
            en_type_num = i;
            break;
        }
    }

    for (int k = 0; k < 3; k++) {
        if (strcmp(type[k], my_pok_ptr[*worrior_num_p].type) == 0) {
            my_type_num = k;
            break;
        }
    }

    if (en_type_num > my_type_num) {
        c = critical;
        printf("\n�� �켼!\n");
        if (sun == 0) {
            printf("\n�츮�� ���� ��������!\n");
            printf("\n�츮�� ���� �������� ī��Ʈ : %d \n", *worrior_num_p);
            attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
        else {
            printf("\n��� ���� ����!\n");
            printf("\n��� ���� ���� ī��Ʈ : %d \n", *worrior_num_p);
            reverse_attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }

    }
    else if (en_type_num < my_type_num) {
        c = critical2;
        printf("\nũ��Ƽ��!!!\n");
        if (sun == 0) {
            printf("\n�츮�� ���� ��������!\n");
            printf("\n�츮�� ���� �������� ī��Ʈ : %d \n", *worrior_num_p);
            attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
            printf("\n ȿ���� �����ߴ�\n");
            
        }
        else {
            printf("\n��� ���� ����!\n");
            printf("\n��� ���� ���� ī��Ʈ : %d \n", *worrior_num_p);
            reverse_attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
    }
    else {
        printf("\n���� Ÿ��\n");
        c = 10;
        if (sun == 0) {
            printf("\n�츮�� ���� ��������!\n");
            attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
        else {
            printf("\n��� ���� ����!\n");
            reverse_attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
    }

    return;
}



void battle(int* worrior_num_p) {
    bar_en;
    printf("���Ͷ� %s!\n", my_pok_ptr[*worrior_num_p].name);
    
    printf("\n ��Ʋ �Լ� ī��Ʈ : %d \n", *worrior_num_p);
 
    critical(worrior_num_p);

    printf("\n��Ʋ ���� �� �ٽ� �������� �� �η� �Ѿ �� ī��Ʈ : %d \n", *worrior_num_p);
    return;
}

int death_pok(int * worrior_num_p, int *result_p) {
    int T_ch = 0;
    printf("\n����Ͻðڽ��ϱ�?\n 1. �� 2. �ƴϿ�\n");
    scanf("%d", &T_ch);

    printf("\n���� ���� ī��Ʈ : %d \n", *worrior_num_p);

    if (T_ch == 1) {
        ++(*worrior_num_p);
        printf("\n���� ���� �� �����ߴ��� Ȯ���ϴ� ���� ī��Ʈ : %d \n", *worrior_num_p);
        //battle(count);
    }
    else if (T_ch == 2) {
        printf("\n��밡 �ʹ� ���ϴ�..! ��������!\n");
        int escape = run_away(*worrior_num_p);

        if (escape == 0) {
            ++(*worrior_num_p);
            printf("\n���� ���� ����ġ�� ������ ��¿ �� ���� �ο�� ���� �����Ǵ� ī��Ʈ : %d \n", *worrior_num_p);
            *result_p = 0;
        }
        else if (escape == 1) {
            *result_p = 1;
            
        }
    }
    return *worrior_num_p;
}

int run_away(int* worrior_num_p) {
    int run_run = rand() % 10 + 1;
   if (run_run > 5) {
            printf("\n���������� �����ƴ�!\n");
            return 1;  // ���� ����
        }
        else {
            printf("\n���� ����..!\n");
            //++(*worrior_num_p);  // Correctly increment the actual count
            //printf("\n����ġ�� �����ؼ� ��¿ �� ���� �ο�� ���� �����Ǵ� ī��Ʈ : %d \n", *worrior_num_p);
            //battle(count);  // Pass the pointer, not the value
            return 0;  // ���� ����
        }
}

int item_use_mosterball() {
    printf("���ͺ� ���!\n");
    int pok_ball = rand() % 4 + 1;
    wimb.ball -= 1;
  
    if (pok_ball >= 3) {
        printf("\n%s�� ��Ҵ�! �� ���ž�!\n", enemy_pok_data->name);
        return 1;
    }
    else {
        printf("\n��..! ���� ���� ���ȴ�..!\n");
        return 0;
    }
}


void what_do(int* worrior_num_p) {
    int choice;
    int item_use;
    printf("�� �� ī��Ʈ  : % d\n", *worrior_num_p);
    printf("�� �� ī��Ʈ ����ü�� : %d\n", my_pok_ptr[*worrior_num_p].rhp);
    int result = 0;
    int *result_p = &result;

    do {
        printf("\n�� �ұ� ?\n1. ���� 2. ���濭�� 3. ����ġ��\n");
        scanf("%d", &choice);

        load_pok(worrior_num_p); // �����

        switch (choice) {
        case 1:
            if (enemy_pok_data->rhp > 0 && my_pok_ptr[*worrior_num_p].rhp > 0) {
                printf("\n�ο���!\n");
                printf("\n�� �ο��� �޴� ī��Ʈ : %d \n", *worrior_num_p);
                battle(worrior_num_p);// �Լ��� ȣ���� �� *�� �ٿ��� ȣ���ϸ� **worrior_num_p�� ȣ���ϴ� �Ͱ� ����. 
            }
           else if (enemy_pok_data->rhp <= 0 && my_pok_ptr[*worrior_num_p].rhp > 0) {
                printf("\n������ �����߷ȴ�!!\n");
                save_all_pokemon(my_pok_ptr, count_ptr);
                result = 1;

            }
            else if (my_pok_ptr[*worrior_num_p].rhp <= 0 && enemy_pok_data->rhp > 0) {
                printf("ī��Ʈ %d\n", *worrior_num_p);
                printf("my_pok%d\n", my_pok_ptr[*worrior_num_p].rhp);
                printf("enemy_ data %d\n", enemy_pok_data->rhp);

                printf("\n������ ����������..!\n");

                printf("\n���ڸ��� ù �ӵο��� ī��Ʈ ���� : %d \n", *worrior_num_p);
                death_pok(worrior_num_p, result_p);
                if (*result_p == 1) {
                    save_all_pokemon(my_pok_ptr, count_ptr);
                    result = 1;
                }
                printf("\n���� ��ũ���� ���� ī��Ʈ �� �ӵο��� ī��Ʈ ���� �̰� ��Ʋ�� �Ѿ�� ��(�����Ǿ� �־�� ��): %d \n", *worrior_num_p);
                if (my_pok_ptr[*worrior_num_p].rhp < 0 || my_pok_ptr[*worrior_num_p].rhp>300) {
                    printf("\n��� ���ϸ��� �����߽��ϴ�....\nó������ ���ư��ϴ�.\n");
                    save_all_pokemon(my_pok_ptr, count_ptr);
                    result = 1;
                }
 
             /*   if ((strcmp(my_pok_ptr[*worrior_num_p].name, "") == 0)) {
                    
                }*/
            }
            break;

        case 2:
            printf("������ ������!\n");
            printf("���ҷ�?\n");
            read_wimb();
            printf("1. ���ͺ��� ����! 2. ��ó���� ����!\n");
            scanf("%d", &item_use);


            if (item_use == 1) {
                if (wimb.ball > 0) {
                    if (item_use_mosterball() == 1) {
                        plus_pok(a, my_pok_ptr, count_ptr);
                        result = 1;
                    }
                }
                else {
                    printf("\n���ͺ��� �����մϴ�\n");
                }

            }
            else if (item_use == 2) {
                if (wimb.para > 0) {
                    printf("\n�ְ��� ������ġ�� ���!!\n");
                    //heal_pok(worrior_num_p);
                    wimb.para -= 1;;
                    printf("���� ���ϸ� ����: rhp=%d, hp=%d\n", my_pok_ptr[*worrior_num_p].rhp, my_pok_ptr[*worrior_num_p].hp);
                    my_pok_ptr[*worrior_num_p].rhp = my_pok_ptr[*worrior_num_p].hp;
                    printf("ȸ�� ���: rhp=%d, hp=%d\n", my_pok_ptr[*worrior_num_p].rhp, my_pok_ptr[*worrior_num_p].hp);
                }
                else {
                    printf("\n��..���� ���µ���?\n");
                }
            }
            display_wimb();
            break;


        case 3:
            printf("\n�����ľ� �� !!!!!\n");
            if (run_away(worrior_num_p) == 1) {
                result = 1;
            }
            break;
        }

    } while (result != 1);
    
    printf("what_do ��������\n\n");
    play_Game(a);
}







int gogo_advanture() {
    //int count = 0;
    //int* worrior_num_p = &count;
    //read_dict2(worrior_num_p); // �̰� �������. �ϼ��Ǹ� ó���� ������ ���� �о my_pok�� �����Ŵϱ� ���� �ڵ� ��������� ���� ��.
    walking();
    warning();
    printf("��� ������ : %d\n", *worrior_num_p);
    what_do(worrior_num_p);
    printf("\n�׽�Ʈ ���� \n�׽�Ʈ ����\n"); //�׽�Ʈ �Ϸ� -> ���� ���(��, Ÿ�� ġ��Ÿ Ȯ��), ����ġ�� ���� �Ϸ� -> �����̶� �����ؾ� ��.
    *worrior_num_p = 0;
    
    return 0;
}





// ������ �ѹ� �� �ʱ�ȭ �ʿ�, �����̰ų� 200 �̻��̸� ���� ���ϸ��� ���ٰ� �ϴ��� ��ġ �ʿ�
// printf("\n���� ��ũ���� ���� ī��Ʈ �� �ӵο��� ī��Ʈ ���� �̰� ��Ʋ�� �Ѿ�� ��(�����Ǿ� �־�� ��): %d \n", *worrior_num_p);
// ���ϸ� ���� ���� �ʿ�


