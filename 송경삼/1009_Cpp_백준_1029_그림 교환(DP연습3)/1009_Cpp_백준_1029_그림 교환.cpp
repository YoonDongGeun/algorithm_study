#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N;
int pnt[15][15];
int dp[1 << 15][15][10];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int dfs(int visited, int num, int value){
	int& ret = dp[visited][num][value];
	
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i < N; ++i) {
		if ((visited & (1 << i)) == 0 && pnt[num][i] >= value) {
			ret = max(ret, dfs(visited | (1 << i), i, pnt[num][i])+1);
		}
	}
	return ret;
}



int main() {
	
	scanf("%d", &N);
	char sub[16];
	for (int i = 0; i < N; ++i) {
		scanf("%s", &sub);
		for (int j = 0; j < N; ++j) {
			pnt[i][j] = sub[j] - '0';
		}
	}
	for (int x = 0; x < (1<<15); ++x) {
		for (int y = 0; y < 15; ++y) {
			for (int z = 0; z < 10; ++z) {
				dp[x][y][z] = -1;
			}
		}
	}
	dfs(1, 0, 0);
	printf("%d", dp[1][0][0]+1);
}