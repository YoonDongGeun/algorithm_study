#include <iostream>
#include <vector>

using namespace std;
struct ax {
	int I;
	int J;
};

vector <ax> good_tomato;
vector <ax> sub;
ax ax_sub;
int di[4] = { 1,0,-1,0 }, dj[4] = {0,1,0,-1};
int N, M, cnt=-1;
int tomato[1001][1001];


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {ax_sub.I = i; ax_sub.J = j; good_tomato.push_back(ax_sub); }
		}
	}
	while (!good_tomato.empty()) {
		++cnt;
		for (int i = 0; i < good_tomato.size(); ++i) {
			for (int d = 0; d < 4; ++d) {
				ax_sub.I = good_tomato[i].I + di[d];
				ax_sub.J = good_tomato[i].J + dj[d];
				if (ax_sub.I >= 0 && ax_sub.I < M && ax_sub.J >= 0 && ax_sub.J < N && !tomato[ax_sub.I][ax_sub.J]) {
					tomato[ax_sub.I][ax_sub.J] = 1;
					sub.push_back(ax_sub);
				}

			}
		}
		good_tomato = sub;
		sub.clear();
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!tomato[i][j]) cnt = -1;
		}
	}
	printf("%d", cnt);
}