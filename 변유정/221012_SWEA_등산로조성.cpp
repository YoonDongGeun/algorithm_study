#include <iostream>
using namespace std;

// 봉우리에서 시작하는 법 다시 풀기

int N, K, ans, map[9][9];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void find_long(int y, int x, int cnt, int mxx)
{
	if (map[y][x] == mxx)
	{
		ans = max(ans, cnt);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[ny][nx] > map[y][x]) find_long(ny, nx, cnt + 1, mxx);
	}
}

void start_(int mxx)
{
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			find_long(y, x, 1, mxx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		ans = 0;
		cin >> N >> K;
		int mxx = -1;
		for (int y = 0;y<N;y++)
			for (int x = 0; x < N; x++)
			{
				cin >> map[y][x];
				mxx = max(mxx, map[y][x]);
			}

		for (int i = 0; i <= K; i++)
		{
			for (int y = 0; y < N; y++)
			{
				for (int x = 0; x < N; x++)
				{
					map[y][x] -= i;
					start_(mxx);
					map[y][x] += i;
				}
			}
		}
		cout << "#" << tc << " " << ans << '\n';
	}
}