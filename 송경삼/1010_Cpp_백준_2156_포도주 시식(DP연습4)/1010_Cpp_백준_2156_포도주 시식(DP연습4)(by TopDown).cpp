#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int dfs(int n, int dd, int* wine, int(* dp)[3], int& N) {
	if (dd > 2) return -1e10; 
	if (n >= N) return 0;
	int& ret = dp[n][dd];
	if (ret != -1) return ret;
	else {
		ret = max(dfs(n + 1, 0, wine, dp, N), dfs(n + 1, dd + 1, wine, dp, N) + wine[n]);
		return ret;
	}
}

int main() {
	int N;
	int wine[10001];
	int dp[10001][3];
	scanf("%d", &N);
	for (int n = 0; n < N; ++n) {
		scanf("%d", &wine[n]);
		dp[n][0] = -1;
		dp[n][1] = -1;
		dp[n][2] = -1;
	}
	printf("%d",dfs(0, 0, wine, dp, N));
}