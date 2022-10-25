#include <iostream>
#include <vector>
#include <queue>
#define F(x,X) for (int x=0; x<X; ++x)

struct AX{
	int w, v, u, t, s, r, q, p, o, n, m, day;
};

using namespace std;
int M, N, O, P, Q, R, S, T, U, V, W, temp, all_tomato=0, cnt=0, last_day=0;
vector <vector <vector < vector < vector < vector < vector< vector < vector< vector< vector<int > > > > > > > > > > > hyper;
queue <AX> que;
AX tomato,next_tomato;
int dm[22] = { 1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int dn[22] = { 0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int dO[22] = { 0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int dp[22] = { 0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int dq[22] = { 0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0 };
int dr[22] = { 0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0 };
int ds[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0 };
int dt[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0 };
int du[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0 };
int dv[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0 };
int dw[22] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1 };

int main() {
	scanf("%d %d %d %d %d %d %d %d %d %d %d", &M, &N, &O, &P, &Q, &R, &S, &T, &U, &V, &W);
	           
	hyper.resize(W);
	for (auto & sub1 : hyper) {
		sub1.resize(V);
		for (auto & sub2 : sub1) {
			sub2.resize(U);
			for (auto&sub3 : sub2) {
				sub3.resize(T);
				for (auto&sub4 : sub3) {
					sub4.resize(S);
					for (auto&sub5 : sub4) {
						sub5.resize(R);
						for (auto&sub6 : sub5) {
							sub6.resize(Q);
							for (auto&sub7 : sub6) {
								sub7.resize(P);
								for (auto&sub8 : sub7) {
									sub8.resize(O);
									for (auto&sub9 : sub8) {
										sub9.resize(N);
										for (auto&sub10 : sub9) sub10.resize(M);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	F(w, W) F(v, V)	F(u, U)	F(t, T) F(s, S) F(r, R)	F(q, Q)	F(p, P) F(o, O) F(n, N) F(m, M) {
		scanf("%d", &hyper[w][v][u][t][s][r][q][p][o][n][m]);
		if (!hyper[w][v][u][t][s][r][q][p][o][n][m]) ++all_tomato;
		else if (hyper[w][v][u][t][s][r][q][p][o][n][m] == 1) que.push({ w,v,u,t,s,r,q,p,o,n,m,0 });
	}

	if (all_tomato) {
		while (!que.empty()) {
			tomato = que.front();
			que.pop();
			if (tomato.day > last_day) last_day = tomato.day;
			F(d, 22) {
				next_tomato = { tomato.w + dw[d],tomato.v + dv[d],tomato.u + du[d], tomato.t + dt[d], tomato.s + ds[d], tomato.r + dr[d], tomato.q + dq[d], tomato.p + dp[d], tomato.o + dO[d], tomato.n + dn[d], tomato.m + dm[d], tomato.day + 1 };
				if (next_tomato.m < 0 || next_tomato.m >= M) continue;
				if (next_tomato.n < 0 || next_tomato.n >= N) continue;
				if (next_tomato.o < 0 || next_tomato.o >= O) continue;
				if (next_tomato.p < 0 || next_tomato.p >= P) continue;
				if (next_tomato.q < 0 || next_tomato.q >= Q) continue;
				if (next_tomato.r < 0 || next_tomato.r >= R) continue;
				if (next_tomato.s < 0 || next_tomato.s >= S) continue;
				if (next_tomato.t < 0 || next_tomato.t >= T) continue;
				if (next_tomato.u < 0 || next_tomato.u >= U) continue;
				if (next_tomato.v < 0 || next_tomato.v >= V) continue;
				if (next_tomato.w < 0 || next_tomato.w >= W) continue;
				int& ret = hyper[next_tomato.w][next_tomato.v][next_tomato.u][next_tomato.t][next_tomato.s][next_tomato.r][next_tomato.q][next_tomato.p][next_tomato.o][next_tomato.n][next_tomato.m];
				if (!ret) {
					ret = 1;
					++cnt;
					que.push(next_tomato);
				}
			}
		}
	}
	if (cnt == all_tomato) printf("%d\n", last_day);
	else printf("-1");
}
