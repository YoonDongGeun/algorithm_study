#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ax {
	int I;
	int J;
};

struct DP{
	int I;
	int J;
	int D;
};

int N, M, ans=0,ans_sub = 0;
char c[1002];
bool visit_S[1002][1002];
bool visit_E[1002][1002];
int dp_S[1002][1002] = { 0, };
int dp_E[1002][1002] = { 0, };
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
vector <ax> wall;
queue <DP> Q;


int main() {
	scanf("%d %d", &N, &M);
	for (int j = 0; j <= M + 1; ++j) { visit_S[0][j] = 1; visit_E[0][j] = 1; }
	for (int i = 1; i <= N; ++i) {
		visit_S[i][0] = 1;
		visit_E[i][0] = 1;
		visit_S[i][M + 1] = 1;
		visit_E[i][M+1] = 1;
		scanf("%s", c);
		for (int j = 1; j <= M; ++j) {
			if (c[j-1] - '0') {
				visit_S[i][j] = 1;
				visit_E[i][j] = 1;
				wall.push_back({ i,j });
			}
		}
	}
	for (int j = 0; j <= M + 1; ++j) { visit_S[N + 1][j] = 1; visit_E[N + 1][j] = 1;
	}

	Q.push({ 1,1,1 });
	dp_S[1][1] = 1;
	visit_S[1][1] = 1;

	while (!Q.empty()) {
		DP A = Q.front();
		Q.pop();
		for (int d=0; d < 4; ++d) {
			DP B = { A.I + di[d],A.J + dj[d],A.D + 1 };
			if (!visit_S[B.I][B.J]) { 
				visit_S[B.I][B.J] = 1;
				Q.push(B);
				dp_S[B.I][B.J] = B.D;
			}
		}
	}

	ans = dp_S[N][M];

	Q.push({ N,M,1 });
	dp_E[N][M] = 1;
	visit_E[N][M] = 1;

	while (!Q.empty()) {
		DP A = Q.front();
		Q.pop();
		for (int d = 0; d < 4; ++d) {
			DP B = { A.I + di[d],A.J + dj[d],A.D + 1 };
			if (!visit_E[B.I][B.J]) {
				visit_E[B.I][B.J] = 1;
				Q.push(B);
				dp_E[B.I][B.J] = B.D;
			}
		}
	}


	for (int i = 0; i < wall.size(); ++i) {
		for (int s = 0; s < 4; ++s) {
			for (int e = 0; e < 4; ++e) {
				if (s == e) continue;
				int S = dp_S[wall[i].I + di[s]][wall[i].J + dj[s]];
				if (!S) continue;
				int E = dp_E[wall[i].I + di[e]][wall[i].J + dj[e]];
				if (!E) continue;
				ans_sub = E + S + 1;
				if (ans == 0 || ans_sub < ans) ans = ans_sub;
			}
			}
		}

	if (!ans) ans = -1;
	printf("%d", ans);

	}
			


	/*for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) printf("%d", dp[i][j]);
		printf("\n");
	}
	printf("\n");*/


	/*for (int i = 0; i < wall.size(); ++i) {
		vector <int> S, E;
		for (int d = 0; d < 4; ++d) {
			ax C = { wall[i].I + di[d],wall[i].J + dj[d] };
			if (dp[C.I][C.J]) {
					E.push_back(dp[C.I][C.J]);
			}
		}
		if (!S.empty() && !E.empty()) {
			sort(S.begin(), S.end());
			sort(E.begin(), E.end());
			int ans_sub = S[0] + E[0] + 1;
			if (ans == 0 || ans_sub < ans) ans = ans_sub;
		}
	}*/

