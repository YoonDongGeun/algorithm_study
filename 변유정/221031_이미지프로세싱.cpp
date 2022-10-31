#include <iostream>
#include <queue>
using namespace std;

// 알고리즘 분류 : BFS
// 시간초과 막는 법 (간단한 건데 생각을 하지 못함...)
//
// 1. 바꾸는 색이 이미 칸의 색과 같을 경우 무시
// 2. 이미 방문한 칸을 또 큐에 넣지 않도록 used 배열 사용하기

struct Data
{
	int y, x, color;
};
Data arr[501];
int H, W, N, pixel[129][129];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };

void turn_color(int i, int j, int color)
{
	int origin = pixel[i][j];
	queue <pair<int, int>> q;
	bool used[129][129] = { 0, };
	if (origin != color)
	{
		used[i][j] = 1;
		q.push({ i,j });
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			pixel[y][x] = color;
			q.pop();
			for (int k = 0; k < 4; k++)
			{
				int ny = y + dy[k];
				int nx = x + dx[k];
				if (ny <= 0 || ny > H || nx <= 0 || nx > W || used[ny][nx]) continue;
				if (pixel[ny][nx] == origin)
				{
					used[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> H >> W;
	for (int y = 1; y <= H; y++)
		for (int x = 1; x <= W; x++)
			cin >> pixel[y][x];
	cin >> N;
	for (int k = 0; k < N; k++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		turn_color(a, b, c);
	}
	for (int y = 1; y <= H; y++)
	{
		for (int x = 1; x <= W; x++)
			cout << pixel[y][x] << ' ';
		cout << '\n';
	}
}