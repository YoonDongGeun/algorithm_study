#include <iostream>
#define F(x,X) for (int x=0;x<X;++x) 
#define F_(x,X) for (int x=1;x<=X;++x)
#define RF(x,X) for (int x=X;x>0;--x)
struct shark {
	int i, j, d;
};
struct smell {
	int n, a;
};

int di[4] = { 0,-1,1,0 }, dj[4] = { 1,0,0,-1 };

int N, M,K,time=0,temp,cnt=0;
shark order[401];
smell sea[21][21];
int pd[401][4][4];

int main() {
	scanf("%d %d %d", &N, &M, &K);
	F(i, N) F(j, N) {
		scanf("%d", &sea[i][j].n);
		if (sea[i][j].n) {
			order[sea[i][j].n] = { i,j,0 };
			sea[i][j].a = K;
		}
		else {
			sea[i][j].a = 0;
		}
	}
	F_(n, M) { scanf("%d", &order[n].d); order[n].d %= 4; }
	F_(n, M) F_(d, 4) F(o, 4) {
		scanf("%d", &pd[n][d%4][o]);
		pd[n][d%4][o] %= 4;
	}

	while (++time < 1001) {

		int can_list[21][21];
		F(i, N) F(j, N) can_list[i][j] = sea[i][j].n;

		RF(n, M) {
			if (order[n].i == -1) continue;
			int flag = 0;
			F(o, 4) {
				int d = pd[n][order[n].d][o];
				int ni = order[n].i + di[d], nj = order[n].j + dj[d];
				if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
				if (!can_list[ni][nj]) {
					if (sea[ni][nj].n) {
						++cnt;
						order[sea[ni][nj].n].i = -1;
					}
					order[n] = { ni,nj,d };
					sea[ni][nj] = { n,K+1 };
					flag = 1;
					break;
				}
				
			}
			if (flag) continue;
			F(o, 4) {
				int d = pd[n][order[n].d][o];
				int ni = order[n].i + di[d], nj = order[n].j + dj[d];
				if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
				if (sea[ni][nj].n==n) {
					order[n] = { ni,nj,d };
					sea[ni][nj] = { n,K+1 };
					break;
				}
			}

		}
		F(i, N) F(j, N) if (sea[i][j].a) if (!(--sea[i][j].a)) sea[i][j].n = 0;
		if (cnt == M - 1) break;
	}
	if (time == 1001) time = -1;
	printf("%d", time);
}