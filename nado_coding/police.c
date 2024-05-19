#include <stdio.h>

int police_main() {
	char name[256];
	int age = 0;
	int high = 0;
	float weigh;
	char abo [256];

	printf("이름 : ");
	scanf("%s", name, sizeof(name));
	printf("\n나이 : ");
	scanf("%d", &age);
	printf("\n키 : ");
	scanf("%d", &high);
	printf("\n몸무게 : ");
	scanf("%f", &weigh);
	printf("\n범죄명 : ");
	scanf("%s", abo, sizeof(abo));

	printf("\n이름 : %s\n나이 : %d\n키 : %d\n몸무게 : %.2f\n범죄명 : %s\n", name, age, high, weigh, abo);
}
