#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// BFS + DFS
// 구현단계
// 1. 바이러스 놓는 칸 2(virus)를 벡터에 저장하기
// 2. 그 칸 중 M개 만큼 선택하기
// 3. M개에서 BFS 후 걸리는 시간 되돌려주기
// 3-1. 0,2를 모두 바이러스로 퍼지게 했으면 걸린시간 되돌려주고
// 3-2. 그렇지 않다면 1e9 되돌려주기
// 
// 4. 그 중 가장 작은 값 출력
// 4-1. 만약 가장 작은 값이 1e9면 -1 출력 (모든 경우의 수가 0,2를 바이러스로
// 못퍼지게 만들었음)


int N, M, lab[50][50];
// virus - 바이러스 놓을 수 있는 칸 저장소
vector <pair<int, int>> virus;
// used_v - 그 칸을 사용했는지
bool used_v[10];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int ans = 1e9;
// v - 경우의수 M개 바이러스 저장소
vector <pair<int, int>> v;

int bfs()
{
	// used_b - 그 칸을 사용했는지 안했는지 확인
	int used_b[50][50] = { 0, };
	// temp - 바이러스를 퍼지게 할 큐
	queue<pair<int, int>> temp;
	for (int i = 0; i < M; i++)
	{
		int ty = v[i].first;
		int tx = v[i].second;
		temp.push({ ty,tx });
		used_b[ty][tx] = 1;
	}
	int result = 0;
	while (!temp.empty())
	{
		int y = temp.front().first;
		int x = temp.front().second;
		temp.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (lab[ny][nx] == 1 || used_b[ny][nx] != 0) continue;
			used_b[ny][nx] = used_b[y][x] + 1;
			// 나름의 가지치기
			if (used_b[ny][nx] > ans) return 1e9;
			temp.push({ ny, nx });
		}
	}
	// 0또는 2를 모두 바이러스 퍼지게 만들었는지 확인
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (lab[y][x] != 1 && used_b[y][x] == 0) return 1e9;
			else if (used_b[y][x] > result) result = used_b[y][x];
		}
	}
	return result - 1;
}

// 경우의수 만들기
void dfs(int now, int cnt)
{
	if (cnt == M)
	{
		int k = bfs();
		if (k < ans) ans = k;
		return;
	}

	for (int i = now; i < virus.size(); i++)
	{
		if (used_v[i] == 1) continue;
		int y = virus[i].first;
		int x = virus[i].second;
		used_v[i] = 1;
		v.push_back({ y,x });
		dfs(i, cnt + 1);

		v.pop_back();
		used_v[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> lab[y][x];
			if (lab[y][x] == 2)
				virus.push_back({ y,x });
		}
	}
	dfs(0, 0);
	if (ans == 1e9) cout << -1;
	else cout << ans;
}