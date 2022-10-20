#include <iostream>
#define F(x,X) for (int x=0;x<X;++x)
int N, min=1e10;
int field[100][100];
int di[4] = { 0,1,0,-1 }, dj[4] = { 1,0,-1,0 };

void dfs(int i, int j, int n,int num){
	if (n >= min) return;
	F(d, 4) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || nj < 0 || ni >= N || nj >= N || field[ni][nj] == num) continue;
		if (field[ni][nj]) {
			if (n < min)min = n;
			return;
		}
		dfs(ni, nj, n + 1, num);
	}
}

void makeland(int i, int j, int num) {
	field[i][j] = num;
	F(d, 4) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || nj < 0 || ni >= N || nj >= N || field[ni][nj] != 1) continue;
		makeland(ni, nj, num);
	}
}


int main() {
	scanf("%d", &N);
	int num = 1;
	F(i, N) F(j, N) scanf("%d", &field[i][j]);
	F(i, N) F(j, N) if (field[i][j]==1) makeland(i, j, ++num);
	F(i, N) F(j, N) if (field[i][j]) dfs(i, j, 0, field[i][j]);
	printf("%d", min);

}