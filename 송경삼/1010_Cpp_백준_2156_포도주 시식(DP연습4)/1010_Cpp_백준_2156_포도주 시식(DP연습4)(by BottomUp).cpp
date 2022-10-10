#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	int N;
	int wine[10001];
	int dp[10001]={0,};
	scanf("%d", &N);
	for (int n = 1; n <= N; ++n) scanf("%d", &wine[n]);
	
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for (int n = 3; n <= N; ++n) {
		dp[n] = max(dp[n-1],max(dp[n - 2] + wine[n], dp[n-3]+wine[n]+wine[n-1]));
	}

	printf("%d", max(dp[N],dp[N-1]));
}