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
    printf("모험 중 .. 모험 중 ... 모험 중 ...\n");
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

    const char* attributes[3] = { "불꽃타입", "풀타입", "물타입" };
    strcpy(enemy_pok_data->name, "야생의 포켓몬");
    strcpy(enemy_pok_data->type, attributes[attr_index]);

    bar_en;
    printf("                               야생의 포켓몬이 나타났다!\n");
    printf("                                 능력치는 정확하지 않다..!\n");
    printf("\n                                 속성 : %s \n                                 체력 : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
    printf("                                 현재 체력 : %d\n                                 공격력 : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);
    bar_en;
    return;
}


void load_pok(int *worrior_num_p) {
    printf("\n로드입니다~~~\n");
    printf("Warrior %d: 이름=%s, 속성=%s, 공격력=%d, 체력=%d, 현재 체력=%d\n",
        *worrior_num_p +1, my_pok_ptr[*worrior_num_p].name, my_pok_ptr[*worrior_num_p].type, my_pok_ptr[*worrior_num_p].attck, my_pok_ptr[*worrior_num_p].hp, my_pok_ptr[*worrior_num_p].rhp);
    printf("\n로드 끝!\n");
    return;
}


void print_f_pok(int* worrior_num_p) {
    printf("\n프린트 에프 카운트 : %d \n", *worrior_num_p);
    bar_en;
    printf("\n                               야생의 포켓몬\n");
    printf("\n                                 속성 : %s \n                                 체력 : %d\n", enemy_pok_data->type, enemy_pok_data->hp);
    printf("                                 현재 체력 : %d\n                                 공격력 : %d\n", enemy_pok_data->rhp, enemy_pok_data->attck);

 
    printf("Warrior %d: 이름=%s, \n속성=%s,  체력=%d, \n공격력=%d, 현재 체력=%d\n",
        *worrior_num_p + 1, my_pok_ptr[*worrior_num_p].name, my_pok_ptr[*worrior_num_p].type, my_pok_ptr[*worrior_num_p].hp, my_pok_ptr[*worrior_num_p].attck, my_pok_ptr[*worrior_num_p].rhp);
    bar_en;
    return;
}

void attack(int* worrior_num_p, int c) {
    printf("\n 어택 카운트 : %d \n", *worrior_num_p);
    int m_attck = my_pok_ptr[*worrior_num_p].attck * 0.2;
    int e_attck = enemy_pok_data->attck * 0.2;

    enemy_pok_data->rhp -= (rand() % (m_attck + c));
    my_pok_ptr[*worrior_num_p].rhp -= (rand() % (e_attck + c));
    return;
}

void reverse_attack(int* worrior_num_p, int c) {
    printf("\n리버스 어택 카운트 : %d \n", *worrior_num_p);
    int m_attck = my_pok_ptr[*worrior_num_p].attck * 0.2;
    int e_attck = enemy_pok_data->attck * 0.2;

    enemy_pok_data->rhp -= (rand() % (m_attck + c));
    my_pok_ptr[*worrior_num_p].rhp -= (rand() % (e_attck + c));
    return;
}


void critical(int *worrior_num_p) {
    printf("\n공격 함수 입니다~~\n");
    printf("\n크리티컬 카운트 : %d \n", *worrior_num_p);
    int sun = rand() % 2;
    int en_type_num, my_type_num, c = 0;
    int critical = 20;
    int critical2 = 30;

    char* type[] = { "풀타입", "불꽃타입",  "물타입" };


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
        printf("\n적 우세!\n");
        if (sun == 0) {
            printf("\n우리가 먼저 공격하자!\n");
            printf("\n우리가 먼저 공격하자 카운트 : %d \n", *worrior_num_p);
            attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
        else {
            printf("\n상대 먼저 공격!\n");
            printf("\n상대 먼저 공격 카운트 : %d \n", *worrior_num_p);
            reverse_attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }

    }
    else if (en_type_num < my_type_num) {
        c = critical2;
        printf("\n크리티컬!!!\n");
        if (sun == 0) {
            printf("\n우리가 먼저 공격하자!\n");
            printf("\n우리가 먼저 공격하자 카운트 : %d \n", *worrior_num_p);
            attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
            printf("\n 효과는 굉장했다\n");
            
        }
        else {
            printf("\n상대 먼저 공격!\n");
            printf("\n상대 먼저 공격 카운트 : %d \n", *worrior_num_p);
            reverse_attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
    }
    else {
        printf("\n같은 타입\n");
        c = 10;
        if (sun == 0) {
            printf("\n우리가 먼저 공격하자!\n");
            attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
        else {
            printf("\n상대 먼저 공격!\n");
            reverse_attack(worrior_num_p, c);
            print_f_pok(worrior_num_p);
        }
    }

    return;
}



void battle(int* worrior_num_p) {
    bar_en;
    printf("나와라 %s!\n", my_pok_ptr[*worrior_num_p].name);
    
    printf("\n 배틀 함수 카운트 : %d \n", *worrior_num_p);
 
    critical(worrior_num_p);

    printf("\n배틀 전투 후 다시 리턴으로 왓 두로 넘어갈 때 카운트 : %d \n", *worrior_num_p);
    return;
}

int death_pok(int * worrior_num_p, int *result_p) {
    int T_ch = 0;
    printf("\n계속하시겠습니까?\n 1. 예 2. 아니오\n");
    scanf("%d", &T_ch);

    printf("\n데스 데스 카운트 : %d \n", *worrior_num_p);

    if (T_ch == 1) {
        ++(*worrior_num_p);
        printf("\n죽은 다음 잘 증가했는지 확인하는 데스 카운트 : %d \n", *worrior_num_p);
        //battle(count);
    }
    else if (T_ch == 2) {
        printf("\n상대가 너무 강하다..! 도망가자!\n");
        int escape = run_away(*worrior_num_p);

        if (escape == 0) {
            ++(*worrior_num_p);
            printf("\n죽은 다음 도망치기 실패해 어쩔 수 없이 싸우기 위해 증가되는 카운트 : %d \n", *worrior_num_p);
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
            printf("\n성공적으로 도망쳤다!\n");
            return 1;  // 도망 성공
        }
        else {
            printf("\n도망 실패..!\n");
            //++(*worrior_num_p);  // Correctly increment the actual count
            //printf("\n도망치기 실패해서 어쩔 수 없이 싸우기 위해 증가되는 카운트 : %d \n", *worrior_num_p);
            //battle(count);  // Pass the pointer, not the value
            return 0;  // 도망 실패
        }
}

int item_use_mosterball() {
    printf("몬스터볼 사용!\n");
    int pok_ball = rand() % 4 + 1;
    wimb.ball -= 1;
  
    if (pok_ball >= 3) {
        printf("\n%s를 잡았다! 넌 내거야!\n", enemy_pok_data->name);
        return 1;
    }
    else {
        printf("\n앗..! 땅에 던져 버렸다..!\n");
        return 0;
    }
}


void what_do(int* worrior_num_p) {
    int choice;
    int item_use;
    printf("왓 두 카운트  : % d\n", *worrior_num_p);
    printf("왓 두 카운트 현재체력 : %d\n", my_pok_ptr[*worrior_num_p].rhp);
    int result = 0;
    int *result_p = &result;

    do {
        printf("\n뭘 할까 ?\n1. 공격 2. 가방열기 3. 도망치기\n");
        scanf("%d", &choice);

        load_pok(worrior_num_p); // 실험용

        switch (choice) {
        case 1:
            if (enemy_pok_data->rhp > 0 && my_pok_ptr[*worrior_num_p].rhp > 0) {
                printf("\n싸우자!\n");
                printf("\n왓 두에서 받는 카운트 : %d \n", *worrior_num_p);
                battle(worrior_num_p);// 함수를 호출할 땐 *를 붙여서 호출하면 **worrior_num_p를 호출하는 것과 같다. 
            }
           else if (enemy_pok_data->rhp <= 0 && my_pok_ptr[*worrior_num_p].rhp > 0) {
                printf("\n적장을 쓰러뜨렸다!!\n");
                save_all_pokemon(my_pok_ptr, count_ptr);
                result = 1;

            }
            else if (my_pok_ptr[*worrior_num_p].rhp <= 0 && enemy_pok_data->rhp > 0) {
                printf("카운트 %d\n", *worrior_num_p);
                printf("my_pok%d\n", my_pok_ptr[*worrior_num_p].rhp);
                printf("enemy_ data %d\n", enemy_pok_data->rhp);

                printf("\n눈앞이 깜깜해졌다..!\n");

                printf("\n죽자마자 첫 왓두에서 카운트 상태 : %d \n", *worrior_num_p);
                death_pok(worrior_num_p, result_p);
                if (*result_p == 1) {
                    save_all_pokemon(my_pok_ptr, count_ptr);
                    result = 1;
                }
                printf("\n데스 포크에서 리턴 카운트 후 왓두에서 카운트 상태 이게 배틀로 넘어가야 함(증가되어 있어야 함): %d \n", *worrior_num_p);
                if (my_pok_ptr[*worrior_num_p].rhp < 0 || my_pok_ptr[*worrior_num_p].rhp>300) {
                    printf("\n모든 포켓몬이 패패했습니다....\n처음으로 돌아갑니다.\n");
                    save_all_pokemon(my_pok_ptr, count_ptr);
                    result = 1;
                }
 
             /*   if ((strcmp(my_pok_ptr[*worrior_num_p].name, "") == 0)) {
                    
                }*/
            }
            break;

        case 2:
            printf("가방을 열었다!\n");
            printf("뭐할래?\n");
            read_wimb();
            printf("1. 몬스터볼로 잡자! 2. 상처약을 쓰자!\n");
            scanf("%d", &item_use);


            if (item_use == 1) {
                if (wimb.ball > 0) {
                    if (item_use_mosterball() == 1) {
                        plus_pok(a, my_pok_ptr, count_ptr);
                        result = 1;
                    }
                }
                else {
                    printf("\n몬스터볼이 부족합니다\n");
                }

            }
            else if (item_use == 2) {
                if (wimb.para > 0) {
                    printf("\n최고의 만병통치약 사용!!\n");
                    //heal_pok(worrior_num_p);
                    wimb.para -= 1;;
                    printf("현재 포켓몬 상태: rhp=%d, hp=%d\n", my_pok_ptr[*worrior_num_p].rhp, my_pok_ptr[*worrior_num_p].hp);
                    my_pok_ptr[*worrior_num_p].rhp = my_pok_ptr[*worrior_num_p].hp;
                    printf("회복 결과: rhp=%d, hp=%d\n", my_pok_ptr[*worrior_num_p].rhp, my_pok_ptr[*worrior_num_p].hp);
                }
                else {
                    printf("\n약..약이 없는뎁슈?\n");
                }
            }
            display_wimb();
            break;


        case 3:
            printf("\n도망쳐야 돼 !!!!!\n");
            if (run_away(worrior_num_p) == 1) {
                result = 1;
            }
            break;
        }

    } while (result != 1);
    
    printf("what_do 종료지점\n\n");
    play_Game(a);
}







int gogo_advanture() {
    //int count = 0;
    //int* worrior_num_p = &count;
    //read_dict2(worrior_num_p); // 이건 실험용임. 완성되면 처음에 무조건 정보 읽어서 my_pok에 넣을거니까 공격 코드 만들어지면 지울 것.
    walking();
    warning();
    printf("고고 어드밴쳐 : %d\n", *worrior_num_p);
    what_do(worrior_num_p);
    printf("\n테스트 종료 \n테스트 종료\n"); //테스트 완료 -> 전투 기능(적, 타입 치명타 확률), 도망치기 구현 완료 -> 가방이랑 연결해야 됨.
    *worrior_num_p = 0;
    
    return 0;
}





// 워리어 넘버 피 초기화 필요, 음수이거나 200 이상이면 남은 포켓몬이 없다고 하던지 조치 필요
// printf("\n데스 포크에서 리턴 카운트 후 왓두에서 카운트 상태 이게 배틀로 넘어가야 함(증가되어 있어야 함): %d \n", *worrior_num_p);
// 포켓몬 센터 구현 필요


