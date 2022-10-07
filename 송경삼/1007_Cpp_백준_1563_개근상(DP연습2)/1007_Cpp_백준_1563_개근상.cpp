#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int dfs(int D, int L, int A, int(*dp)[3][4], int& N) {
	if (L == 2 || A == 3) {
		return 0;
	}
	if (D >= N) {
		return 1;
	}
	int &ret = dp[D][L][A];
	if (ret != -1) {
		return ret;
	}
	ret= (dfs(D + 1, L, 0, dp, N) + dfs(D + 1, L + 1, 0, dp, N) + dfs(D + 1, L, A + 1, dp, N))%1000000;
	return ret;
}

int main() {
	int N;
	int dp[1001][3][4];
	for (int x = 0; x < 1001; ++x) {
		for (int y = 0; y < 3; ++y) {
			for (int z = 0; z < 4; ++z) {
				dp[x][y][z] = -1;
			}
		}
	}
	scanf("%d", &N);
	printf("%d",dfs(0, 0, 0, dp, N)%1000000);
}