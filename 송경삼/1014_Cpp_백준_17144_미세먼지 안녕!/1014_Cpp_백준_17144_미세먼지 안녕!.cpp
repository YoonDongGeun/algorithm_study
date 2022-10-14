#include <iostream>
#define F(x,X) for(int x=0; x<X;++x)

int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main() {
	int N, M, T;
	scanf("%d %d %d", &N, &M, &T);
	int air[51][51][2] = { 0, };
	int ac=-1;
	F(i, N) {
		F(j, M) {
			scanf("%d", &air[i][j][0]);
			if (air[i][j][0] == -1 and ac==-1) {
				air[i][j][1] = -1;
				air[i + 1][j][1] = -1;
				ac = i;
			}
		}
	}

	int b = 0, a = 1;
	for ( int t = 1; t <= T; t++) {

		b = 1 - b;
		a = 1 - a;
		
		F(i, N) {
			F(j, M) {
				if (air[i][j][a]>0) {
					int Q = air[i][j][a];
					int amount = air[i][j][a] / 5;
					F(d, 4) {
						int ni = i + di[d], nj = j + dj[d];
						if (ni < 0 || ni >= N || nj < 0 || nj >= M || air[ni][nj][a]==-1) continue;
						air[ni][nj][b] += amount;
						Q-= amount;

					}
					air[i][j][b] += Q;
				}
			}
		}

		F(i, N) {
			F(j, M) {
				if (air[i][j][a]!=-1) air[i][j][a] = 0;
			}
		}

		int aci1,aci2,acj=0;
		for (aci1 = ac - 1; aci1 > 0; --aci1) {
			air[aci1][acj][b] = air[aci1-1][acj][b];
		}


		for (aci2 = ac + 2; aci2 < N-1; ++aci2) {
			air[aci2][acj][b] = air[aci2+1][acj][b];
		}

		for (; acj < M - 1; ++acj) {
			air[aci1][acj][b] = air[aci1][acj + 1][b];
			air[aci2][acj][b] = air[aci2][acj + 1][b];
		}
		for (; aci1 < ac; ++aci1) {
			air[aci1][acj][b] = air[aci1 + 1][acj][b];
		}

		for (; aci2 > ac+1; --aci2) {
			air[aci2][acj][b] = air[aci2 -1][acj][b];
		}
		for (; acj > 1; --acj) {
			air[aci1][acj][b] = air[aci1][acj - 1][b];
			air[aci2][acj][b] = air[aci2][acj - 1][b];
		}
		air[aci1][1][b] = 0; air[aci2][1][b] = 0;

	}
	int ans = 2;
	F(i, N) {
		F(j, M) {
			ans += air[i][j][b];
		}
	}
	printf("%d", ans);

}