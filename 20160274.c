#include<stdio.h>
void main() {
	int ST = 0, SP = 0;                                                // ST : 스트라이크인 경우 기록을 위한 변수, SP : 스페어인 경우 기록을 위한 변수
	int n, i, r, p, bp;                                                // n : 프레임 수, i : 프레임 안에서 횟수, r : 각 횟수 점수, p : 현제 처리 핀 수, bp : 이전 처리 핀 수
	int sum = 0;                                                       // sum : 누적 점수
	n = 1;
	while (n <= 10) {
		i = 1;
		bp = 0;
		while (i <= 2) {
			printf("%2d번째 프레임 %d 번째 처리 핀 수 : ", n, i);
			scanf("%d", &p);
			if (ST == 3)                                              // 최대 점수는 3배까지 이므로
				ST--;
			if (p == 10 && i == 1) {                                  // 스트라이크인 경우
				ST++;
				r = p * ST;
				sum += r;
				printf("**** 현재까지 점수 :%3d\n", sum);
				i += 2;                                               // 반복문 탈출을 위해 선언
			}
			else if (p + bp == 10) {                                  // 스페어인 경우
				if (ST) {                                             // 이 전 프레임에 스트라이크인 경우
					r = p * (ST);
					sum += r;
				}
				else if (SP) {                                        // 이 전 프레임에 스페어인 경우
					r = p * 2;
					sum += r;
				}
				else {
					sum += p;
				}
				printf("**** 현재까지 점수 :%3d\n", sum);
				SP++;
				i++;
			}
			else if (p + bp < 10 && p + bp >= 0) {                    // 스트라이크 스페어 둘 다 아닌경우
				if (ST) {                                             // 스트라이크인 경우
					r = p * (ST+1);
					sum += r;
				}
				else if (SP) {                                        // 스페어인 경우
					r = p * 2;
					sum += r;
				}
				else {
					sum += p;
				}
				printf("**** 현재까지 점수 :%3d\n", sum);
				bp = p;
				if (i == 2)
					ST = 0;
				SP = 0;
				i++;
			}
			else
				printf("#### 다시 입력하십시오.\n");                   // 볼링 조건에 맞지 않는 수를 입력한 경우
		}
		bp = 0;                                                        // 한 프레임이 끝날때마다 이전 처리 핀 수 초기화
		if (n == 10 && (ST+SP)) {                                      // 10 프레임에서 스트라이크 또는 스페어인 경우
			if (ST)                                                    // 스트라이크인 경우
				i = 2;
			if (SP)                                                    // 스페어인 경우
				i = 3;
			while (i < 4) {
				printf("%2d번째 프레임 %d 번째 처리 핀 수 : ", n, i);
				scanf("%d", &p);
				if (p + bp <= 10) {
					if (p == 10) {                                      // 스트라이크인 경우
						sum += 30;
						i = 3;
					}
					else
						sum += p;
					if (i == 3)
						printf("**** 최종 점수 :%3d\n", sum);
					else
						printf("**** 현재까지 점수 : %3d\n", sum);
					i++;
				}
				else
					printf("#### 다시 입력하십시오.\n");
			}
		}
		n++;
	}
}
