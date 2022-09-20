#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// 구현 단계 (DFS // DFS)
// 1. 순환선 찾기 (DFS)
// 2. 순환선과 역에서 거리 찾기 (DFS) - BFS로 풀어야 빠르다
// 
// 1-1. 순환선이 되기 위해선 적어도 3개 노드 필요(1번 이상 더해주면 조건 걸음)
// 1-2. 돌다가 순환선 찾으면 끝
// 1-3. 못찾으면 used 초기화 시키고 다음 역으로 순환선 찾기

int N, a, b;
bool ring[3001];
bool used[3001];
vector <int> subway[3001];
int ans = 1e9;
bool flag;
int start;

void circle(int now, int cnt)
{
	if (now == start && cnt > 1)
	{
		flag = 1;
		return;
	}

	used[now] = 1;
	for (int i = 0; i < int(subway[now].size()); i++)
	{
		//used 확인하기!
		int next = subway[now][i];
		if (!used[next]) circle(next, cnt + 1);
		else
			if (next == start && cnt > 1)
				circle(next, cnt);
		if (flag) return;
	}
}

// 이걸 BFS로
void shortcut(int now, int cnt)
{
	if (ring[now])
	{
		if (ans > cnt) ans = cnt;
		return;
	}

	for (int i = 0; i < int(subway[now].size()); i++)
	{
		int k = subway[now][i];
		if (used[k]) continue;
		used[k] = 1;
		shortcut(k, cnt + 1);
		used[k] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		subway[a].push_back(b);
		subway[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		flag = 0;
		start = i;
		circle(i, 0);
		if (flag) ring[i] = 1;
		memset(used, 0, sizeof(used));
	}

	for (int i = 1; i <= N; i++)
	{
		if (!ring[i])
		{
			shortcut(i, 0);
			cout << ans << " ";
			ans = 1e9;
		}
		else cout << 0 << " ";
	}
}

// DFS + BFS 섞은 코드

//#include <stdio.h>
//#include <vector>
//#include <queue>
//using namespace std;
//#define SIZE 3001
//
//int N;
//vector<int> graph[SIZE];
//bool visited[SIZE] = { false, };
//int parent[SIZE];
//int dist[SIZE];
//queue<int> q;
//
//int DFS(int u, int prev) {
//	visited[u] = true;
//	parent[u] = prev;
//	int size = graph[u].size(), x, res;
//	for (int i = 0; i < size; i++) {
//		x = graph[u][i];
//		if (x == prev) continue;
//		else if (visited[x]) {
//			parent[x] = u;
//			return x;
//		}
//		res = DFS(x, u);
//		if (res > 0) return res;
//	}
//	return -1;
//}
//
//void BFS() {
//	while (!q.empty()) {
//		int u = q.front(); q.pop();
//		int size = graph[u].size(), x;
//		for (int i = 0; i < size; i++) {
//			x = graph[u][i];
//			if (visited[x]) continue;
//			if (dist[x] == 0) continue;
//
//			visited[x] = true;
//			dist[x] = dist[u] + 1;
//			q.push(x);
//		}
//	}
//}
//
//int main() {
//	int a, b;
//	scanf("%d", &N);
//
//	for (int i = 0; i < N; i++) {
//		scanf("%d %d", &a, &b);
//		graph[a].push_back(b);
//		graph[b].push_back(a);
//	}
//
//	int start = DFS(1, -1);
//
//	for (int i = 1; i <= N; i++) {
//		visited[i] = false;
//		dist[i] = -1;
//	}
//
//	int k = start;
//	do {
//		dist[k] = 0;
//		if (graph[k].size() > 2) {
//			visited[k] = true;
//			q.push(k);
//		}
//		k = parent[k];
//	} while (k != start);
//
//	BFS();
//
//	for (int i = 1; i <= N; i++)
//		printf("%d ", dist[i]);
//	return 0;
//}