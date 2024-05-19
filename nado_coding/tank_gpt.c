#include <stdio.h>
#include <math.h>

#define PI 3.14159

int gpt_tank_main() {
    double angle, power;
    double distance;
    int target = 100; // 상대 탱크까지의 거리 (임의로 설정)

    printf("간단한 탱크 게임에 오신 것을 환영합니다!\n");
    printf("상대방 탱크를 명중시켜 승리하세요.\n");
    printf("상대방 탱크까지의 거리는 %d 미터입니다.\n", target);

    while (1) {
        printf("발사 각도(도)와 파워(1~100)를 입력하세요 (예: 45 50): ");
        scanf("%lf %lf", &angle, &power);

        // 각도를 라디안으로 변환
        angle = angle * PI / 180.0;

        // 포탄이 날아간 거리 계산 (간단한 물리 공식 사용)
        distance = (power * power * sin(2 * angle)) / 9.81;

        printf("포탄은 약 %.2f 미터를 날아갔습니다!\n", distance);

        // 명중 여부 체크
        if (distance >= target - 5 && distance <= target + 5) {
            printf("축하합니다! 상대 탱크를 명중시켰습니다!\n");
            break;
        }
        else {
            printf("아쉽게도 빗나갔습니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
