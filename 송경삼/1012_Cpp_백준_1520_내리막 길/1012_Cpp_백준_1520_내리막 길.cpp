#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int N, M;
int field[500][500];
bool visit[500][500]={0,};
int dp[500][500];
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int dfs(int i,int j) {
	if (i == N - 1 && j == M - 1) return 1;
	int& ret = dp[i][j];
	if (ret != -1) return ret;
	else {
		ret = 0;
		for (int d = 0; d < 4; ++d) {
			int ni = i + di[d], nj = j + dj[d];
			if (ni < 0 || ni >= N || nj < 0 || nj >= M || field[ni][nj] >= field[i][j] || visit[ni][nj]) continue;
			ret = ret + dfs(ni, nj);
		}
		return ret;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &field[i][j]);
			dp[i][j] = -1;
		}
	}
	visit[0][0] = 1;
	dfs(0, 0);
	printf("%d", dp[0][0]);
}