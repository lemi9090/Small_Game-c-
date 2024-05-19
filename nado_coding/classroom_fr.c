#include <stdio.h>

int class_main(void) {
	int st;

	//1번부터 10까지 발표준비를 하세요, 1번부터 3번까지는 지금 발표하세요
	printf("1번부터 10번까지 발표준비를 하세요\n");
	for (int i = 1; i < 20; i++) {
		if (i <= 15) {
			
			if (i == 7) {
				printf("%d번은 결석입니다.\n", i);
				continue;
			}
			if (i == 8) {
				printf("그러니 %d번이 대신 발표하세요\n", i);
				continue;
			}
			printf("[%d]번 지금 발표하세요\n", i);
		}
	}
}
