#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#define F(x,X) for(int x=0;x<X;++x)

using namespace std;


int N;
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
vector<string> board;
vector<vector<bool>> visit;



void dfs(int i, int j, char q ) {
	visit[i][j] = 1;
	F(d, 4) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || ni >= N || nj < 0 || nj >= N || visit[ni][nj]) continue;
		if (board[ni][nj] == q) {
			visit[i][j] = 1;
			dfs(ni, nj, q);
		}
	}

}




int main() {
	scanf("%d", &N);
	board.resize(N);
	visit.resize(N, vector<bool>(N, 0));
	int cnt1=0, cnt2 = 0;
	F(i, N) cin >> board[i];

	F(i, N)F(j, N) {
		if (!visit[i][j]) {
			dfs(i, j, board[i][j]);
			cnt1++;
		}
	}
	F(i, N)F(j, N) {
		if (board[i][j]=='G') {
			board[i][j] = 'R';
		}
	}
	visit.clear();
	visit.resize(N, vector<bool>(N, 0));
	F(i, N)F(j, N) {
		if (!visit[i][j]) {
			dfs(i, j, board[i][j]);
			cnt2++;
		}
	}
	printf("%d %d", cnt1, cnt2);
}