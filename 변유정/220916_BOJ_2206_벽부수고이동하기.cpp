#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//
// BFS
// 1. 들렸는지 아닌지
// 2. 다음 갈 곳이 벽인지 아닌지
// 3. 벽이면 벽을 부순적이 있는지 확인
//

struct broke
{
	int y, x;
	int wall;
};

int N, M;
string map[1001];
int used[1001][1001][2] = { 0, };
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue <broke> now;

int bfs()
{
	while (!now.empty())
	{
		int y = now.front().y;
		int x = now.front().x;
		int wall_ = now.front().wall;
		now.pop();
		if (y == N - 1 && x == M - 1) return used[y][x][wall_];
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			// 2단계 + 3단계
			if (map[ny][nx] == '1' && wall_ == 0)
			{
				now.push({ ny,nx,1 });
				used[ny][nx][1] = used[y][x][0] + 1;
			}
			// 1단계
			else if (map[ny][nx] == '0' && used[ny][nx][wall_] == 0)
			{
				now.push({ ny,nx,wall_ });
				used[ny][nx][wall_] = used[y][x][wall_] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
		cin >> map[y];
	now.push({ 0,0,0 });
	used[0][0][0] = 1;
	cout << bfs();
	return 0;
}