//
////advanture.c
//#include "INFO.h"
//#include <stdio.h>
//#include<string.h> 
//#include <stdlib.h>
//#include <time.h>
//#include <Windows.h>
//#define bar_en printf("\n=================================================\n");
//#define max_warrior 100
//
//my_pok my_pok_data[INITIAL_MAX_POKEMON];
//my_pok* my_pok_battle = my_pok_data;
//
//my_pok enemy_pok;
//my_pok* enemy_pok_data = &enemy_pok;
//
//extern int a;
//
//extern void read_dict_in_game();
//extern void play_Game(int);
//
//void walking();
//void warning();
//void what_do();
//void print_f_pok(int count);
//void load_pok(int count);
//void attack(int count, int c);
//void reverse_attack(int count, int c);
//void critical(int count);
//void battle(int count);
//int run_away(int count);
//
//
//void walking() {
//    srand((unsigned)time(NULL));
//    int walk = rand() % 4 + 1;
//    bar_en;
//    printf("���� �� .. ���� �� ... ���� �� ...\n");
//    bar_en;
//    fflush(stdout);
//    Sleep(walk * 1000);
//
//}
//
//void warning() {
//    int type_num = rand() % 3;
//    int att = rand() % 100 + 1;
//    int H = rand() % 200 + 100;
//    int R = H - rand() % 15;
//
//    enemy_pok_data->attck = att;
//    enemy_pok_data->hp = H;
//    enemy_pok_data->rhp = R;
//    int attr_index = rand() % 3;
//
//    const char* attributes[3] = { "�Ҳ�Ÿ��", "ǮŸ��", "��Ÿ��" };
//    strcpy(enemy_pok_data->name, "�߻��� ���ϸ�");
//    strcpy(enemy_pok_data->type, attributes[attr_index]);
//
//    bar_en;
//    printf("                               �߻��� ���ϸ��� ��Ÿ����!\n");
//    printf("\n                                 �Ӽ� : %s \n                                 ü�� : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
//    printf("                                 ���� ü�� : %d\n                                 ���ݷ� : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);
//    bar_en;
//    what_do();
//    return;
//}
//
////void load_pok(int count) {
////    printf("\n�ε��Դϴ�~~~\n");
////    printf("Warrior %d: �̸�=%s, �Ӽ�=%s, ���ݷ�=%d, ü��=%d, ���� ü��=%d\n",
////           count+1, my_pok_battle[count].name, my_pok_battle[count].type, my_pok_battle[count].attck, my_pok_battle[count].hp, my_pok_battle[count].rhp);
////    return;
////}
//
//
//void print_f_pok(int count) {
//    bar_en;
//    printf("\n                               �߻��� ���ϸ�\n");
//    printf("\n                                 �Ӽ� : %s \n                                 ü�� : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
//    printf("                                 ���� ü�� : %d\n                                 ���ݷ� : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);
//
//
//    printf("Warrior %d: �̸�=%s, \n�Ӽ�=%s,  ü��=%d, \n���ݷ�=%d, ���� ü��=%d\n",
//        count + 1, my_pok_battle[count].name, my_pok_battle[count].type, my_pok_battle[count].hp, my_pok_battle[count].attck, my_pok_battle[count].rhp);
//    bar_en;
//    return;
//
//}
//void attack(int count, int c) {
//    int m_attck = my_pok_battle[count].attck * 0.2;
//    int e_attck = enemy_pok_data->attck * 0.2;
//
//    enemy_pok_data->rhp = enemy_pok_data->rhp - (rand() % (m_attck + c));
//    my_pok_battle[count].rhp = my_pok_battle[count].rhp - (rand() % (e_attck + c));
//    return;
//}
//
//
//void reverse_attack(int count, int c) {
//    int m_attck = my_pok_battle[count].attck * 0.2;
//    int e_attck = enemy_pok_data->attck * 0.2;
//
//    enemy_pok_data->rhp = enemy_pok_data->rhp - (rand() % (m_attck + c));
//    my_pok_battle[count].rhp = my_pok_battle[count].rhp - (rand() % (e_attck + c));
//    return;
//}
//
//
//void critical(int count) {
//    printf("\n���� �Լ� �Դϴ�~~\n");
//    int sun = rand() % 2;
//    int en_type_num, my_type_num, c = 0;
//    int critical = 20;
//    int critical2 = 30;
//
//    char* type[] = { "ǮŸ��", "�Ҳ�Ÿ��",  "��Ÿ��" };
//
//
//    for (int i = 0; i < 3; i++) {
//        if (strcmp(type[i], enemy_pok_data->type) == 0) {
//            en_type_num = i;
//            break;
//        }
//    }
//
//    for (int k = 0; k < 3; k++) {
//        if (strcmp(type[k], my_pok_battle[count].type) == 0) {
//            my_type_num = k;
//            break;
//        }
//    }
//
//    if (en_type_num > my_type_num) {
//        c = critical;
//        printf("\n�� �켼!\n");
//        if (sun == 0) {
//            printf("\n�츮�� ���� ��������!\n");
//            attack(count, c);
//            print_f_pok(count);
//        }
//        else {
//            printf("\n��� ���� ����!\n");
//            reverse_attack(count, c);
//            print_f_pok(count);
//        }
//
//    }
//    else if (en_type_num < my_type_num) {
//        c = critical2;
//        printf("\nũ��Ƽ��!!!\n");
//        if (sun == 0) {
//            printf("\n�츮�� ���� ��������!\n");
//            attack(count, c);
//            printf("\n ȿ���� �����ߴ�\n");
//            print_f_pok(count);
//        }
//        else {
//            printf("\n��� ���� ����!\n");
//            reverse_attack(count, c);
//            print_f_pok(count);
//        }
//    }
//    else {
//        printf("\n���� Ÿ��\n");
//        c = 10;
//        if (sun == 0) {
//            printf("\n�츮�� ���� ��������!\n");
//            attack(count, c);
//            print_f_pok(count);
//        }
//        else {
//            printf("\n��� ���� ����!\n");
//            reverse_attack(count, c);
//            print_f_pok(count);
//        }
//    }
//
//    return;
//}
//
//
//void battle(int count) {
//    bar_en;
//    printf("���Ͷ� %s!\n", my_pok_battle[count].name);
//    //load_pok(count);
//    critical(count);
//    what_do();
//}
//
//void death_pok(int count) {
//    int T_ch;
//    printf("\n����Ͻðڽ��ϱ�?\n 1. �� 2. �ƴϿ�\n");
//    scanf("%d", &T_ch);
//
//    if (T_ch == 1) {
//        ++count;
//        battle(count);
//    }
//    else if (T_ch == 2) {
//        printf("\n��밡 �ʹ� ���ϴ�..! ��������!\n");
//        run_away(count);
//    }
//
//}
//
//int run_away(int count) {
//    int run_run;
//    if (enemy_pok_data->rhp > my_pok_battle[count].rhp) {
//        run_run = rand() % 10 + 1;
//        if (run_run > 5) {
//            printf("\n���������� �����ƴ�!\n");
//            return 0;
//        }
//        else {
//            printf("\n����ġ�� ����..!\n");
//            ++count;
//            battle(count);
//
//        }
//    }
//}
//
//
//
//void what_do() {
//    int choice;
//    int count = 0;
//    int result = 0;
//
//
//    do {
//        printf("\n�� �ұ� ?\n1. ���� 2. ���濭�� 3. ����ġ��\n");
//        scanf("%d", &choice);
//        switch (choice) {
//        case 1:
//            if (enemy_pok_data->rhp > 0 && my_pok_battle[count].rhp > 0) {
//                printf("\n�ο���!\n");
//                battle(count);
//                break;
//            }
//            else if (enemy_pok_data->rhp <= 0 || my_pok_battle[count].rhp <= 0) {
//                if (enemy_pok_data->rhp < 0) {
//                    printf("\n������ �����߷ȴ�!!\n");
//                    break;
//                    return result = 1;
//
//                }
//                else if (my_pok_battle[count].rhp < 0) {
//                    printf("\n������ ����������..!\n");
//                    death_pok(count);
//                    break;
//                    return;
//                }
//            }
//            //case 2:
//            //    bag();
//            //    break;
//        case 3:
//            printf("\n�����ľ� �� !!!!!\n");
//            run_away(count);
//
//            if (run_away(count) == 0) {
//                result = 1;
//            }
//            break;
//        }
//    } while (result != 1);//���� ����ġ�� ��� �� ���ϵǴ� ���� �־�� �� ��.);
//    printf("what_do ��������");
//    play_Game(a);
//}
//
//
//
//
//int main() {
//
//    read_dict_in_game(); // �̰� �������. �ϼ��Ǹ� ó���� ������ ���� �о my_pok�� �����Ŵϱ� ���� �ڵ� ��������� ���� ��.
//    walking();
//    warning();
//    printf("\n�׽�Ʈ ���� \n�׽�Ʈ ����\n"); //�׽�Ʈ �Ϸ� -> ���� ���(��, Ÿ�� ġ��Ÿ Ȯ��), ����ġ�� ���� �Ϸ� -> �����̶� �����ؾ� ��.
//    return 0;
//}