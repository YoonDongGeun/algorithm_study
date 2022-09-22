#include <iostream>

int s, N, K, R1, R2, C1, C2, i,j,l,r, n;

int goback(int s,int di, int dj) {	// s:과거로 돌아가야할 횟수, di:현재 i좌표, dj:현재 j좌표
	if ((di%N) >= l && (di%N) < r && (dj%N) >= l && (dj%N) < r) {
      return 1;    // 한 번이라도 해당 영역에 속했던 경우 무조건 검은색입니다.
  }
  if (!s) {				//태초에 도착했다면 0을 돌려줍니다
		return 0;
	}
	return goback(s-1, di / N, dj / N);
}

int main() {
	scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
	l = (N - K)/2;			// 하얀색이 분열할 때 필요한 보조변수 l입니다.
	r = N - l;					// 보조변수 r입니다.
	for (int i = R1; i <= R2; ++i) {
		for (int j = C1; j <= C2; ++j) {
			printf("%d",goback(s,i, j));		// 해당 좌표가 어떤 경로로 온 것인지 추적해서 인쇄합니다.
		}
		printf("\n");
	}
	printf("\n");
}


