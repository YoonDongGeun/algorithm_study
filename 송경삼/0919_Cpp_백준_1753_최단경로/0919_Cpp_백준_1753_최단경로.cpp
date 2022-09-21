#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, S,st,ed,va,q;
vector<pair<int,int>> G[20001];
priority_queue <pair<int,int>> Q;
int ans[20001];

int main() {
	scanf("%d %d",&V, &E);
	scanf("%d", &S);
	fill(ans, ans + V + 1, 1e9);

	for (int v = 1; v <= E; ++v) {
		scanf("%d %d %d", &st, &ed, &va);
		G[st].push_back({ -va,ed });
	}
	Q.push({ 0,S });
	ans[S] = 0;

	while (!Q.empty()) {
		int cost = -Q.top().first;
		int now = Q.top().second;
		Q.pop();
		
		for (int i = 0; i < G[now].size(); ++i) {
			int to = G[now][i].second;
			int co = -G[now][i].first;
			if (cost +co < ans[to]) {
				ans[to] = cost + co;
				Q.push({ -ans[to],to });
			}
		}
		
	}

	for (int i = 1; i <= V; ++i) {
		if(ans[i]!=1e9) printf("%d\n", ans[i]);
		else printf("INF\n");
	}
}