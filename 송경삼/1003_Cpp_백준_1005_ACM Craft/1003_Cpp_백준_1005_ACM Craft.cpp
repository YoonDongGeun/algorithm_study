#include <iostream>
#include <vector>
#include <queue>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, K, b_t[1001],cnt[1001]={0,}, time[1001]={0,}, s, e, end;
		std::vector <int> edges[1001];
		std::queue <int> Q;

		scanf("%d %d", &N, &K);
		for (int n = 1; n <= N; ++n) scanf("%d", &b_t[n]);
		while (K--) {
			scanf("%d %d", &s, &e);
			edges[s].push_back(e);
			++cnt[e];
		}
		scanf("%d", &end);

		for (int i = 1; i <= N; ++i) {
			if (!cnt[i]) {
				Q.push(i);
				time[i] = b_t[i];
			}
		}
		while (cnt[end]) {
			s = Q.front();
			Q.pop();
			for (int i = 0; i < edges[s].size(); ++i) {
				e = edges[s][i];
				if (time[s] + b_t[e] > time[e]) time[e] = time[s] + b_t[e];
				if (!(--cnt[e])) {
					Q.push(e);
				}
			}
		}
		printf("%d\n", time[end]);

	}

}