#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/// 아기상어 문제의 중요한 점
/// 1. 우선순위 정해주기 (거리 - 위쪽 - 왼쪽)
/// 2. 우선순위 큐 + 구조체 이해해서 표현하기
/// 3. bool operator

struct shark {
	int y, x, dist;

	bool operator < (const shark& f) const {
		if (dist == f.dist)
		{
			if (y == f.y) return x > f.x;
			else return y > f.y;
		}
		else return dist > f.dist;
	}
};
int N;
int arr[21][21];
int used[21][21] = {0,};
int baby_size = 2;
int eat_ = 0;
int ans = 0;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
priority_queue <shark> pq;

void bfs() {
	while (!pq.empty())
	{
		int ny = pq.top().y;
		int nx = pq.top().x;
		int ndist = pq.top().dist;
		pq.pop();

		if (arr[ny][nx] > 0 && arr[ny][nx] < baby_size)
		{
			eat_++;
			arr[ny][nx] = 0;
			if (eat_ == baby_size)
			{
				baby_size++;
				eat_= 0;
			}
			ans += ndist;
			ndist = 0;
			memset(used, 0, sizeof(used));

			while (!pq.empty())pq.pop();
		}

		for (int i = 0; i < 4; i++)
		{
			int next_y = ny + dy[i];
			int next_x = nx + dx[i];

			if (next_y >= N || next_y < 0 || next_x >= N || next_x < 0) continue;
			if (used[next_y][next_x] == 1) continue;
			if (arr[next_y][next_x] > baby_size) continue;
			pq.push({ next_y,next_x, ndist + 1 });
			used[next_y][next_x] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int y = 0;y<N;y++)
		for (int x = 0; x < N; x++)
		{
			cin >> arr[y][x];
			if (arr[y][x] == 9)
			{
				pq.push({ y,x,0 });
				arr[y][x] = 0;
				used[y][x] = 1;
			}
		}
	bfs();
	cout << ans << "\n";
}