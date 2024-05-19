#include <stdio.h>
#include<time.h>
#include<stdlib.h>

//가위, 바위, 보
// 처음에 내가 뭐낼지 입력받고
// 만약에 내가 낸게 랜덤으로 나온거랑 해서 이기면 이겼다!, 졌으면 으아아아아 출력

int batt(int a, int b) {
	switch (a) {

	case 1: {


		if (b == 1) {
			printf("***비겼다! 다시!***\n");
			return main();
		}
		else if (b == 2) {
			printf("***이겼다!야호!***\n");
			break;

		}
		else {
			printf("***졌다! 으아아앙***\n");
			break;
		}

	}
	case 2: {
		if (b == 1) {
			printf("***이겼다!야호!***\n");
			break;
		}
		else if (b == 2) {
			printf("***비겼다! 다시!***\n");
			return main();

		}
		else {
			printf("***졌다! 으아아앙***\n");
			break;
		}

	}
	case 3: {
		if (b == 1) {
			printf("***이겼다!야호!***\n");
			break;
		}
		else if (b == 2) {
			printf("***졌다! 으아아앙***\n");
			break;
		}
		else {
			printf("***비겼다! 다시!***\n");
			return main();

		}
	}
	}
	return main();
}

int rock_main(void) {
		int a, b, c, d;
		srand(time(NULL));
		//printf("\n\n__________가위! 바위! 보!__________");
		printf("\n뭐 낼래? : \n 1 주먹 2 가위 3 보자기\n");
		scanf("%d", &a);

		b = rand() % 3 + 1;
		//printf("%d\n", b);

		batt(a, b);
}
