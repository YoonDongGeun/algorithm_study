#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct IJ {
	int I;
	int J;
};


int sea[20][20];
int N, T=0, I,J, sz=2, cnt=0, v;
int di[4] = { -1,0,0,1 };
int dj[4] = { 0,-1,1,0 };
IJ start, sub;


int eat(IJ ioc) {
	int d = 0;
	vector <IJ> now = { ioc }, next, visit = { ioc };
	while (!now.empty()) {
		++d;
		for (int c = 0; c < now.size(); ++c) {
			for (int d = 0; d < 4; ++d) {
				v = 0;

				sub.I = now[c].I + di[d];
				sub.J = now[c].J + dj[d];

				for (int q = 0; q < visit.size(); q++) {
					if (visit[q].I == sub.I && visit[q].J == sub.J) { v = 1; break; }
				}
				if (v == 1) continue;

				if (0 <= sub.I && sub.I < N && 0 <= sub.J && sub.J < N) {
					if (sea[sub.I][sub.J] <= sz) {
						next.push_back(sub);
						visit.push_back(sub);
					}
				}


			}
		}

		if (next.empty()) break;
		IJ SUB = { 1000,1000 };
		for (int w = 0; w < next.size(); ++w) {
			if (sea[next[w].I][next[w].J] && sea[next[w].I][next[w].J] < sz) {
				if (next[w].I < SUB.I) SUB = next[w];
				else if (next[w].I == SUB.I && next[w].J < SUB.J) { SUB = next[w]; }
			}
		}
		if (SUB.I == 1000) { now = next; next = {}; }
		else {
			sea[SUB.I][SUB.J] = 0;
			start = SUB;
			if (++cnt == sz) { cnt = 0; sz++; }
			return d;
		}

	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sea[i][j];
			if (sea[i][j] == 9) {
				sea[i][j] = 0;
				start.I = i;
				start.J = j;
			}
		}
	}

	while (1) {
		int t = eat(start);
		if (t) T += t;
		else break;
	}
	cout << T << "\n";
}
