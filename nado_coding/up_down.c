#include <stdio.h>
#include<time.h>
#include<stdlib.h>

//up and down
// 숫자가 랜덤으로 정해지고
// 사용자가 입력한 숫자와 비교한다.
// 낮으면 up, 높으면 다운 출력

int up_down_main() {
	int a;
	int b;
	int i = 5;

	printf("자! 컴퓨터가 랜덤의 숫자를 골라서 생각하고 있습니다. \n 맞춰보시지요! 껄껄껄\n");
	srand(time(NULL));
	b = rand() % 100 + 1;
	
	
//do while을 사용해 만든 게임 
	do {
		scanf("%d", &a);
		if (b == a) {
			printf("아니 어떻게 알았지?\n 정답입니다!");
			break;
		}
		else if (b > a) {
			printf("UP!! 잘 맞춰보세요!\n남은 기회는 %d번!\n", i--);
			continue;
		}
		else if (a > b) {
			printf("DOWN!! 잘 맞춰보세요!\n남은 기회는 %d번!\n", i--);
			continue;
		}
	} while (i > 0);
	printf("\n정답은 바로바로~~~!! %d 입니다 ㅠㅠ \n 다음기회를 노려보세요! ", b);


-------------------------------------------------------------------------------------
//for문으로 만든 게임
	
	for (int i = 5; i < 6; i--) {
		if (i != 0) {
			scanf("%d", &a);
			if (b == a) {
				printf("아니 어떻게 알았지?\n 정답입니다!");
				break;
			}
			else if (b > a) {
				printf("up!! 잘 맞춰보세요!\n남은 기회는 %d번!\n", i-1);
				continue;
			}
			else if (a > b) {
				printf("down!! 잘 맞춰보세요!\n남은 기회는 %d번!\n", i-1);
				continue;
			}
		}
		else if (i == 0) {
			printf("\n정답은 바로바로~~~!! %d 입니다 ㅠㅠ \n 다음기회를 노려보세요! ", b);
			break;
		}
		
	}
