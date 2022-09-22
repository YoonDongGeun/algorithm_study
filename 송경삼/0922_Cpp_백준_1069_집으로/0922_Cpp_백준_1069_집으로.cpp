#include <iostream>
#include <cmath>
int main() {
	int X, Y, D, K;
	double ans = 0, case2 = 0, case3=0;
	scanf("%d %d %d %d", &X, &Y, &D, &K);
	double d = pow(pow(X, 2) + pow(Y, 2), 0.5); // 집 까지 직선거리 d
	int N = (int) d / D;
																		// 직선으로 이동할 때 도착 직전까지 점프 가능 횟수
	ans = N * K + d - N * D;					// case1 : 직전까지 점프 후 앞으로 걷기 
	case2 = (N + 1)*K + (N+1)*D-d;		// case2 : 직후까지 점프 후 되돌아오며 걷기
	if (N) case3 = (N + 1)*K;					// case3 : 여러개일땐 경로를 비틀며 최소한의 점프로 도착하기
	else case3 = 2 * K;								// 점프가 한번일때 안되므로 최소한 2번
	if (case2 < ans) ans = case2;
	if (case3 < ans) ans = case3;
	if (d<ans) ans=d;									// 그냥 무작정 걷기
	printf("%.13f", ans);							// 최소값 출력
}