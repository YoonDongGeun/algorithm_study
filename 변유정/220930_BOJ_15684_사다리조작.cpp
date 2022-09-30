#include <iostream>
using namespace std;

// 브루트포스, 백트래킹, 구현
// 구현 단계
// 1. 사다리 가로선 - 왼쪽(1), 오른쪽(2)
// 2. 최소 0개 - 최대 3개로 다리 가로선 놓기 (bridge)
// 3. 만약 0 - 1 - 2 - 3 늘려가면서 ans가 바뀌면 그게 최솟값
// 4. 쭉쭉 내려가다가 처음 시작점과 끝점이 같으면 통과 (line)
// 5. 세로선 모두 가능하면 끝

// ladder 왼쪽, 오른쪽으로 나눠서 1,2로 구분했는데
// bool 형식으로 하거나 if 문 줄이면 시간을 더 줄일 수 있음

int N, M, H, ladder[32][12];
int ans = 4;

int line()
{
	int flag = 0;
	for (int i = 1; i <= N; i++)
	{
		int sy = 1;
		int sx = i;
		while (true)
		{
			if (sy > H) break;
			if (ladder[sy][sx] == 1) // 왼쪽점이면 오른쪽으로 이동
				sx++;
			else if (ladder[sy][sx] == 2) // 오른쪽이면 왼쪽으로 이동
				sx--;
			sy++;
		}
		if (sx != i) flag = 1;
		if (flag == 1) break;
	}
	return flag;
}

void bridge(int cnt, int sy, int goal)
{
	if (cnt == goal)
	{
		if (line() == 0) ans = cnt;
		return;
	}

	for (int y = sy; y <= H; y++)
		for (int x = 1; x < N; x++)
		{
			if (ladder[y][x] != 0 || ladder[y][x + 1] != 0) continue;
			ladder[y][x] = 1;
			ladder[y][x + 1] = 2;
			bridge(cnt + 1, y, goal);
			ladder[y][x] = 0;
			ladder[y][x + 1] = 0;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
		ladder[a][b + 1] = 2;
	}
	for (int i = 0; i < 4; i++)
	{
		bridge(0,1,i);
		if (ans != 4) break;
	}
	if (ans == 4) cout << -1;
	else cout << ans;
}