#include <iostream>
#define F(x,X) for(int x=1;x<=X;++x)
int N, M, H, min = 4, Nsub;
int field[32][11] = { 0, };

bool is_valid() {
	int flag = 1;
	F(x, N) {
		int i = 0, j = x;
		while (++i <= H) {
			j += field[i][j];
		}
		if (x != j) {
			flag = 0;
			break;
		}
	}
	return flag;
}
void dfs(int n, int last) {
	if (is_valid() && n < min) min = n;
	if (n >= 3 || n >= min) return;
	F(i, H) F(j, Nsub) {
		if (i * Nsub + j < last) continue;
		if (!field[i][j] && !field[i][j + 1]) {
			field[i][j] = 1;
			field[i][j + 1] = -1;
			dfs(n + 1, (i*(Nsub)+j) + 1);
			field[i][j] = 0;
			field[i][j + 1] = 0;
		}
	}

}
int main() {
	scanf("%d %d %d", &N, &M, &H);
	Nsub = N - 1;
	int a, b;
	while (M--) {
		scanf("%d %d", &a, &b);
		field[a][b] = 1;
		field[a][b + 1] = -1;
	}
	dfs(0, 1);
	if (min == 4) min = -1;
	printf("%d\n", min);

}