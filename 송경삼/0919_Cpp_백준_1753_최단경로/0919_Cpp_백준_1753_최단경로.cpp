#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, S,st,ed,va,q;
vector<pair<int,int>> G[20001];		//간선의 정보를 저장할 공간입니다.
priority_queue <pair<int,int>> Q;
int ans[20001];

int main() {
	scanf("%d %d",&V, &E);
	scanf("%d", &S);
	fill(ans, ans + V + 1, 1e9);	//정답 배열을 1e9로 초기화합니다

	for (int v = 1; v <= E; ++v) {
		scanf("%d %d %d", &st, &ed, &va);
		G[st].push_back({ -va,ed });	//간선의 정보를 담아서 저장공간에 저장합니다. 근데,
	}																//우선순위큐를 최소값으로 사용하기 위해 value에 -를 붙여서 넣습니다
	Q.push({ 0,S });		//초기 값과 시작위치입니다.
	ans[S] = 0;

	while (!Q.empty()) {			//우선순위큐가 빌 때 까지
		int cost = -Q.top().first;	//최소 경로값을 지닌 간선을 꺼냅니다
		int now = Q.top().second;
		Q.pop();
		
		for (int i = 0; i < G[now].size(); ++i) {
			int to = G[now][i].second;		// 해당 경로로 이동한 노드를 탐색하면서
			int co = -G[now][i].first;
			if (cost +co < ans[to]) {			
				ans[to] = cost + co;				// 해당 노드의 경로값을 최소값으로 갱신하고
				Q.push({ -ans[to],to });		// 우선순위큐에 넣습니다.
			}
		}
		
	}

	for (int i = 1; i <= V; ++i) {
		if(ans[i]!=1e9) printf("%d\n", ans[i]);
		else printf("INF\n");
	}
}