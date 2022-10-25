#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define F(x,X) for (int x=0;x<X;++x)

struct AX {
	int i, j;
};
struct fish {
	int n, d;
};
AX sq[17];
fish sea[4][4];

int di[8] = { -1,-1,-1,0,1,1,1,0 };
int dj[8] = { 1,0,-1,-1,-1,0,1,1 };
int MAX = 0;


void go() {
	for (int x = 1; x < 17; ++x) {
		int i = sq[x].i, j = sq[x].j;
		if (i == -1) continue;
		while (1) {
			int ni = i + di[sea[i][j].d], nj = j + dj[sea[i][j].d];
			if (ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && sea[ni][nj].n) {
				if (sea[ni][nj].n == -1) {
					sq[x] = { ni,nj };
					sea[ni][nj] = sea[i][j];
					sea[i][j] = { -1,-1 };
					break;
				}
				AX temp = sq[sea[i][j].n];
				sq[sea[i][j].n] = sq[sea[ni][nj].n];
				sq[sea[ni][nj].n] = temp;
				fish temp2 = sea[i][j];
				sea[i][j] = sea[ni][nj];
				sea[ni][nj] = temp2;
				break;
			}
			else sea[i][j].d = (sea[i][j].d+1)%8;
		}
	}
}


void dfs(int sum) {
	if (sum > MAX) MAX = sum;
	AX sq_save[17];
	fish sea_save[4][4];
	F(i, 17) sq_save[i] = sq[i];
	F(i, 4) F(j, 4) sea_save[i][j] = sea[i][j];
	go();
	int i = sq[0].i, j = sq[0].j;
	for (int c = 1; c < 4; ++c) {
		int ni = i + c*di[sea[i][j].d], nj = j + c*dj[sea[i][j].d];
		if (ni >= 0 && ni < 4 && nj >= 0 && nj < 4 && sea[ni][nj].n>0) {
			fish saved_fish = sea[ni][nj];
			fish saved_shark = sea[i][j];
			sq[0] = { ni,nj };
			sq[saved_fish.n] = { -1,-1 };
			sea[ni][nj].n = 0;
			sea[i][j] = { -1,-1 };
			dfs(sum + saved_fish.n);
			sea[i][j] = saved_shark;
			sea[ni][nj] = saved_fish;
			sq[saved_fish.n] = { ni,nj };
			sq[0] = { i,j };
		}
	}
	F(i, 17) sq[i] = sq_save[i];
	F(i, 4) F(j, 4) sea[i][j] = sea_save[i][j];

}




int main() {
	F(i, 4) F(j, 4) {
		scanf("%d %d", &sea[i][j].n, &sea[i][j].d);
		sq[sea[i][j].n] = {i,j};
		if (sea[i][j].d == 8) sea[i][j].d = 0;
	}
	int v= sea[0][0].n;
	sq[sea[0][0].n] = { -1,-1 };
	sea[0][0].n = 0;
	dfs(v);
	printf("%d", MAX);
}


