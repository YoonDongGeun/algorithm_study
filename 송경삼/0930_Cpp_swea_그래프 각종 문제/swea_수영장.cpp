#include <iostream>

int min(int a, int b) {
	if (a < b)return a;
	return b;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int fee[4], plan[12], DP[12] = { 0, };
		for (int i = 0; i < 4; ++i) scanf("%d", &fee[i]);
		for (int i = 0; i < 12; ++i) scanf("%d", &plan[i]);
		for (int i = 0; i < 12; ++i) {
			int c1 = ((i > 0) ? DP[i - 1] : 0) + plan[i] * fee[0];
			int c2 = ((i > 0) ? DP[i - 1] : 0) + fee[1];
			int c3 = ((i > 2) ? DP[i - 3] : 0) + fee[2];
			DP[i] = min(fee[3],min(c1, min(c2, c3)));
		}
		printf("#%d %d\n", t, DP[11]);
	}
}