#include <stdio.h>
#define INF 1e10;

int DP[1000001];
int min(int a, int b) {
	if (a > b) return b;
	return a;
}
int main() {
	int N, n = 1;
	scanf("%d", &N);
	DP[1] = 0;
	for (int i = 2; i <= N; ++i) {
		int c1 = INF;
		int c2 = INF;
		int c3 = INF;
		if (!(i % 3)) c1 = DP[i / 3] + 1;
		if (!(i % 2)) c2 = DP[i / 2] + 1;
		if (i > 1) c3 = DP[i - 1] + 1;
		DP[i] = min(c1, min(c2, c3));
	}
	printf("%d", DP[N]);
}