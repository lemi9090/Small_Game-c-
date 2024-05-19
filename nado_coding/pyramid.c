#include <stdio.h>

int flo(int f) {
	int i = 0;
	int a = 0;
	for (i = 0; i <= f; i++) {
		for (a = f - 1; a >= i; a--) {
			printf(" ");
		}
		for (int c = 0; c < 2 * i + 1; c++) {  // 식이 성립 안되면 위 중첩문으로 갔다가 // 다시 돌아올땐 다시 c는 0이 된다.
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n");
	return main();
}

int pyramid_main(void) {
	
	int num = 100;
	int f = 0;
	printf("몇 층으로 쌓을거야? : ");
	scanf("%d", &f);
	flo(f);
	
}
