#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int totalScore = 0;

    srand(time(NULL));

    for (int round = 1; round <= 5; round++) {

        int dice[5];
        int count[7] = {0};   // 1~6 사용

        // 주사위 굴리기
        for (int i = 0; i < 5; i++) {
            dice[i] = rand() % 6 + 1;
            count[dice[i]]++;
        }

        int pair = 0;
        int triple = 0;
        int four = 0;
        int yacht = 0;

        // 같은 숫자 개수 확인
        for (int i = 1; i <= 6; i++) {
            if (count[i] == 2)
                pair = i;
            else if (count[i] == 3)
                triple = i;
            else if (count[i] == 4)
                four = i;
            else if (count[i] == 5)
                yacht = i;
        }

        int score = 0;
        char rank[20];

        // 요트
        if (yacht) {
            score = 50;
            sprintf(rank, "요트");
        }

        // 스트레이트 확인
        else {
            int straight = 0;

            if ((count[1] && count[2] && count[3] && count[4]) ||
                (count[2] && count[3] && count[4] && count[5]) ||
                (count[3] && count[4] && count[5] && count[6])) {
                straight = 1;
            }

            if (straight) {
                score = 30;
                sprintf(rank, "스트레이트");
            }

            // 풀하우스
            else if (pair && triple) {
                score = 25;
                sprintf(rank, "풀하우스");
            }

            // 포카드
            else if (four) {
                score = four * 4;
                sprintf(rank, "포카드");
            }

            // 트리플
            else if (triple) {
                score = triple * 3;
                sprintf(rank, "트리플");
            }

            // 원페어
            else if (pair) {
                score = pair * 2;
                sprintf(rank, "원페어");
            }

            // 아무 족보도 없음
            else {
                score = 0;
                sprintf(rank, "없음");
            }
        }

        totalScore += score;

        printf("===== %d판 =====\n", round);

        printf("주사위 : ");
        for (int i = 0; i < 5; i++) {
            printf("%d ", dice[i]);
        }
        printf("\n");

        printf("족보 : %s\n", rank);
        printf("점수 : %d\n\n", score);
    }

    printf("===== 게임 종료 =====\n");
    printf("총점 : %d점\n", totalScore);

    return 0;
}