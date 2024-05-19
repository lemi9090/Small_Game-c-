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
//    printf("모험 중 .. 모험 중 ... 모험 중 ...\n");
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
//    const char* attributes[3] = { "불꽃타입", "풀타입", "물타입" };
//    strcpy(enemy_pok_data->name, "야생의 포켓몬");
//    strcpy(enemy_pok_data->type, attributes[attr_index]);
//
//    bar_en;
//    printf("                               야생의 포켓몬이 나타났다!\n");
//    printf("\n                                 속성 : %s \n                                 체력 : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
//    printf("                                 현재 체력 : %d\n                                 공격력 : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);
//    bar_en;
//    what_do();
//    return;
//}
//
////void load_pok(int count) {
////    printf("\n로드입니다~~~\n");
////    printf("Warrior %d: 이름=%s, 속성=%s, 공격력=%d, 체력=%d, 현재 체력=%d\n",
////           count+1, my_pok_battle[count].name, my_pok_battle[count].type, my_pok_battle[count].attck, my_pok_battle[count].hp, my_pok_battle[count].rhp);
////    return;
////}
//
//
//void print_f_pok(int count) {
//    bar_en;
//    printf("\n                               야생의 포켓몬\n");
//    printf("\n                                 속성 : %s \n                                 체력 : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
//    printf("                                 현재 체력 : %d\n                                 공격력 : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);
//
//
//    printf("Warrior %d: 이름=%s, \n속성=%s,  체력=%d, \n공격력=%d, 현재 체력=%d\n",
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
//    printf("\n공격 함수 입니다~~\n");
//    int sun = rand() % 2;
//    int en_type_num, my_type_num, c = 0;
//    int critical = 20;
//    int critical2 = 30;
//
//    char* type[] = { "풀타입", "불꽃타입",  "물타입" };
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
//        printf("\n적 우세!\n");
//        if (sun == 0) {
//            printf("\n우리가 먼저 공격하자!\n");
//            attack(count, c);
//            print_f_pok(count);
//        }
//        else {
//            printf("\n상대 먼저 공격!\n");
//            reverse_attack(count, c);
//            print_f_pok(count);
//        }
//
//    }
//    else if (en_type_num < my_type_num) {
//        c = critical2;
//        printf("\n크리티컬!!!\n");
//        if (sun == 0) {
//            printf("\n우리가 먼저 공격하자!\n");
//            attack(count, c);
//            printf("\n 효과는 굉장했다\n");
//            print_f_pok(count);
//        }
//        else {
//            printf("\n상대 먼저 공격!\n");
//            reverse_attack(count, c);
//            print_f_pok(count);
//        }
//    }
//    else {
//        printf("\n같은 타입\n");
//        c = 10;
//        if (sun == 0) {
//            printf("\n우리가 먼저 공격하자!\n");
//            attack(count, c);
//            print_f_pok(count);
//        }
//        else {
//            printf("\n상대 먼저 공격!\n");
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
//    printf("나와라 %s!\n", my_pok_battle[count].name);
//    //load_pok(count);
//    critical(count);
//    what_do();
//}
//
//void death_pok(int count) {
//    int T_ch;
//    printf("\n계속하시겠습니까?\n 1. 예 2. 아니오\n");
//    scanf("%d", &T_ch);
//
//    if (T_ch == 1) {
//        ++count;
//        battle(count);
//    }
//    else if (T_ch == 2) {
//        printf("\n상대가 너무 강하다..! 도망가자!\n");
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
//            printf("\n성공적으로 도망쳤다!\n");
//            return 0;
//        }
//        else {
//            printf("\n도망치기 실패..!\n");
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
//        printf("\n뭘 할까 ?\n1. 공격 2. 가방열기 3. 도망치기\n");
//        scanf("%d", &choice);
//        switch (choice) {
//        case 1:
//            if (enemy_pok_data->rhp > 0 && my_pok_battle[count].rhp > 0) {
//                printf("\n싸우자!\n");
//                battle(count);
//                break;
//            }
//            else if (enemy_pok_data->rhp <= 0 || my_pok_battle[count].rhp <= 0) {
//                if (enemy_pok_data->rhp < 0) {
//                    printf("\n적장을 쓰러뜨렸다!!\n");
//                    break;
//                    return result = 1;
//
//                }
//                else if (my_pok_battle[count].rhp < 0) {
//                    printf("\n눈앞이 깜깜해졌다..!\n");
//                    death_pok(count);
//                    break;
//                    return;
//                }
//            }
//            //case 2:
//            //    bag();
//            //    break;
//        case 3:
//            printf("\n도망쳐야 돼 !!!!!\n");
//            run_away(count);
//
//            if (run_away(count) == 0) {
//                result = 1;
//            }
//            break;
//        }
//    } while (result != 1);//여긴 도망치기 기능 후 리턴되는 값을 넣어야 할 듯.);
//    printf("what_do 종료지점");
//    play_Game(a);
//}
//
//
//
//
//int main() {
//
//    read_dict_in_game(); // 이건 실험용임. 완성되면 처음에 무조건 정보 읽어서 my_pok에 넣을거니까 공격 코드 만들어지면 지울 것.
//    walking();
//    warning();
//    printf("\n테스트 종료 \n테스트 종료\n"); //테스트 완료 -> 전투 기능(적, 타입 치명타 확률), 도망치기 구현 완료 -> 가방이랑 연결해야 됨.
//    return 0;
//}