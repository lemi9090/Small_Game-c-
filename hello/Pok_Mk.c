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
	printf("R�� ���޵� a�� : %d\n", a);

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
		printf("\n���ͺ� : %d �� ����, ���� : %d\n", market2.ball, ball_price);
		printf("������ġ��: %d �� ����, ���� : %d\n", market2.para, potion_price);
		BAR;
		printf("\n ���� �ϰ� ���� ����... : \n 1. ���ͺ�! 2. ������ġ��!  3. ������\n");
		scanf("%d", &ch);

		if (ch == 1) {
			BAR;
			printf("\n\n�츮���� ���ͺ��� �ְ���!\n �󸶳� �췡?\n\n");
			scanf("%d", &tt);
			if (ball_price * tt <= wimb.money && tt <= market2.ball) {
				printf("\n%d��? �˰ھ� ����!\n", tt);
				market2.ball = market2.ball - tt;
				wimb.ball = wimb.ball + tt;
				wimb.money = wimb.money - (tt * ball_price);
				printf("�ܾ��� %d ���Ҵ�..!\n", wimb.money);
			}
			else if (tt > market2.ball) {
				printf("\n�׷��� ����? �׷��� ���̴� ����!!\n");
				continue;
			}
			else if (ball_price * tt > wimb.money) {
				printf("\n%d��? ���� �����鼭 ����!!\n", tt);
				continue;
			}
		}
		else if (ch == 2) {
			BAR;
			printf("\n\n������ġ��..! ���� ��������!\n �󸶳� �췡?\n\n");
			scanf("%d", &tt);
			if (potion_price * tt <= wimb.money && tt < market2.para) {
				printf("\n%d��? �˰ھ� ����!\n", tt);
				market2.para = market2.para - tt;
				wimb.para = wimb.para + tt;
				wimb.money = wimb.money - (tt * potion_price);
				printf("�ܾ��� %d ���Ҵ�..!\n", wimb.money);
			}
			else if (tt > market2.para) {
				printf("\n�׷��� ����? �׷��� ���̴� ����!!\n");
				continue;
			}
			else if (potion_price * tt > wimb.money) {
				printf("\n%d��? �̾������� ���� ������ �� ��!!\n", tt);
				continue;
			}
			
		}
	} while (ch != 3);
	display_wimb();
}