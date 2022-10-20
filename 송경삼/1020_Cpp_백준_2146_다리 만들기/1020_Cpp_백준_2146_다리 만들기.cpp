#include <iostream>
#define F(x,X) for (int x=0;x<X;++x)
int N, min = 1e10;
int field[100][100];
int I[10001], J[10001], X[10001];
int idx;
int di[4] = { 0,1,0,-1 }, dj[4] = { 1,0,-1,0 };

int main() {
	scanf("%d", &N);
	int num = 1;
	F(i, N) F(j, N) scanf("%d", &field[i][j]);
	F(i, N) F(j, N) if (field[i][j] == 1) {
		idx = 0; ++num;
		I[idx] = i;J[idx++] = j;
		int ai, aj, bi, bj;
		while (idx) {
			ai = I[--idx]; aj = J[idx];
			field[ai][aj] = num;
			F(d, 4) {
				bi = ai + di[d]; bj = aj + dj[d];
				if (bi < 0 || bj < 0 || bi >= N || bj >= N || field[bi][bj] != 1) continue;
				I[idx] = bi; J[idx++] = bj;
			}
		}
	}

	F(i, N) F(j, N) if (field[i][j]) {
		idx = 0; num=field[i][j];
		I[idx] = i; J[idx] = j, X[idx++]=0;
		int ai, aj, bi, bj, n;
		bool visit[100][100] = { 0, };
		while (idx) {
			ai = I[--idx]; aj = J[idx]; n = X[idx];
			visit[ai][aj] = 1;
			if (n>= min) continue;
			F(d, 4) {
				bi = ai + di[d]; bj = aj + dj[d];
				if (bi < 0 || bj < 0 || bi >= N || bj >= N || visit[bi][bj] ||field[bi][bj] == num) continue;
				if (field[bi][bj]) {
					if (n < min)min = n;
					break;
				}
				I[idx] = bi; J[idx] = bj, X[idx++]=n+1;
			}
		}
	}
	printf("%d", min);

}