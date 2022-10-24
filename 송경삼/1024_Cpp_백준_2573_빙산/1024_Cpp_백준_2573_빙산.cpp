#include <iostream>
#define F(x,X) for (int x=0;x<X;++x)
#define F_(x,X) for (int x=1;x<X-1;++x)

struct Q {
	int i, j;
};

int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
int field[300][300];
int melting[300][300]={0,};
int N, M;
Q temp[10001];
Q stack[10001];

int main() {
	scanf("%d %d", &N, &M);
	F(i, N) F(j, M) scanf("%d", &field[i][j]);
	F_(i, N) F_(j, M) if (field[i][j]) F(d, 4) if (!field[i + di[d]][j + dj[d]]) melting[i][j]++;
	int t = 0;
	while (++t) {
		int pt = 0;
		F_(i, N) F_(j, M) {
			if (field[i][j]) {
				field[i][j] -= melting[i][j];
				if (field[i][j] <= 0) {
					field[i][j] = 0;
					temp[pt++] = { i,j };
				}
			}
		}
		int sp = 0;
		bool flag1=0, flag2=0, flag3=1;
		bool visit[300][300] = { 0 ,};
		F(i, N) {
			F(j, M) {
				if (field[i][j]) {
					flag3 = 0;
					if (!visit[i][j]) {
						if (flag1) { flag2 = 1; break; }
						flag1 = 1;
						stack[sp++] = { i,j };
						while (sp > 0) {
							int ai = stack[--sp].i, aj = stack[sp].j;
							visit[ai][aj] = 1;
							F(d, 4) {
								int bi = ai + di[d], bj = aj + dj[d];
								if (field[bi][bj] && !visit[bi][bj]) {
									stack[sp++] = { bi,bj };
								}
							}
						}
					}
					}
				}
			if (flag2) break;
			}
		if (flag3) { t = 0; break; }
		if (flag2) break;
		F(q, pt) F(d, 4) melting[temp[q].i + di[d]][temp[q].j + dj[d]]++;
	}
	printf("%d\n", t);




}
