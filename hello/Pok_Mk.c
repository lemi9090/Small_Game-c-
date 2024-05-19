//Pok_Mk.c
#include <stdio.h>
#include "INFO.h"
#define BAR printf("=================================================");
extern void display_wimb();
extern void read_wimb();

typedef struct {
	int ball;
	int para;
}pok_market;

pok_market market2 = { 10, 10 };

//void reset_wimb() {
//	wimb.money = 1000;
//	wimb.ball = 0;
//	wimb.para = 0;
//}



void R_shopping(int a) {
	printf("R에 전달된 a값 : %d\n", a);

	/*if (a == 1) {
		reset_wimb();
	}
	else {
		read_wimb();
	}*/

	int ball_price = 50;
	int potion_price = 200;
	int ch, tt;

	BAR
		printf("\nBonjour! vous voulez ce?\n");
	BAR;
	do {
		printf("\n몬스터볼 : %d 개 남음, 가격 : %d\n", market2.ball, ball_price);
		printf("만병통치약: %d 개 남음, 가격 : %d\n", market2.para, potion_price);
		BAR;
		printf("\n 내가 하고 싶은 것은... : \n 1. 몬스터볼! 2. 만병통치약!  3. 나가다\n");
		scanf("%d", &ch);

		if (ch == 1) {
			BAR;
			printf("\n\n우리가게 몬스터볼은 최고지!\n 얼마나 살래?\n\n");
			scanf("%d", &tt);
			if (ball_price * tt <= wimb.money && tt <= market2.ball) {
				printf("\n%d개? 알겠어 여기!\n", tt);
				market2.ball = market2.ball - tt;
				wimb.ball = wimb.ball + tt;
				wimb.money = wimb.money - (tt * ball_price);
				printf("잔액이 %d 남았다..!\n", wimb.money);
			}
			else if (tt > market2.ball) {
				printf("\n그렇게 많이? 그렇게 많이는 없어!!\n");
				continue;
			}
			else if (ball_price * tt > wimb.money) {
				printf("\n%d개? 돈도 없으면서 무슨!!\n", tt);
				continue;
			}
		}
		else if (ch == 2) {
			BAR;
			printf("\n\n만병통치약..! 많이 아프구나!\n 얼마나 살래?\n\n");
			scanf("%d", &tt);
			if (potion_price * tt <= wimb.money && tt < market2.para) {
				printf("\n%d개? 알겠어 여기!\n", tt);
				market2.para = market2.para - tt;
				wimb.para = wimb.para + tt;
				wimb.money = wimb.money - (tt * potion_price);
				printf("잔액이 %d 남았다..!\n", wimb.money);
			}
			else if (tt > market2.para) {
				printf("\n그렇게 많이? 그렇게 많이는 없어!!\n");
				continue;
			}
			else if (potion_price * tt > wimb.money) {
				printf("\n%d개? 미안하지만 돈이 없으면 못 줘!!\n", tt);
				continue;
			}
			
		}
	} while (ch != 3);
	display_wimb();
}