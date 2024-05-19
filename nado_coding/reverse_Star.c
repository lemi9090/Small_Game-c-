#include <stdio.h>

int reverse_star_main(void) {
	int i = 0;
	int a = 0;

	for (i = 0; i <= 5;i++) { //층을 정해준다.
		for (a = 5; a >= i; a--) {//조건을 정할 때 역으로 해야하니 낮은층이 제일 많아야 한다. 
			printf("*");
		}
		printf("\n");//층 나누는 부분
	}
}
