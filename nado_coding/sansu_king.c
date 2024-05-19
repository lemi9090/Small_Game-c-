// 5단계의 각 단계마다 랜덤한 수식퀴즈가 탄생한다.
// 그 퀴즈를 맞춰야 다음 단계로 갈 수 있다. 
// 맞히면 통과, 틀리면 실패
// 간 단계의 도전 2번 시도 가능

#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>


bool quest(int u, int i, int t) {
	int r=0;
		for (int b = 0; b < 2; b++) { //한문제에 2번기회

			printf("%d + %d = ??\n", u, i);
			scanf("%d", &r);

			while (1) {
				if (t == r) {
					printf("성공! 다음단계로 넘어가세요\n");
					return true;
					break;
				}
				else {
					printf("다시 생각해 보세요\n");
					break;
				}

			}
		}
		printf("실패했습니다 처음부터 다시하세요\n");
		return false;
	}

bool quest2(int u, int i, int t) {
	int r = 0;
	for (int b = 0; b < 2; b++) { //한문제에 2번기회

		printf("%d - %d = ??\n", u, i);
		scanf("%d", &r);
		while (1) {
			if (t == r) {
				printf("성공! 다음단계로 넘어가세요\n");
				return true;
				break;
			}
			else {
				printf("다시 생각해 보세요\n");
				break;
			}
			
		}		
	}
	printf("실패했습니다 처음부터 다시하세요\n");
	return false;
	
}
bool quest3(int u, int i, int t) {
	int r = 0;
	for (int b = 0; b < 2; b++) { //한문제에 2번기회

		printf("%d - %d = ??\n", u, i);
		scanf("%d", &r);
		while (1) {
			if (t == r) {
				printf("성공! 다음단계로 넘어가세요\n");
				return true;
				break;
			}
			else {
				printf("다시 생각해 보세요\n");
				break;
			}

		}
	}
	printf("실패했습니다 처음부터 다시하세요\n");
	return false;

}
bool quest4(int u, int i, int t) {
	int r = 0;
	for (int b = 0; b < 2; b++) { //한문제에 2번기회

		printf("%d * %d = ??\n", u, i);
		scanf("%d", &r);
		while (1) {
			if (t == r) {
				printf("성공! 다음단계로 넘어가세요\n");
				return true;
				break;
			}
			else {
				printf("다시 생각해 보세요\n");
				break;
			}

		}
	}printf("실패했습니다 처음부터 다시하세요\n");
	return false;

}
bool quest5(int u, int i, int t) {
	int r = 0;
	for (int b = 0; b < 2; b++) { //한문제에 2번기회

		printf("%d * %d = ??\n", u, i);
		scanf("%d", &r);
		while (1) {
			if (t == r) {
				printf("성공! 다음단계로 넘어가세요\n");
				return true;
				break;
			}
			else {
				printf("다시 생각해 보세요\n");
				break;
			}

		}

	}	printf("실패했습니다 처음부터 다시하세요\n");
	return false;

}


int math_main(void) {
	srand(time(NULL));
	int u=0, i=0, t=0;

	printf("\n어서오세요! 당신의 산수 실력을 확인해 보겠습니다!\n");

	while (true) {
		u = rand() % 10 + 1;
		i = rand() % 10 + 1;
		t = u + i;
		if (quest(u, i, t) == true) {//문제 1번
			break;
		}
	}


	while(true){
		u = rand() % 30 + 20;
		i = rand() % 10 + 1;
		t = u - i;

		if (quest2(u, i, t) == true) {
			break;
		}
	}


	while (true) {
		u = rand() % 300 + 200;
		i = rand() % 100 + 1;
		t = u - i;

		if (quest3(u, i, t) == true) {
			break;
		}
	}

	while (true) {
			u = rand() % 30 + 1;
			i = rand() % 30 + 1;
			t = u * i;

			if (quest4(u, i, t) == true) {
				break;
			}
	}

	while (true) {
		u = rand() % 100 + 1;
		i = rand() % 100 + 1;
		t = u * i;

		if (quest5(u, i, t) == true) {
			break;
		}
	}
	printf("\n와우! 모두 풀어냈군요 당신은 최고의 산수왕!\n\n");
	
	int cc;

	printf("다른 문제 풀어보실래요? : \n1. 네\n2. 아니요\n");
	scanf("%d", &cc);

	if (cc == 1) {
		main();
	}
	else if (cc == 2) {
		printf("그럼 잘가요!");
		exit(0);
	}

}
