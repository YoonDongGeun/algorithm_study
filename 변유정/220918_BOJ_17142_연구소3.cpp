#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

//BFS + DFS 
// 문제 설명이 애매하게 되어있음
// 1. 칸이 2일 때도 지나갈수 있다 (이동시간도 동일)
// 2. 그러나 0이 모두 바뀌었을 때는, 2를 굳이 지나갈 필요가 없어진다.
// 
// 3. 그렇기 때문에 현재 연구소 안의 0의 개수를 모두 세어주고,
// - 하나씩 바이러스 퍼질 때마다 0의 개수를 세어줘야한다. 
// 4. 만약 0이 모두 바이러스로 바뀌었을 때 더 진행하지 말고 멈춰야 한다.
//
// 나머지는 연구소 2와 동일하게 구현
// 예제 + 반례 참고 : https://www.acmicpc.net/board/view/43303


int N, M, lab[50][50];
vector <pair<int, int>> virus;
bool used_v[10];
int zero = 0;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int ans = 1e9;
vector <pair<int, int>> v;

int bfs()
{
	int used_b[50][50] = { 0, };
	queue<pair<int, int>> temp;
	for (int i = 0; i < M; i++)
	{
		int ty = v[i].first;
		int tx = v[i].second;
		temp.push({ ty,tx });
		used_b[ty][tx] = 1;
	}
	int result = 0;
	// 이번 경우에서 퍼진 0의 개수
	int zero_cnt = 0;
	while (!temp.empty())
	{
		int y = temp.front().first;
		int x = temp.front().second;
		temp.pop();
		// 바이러스로 변한 0의 개수가 원래 0의갯수와 동일할때
		if (zero_cnt >= zero) break;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (lab[ny][nx] == 1 || used_b[ny][nx] != 0) continue;
			// 0일때마다 개수 더해주기
			if (lab[ny][nx] == 0) zero_cnt++;
			used_b[ny][nx] = used_b[y][x] + 1;
			// 나름의 가지치기 - 구해둔 min값보다 커지면 큰 값 리턴
			if (used_b[ny][nx] > ans) return 1e9;
			temp.push({ ny, nx });
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (lab[y][x] == 0 && used_b[y][x] == 0) return 1e9;
			else if (used_b[y][x] > result) result = used_b[y][x];
		}
	}
	return result-1;
}

void dfs(int now,int cnt)
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
		dfs(i,cnt + 1);

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
			else if (lab[y][x] == 0) zero++;
		}
	}
	dfs(0,0);
	if (ans == 1e9) cout << -1;
	else cout << ans;
}