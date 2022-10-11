#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int dp[2001][2001];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int dfs(int l, int r, int *lc, int *rc, int& N) {
	if (r >= N || l>=N) {
		return 0;
	}
	int& ret = dp[l][r];
	if (ret != -1) return ret;
	else {
		if (lc[l] > rc[r]) {
			ret = max(dfs(l, r + 1, lc, rc, N) + rc[r], max(dfs(l + 1, r, lc, rc, N), dfs(l + 1, r + 1, lc, rc, N)));
		}
		else
			ret = max(dfs(l + 1, r, lc, rc, N), dfs(l + 1, r + 1, lc, rc, N));
		return ret;
	}


}

int main() {
	int N;
	int lc[2001], rc[2001];
	scanf("%d", &N);
	for (int n = 0; n < N; ++n) scanf("%d", &lc[n]);
	for (int n = 0; n < N; ++n) scanf("%d", &rc[n]);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) dp[i][j] = -1;
	}

	dfs(0, 0, lc, rc, N);
	printf("%d", dp[0][0]);
}