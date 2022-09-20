#include <iostream>
using namespace std;

// 지난 코드와 다른점
// 1. 옆의 값과 같은지 일일이 확인하는 것을 없앰
// 2. 모든 방향을 도는게 아니라 사용한 방향의 반대 방향은 사용하지 않도록 함
// 3. 만약 사용한 지점에 다시 돌아왔다면, 한바퀴 돈것이므로 거기서 멈추기

// 코드가 더 간결해지고 불필요한 것을 제거해서 시간도 더 빨라졌다

int N, M;
char board[50][50];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool used[50][50];
char check;
bool ans;

void dfs(int y, int x, int dir)
{
	used[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		if ((i + 2) % 4 == dir) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (board[ny][nx] != check) continue;
		if (used[ny][nx] == 1) ans = 1;
		used[ny][nx] = 1;
		if (ans == 1) return;
		dfs(ny, nx, i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	for (int y = 0; y < N - 1; y++)
	{
		for (int x = 0; x < M - 1; x++)
		{
			if (used[y][x]) continue;
			check = board[y][x];
			dfs(y, x, 0);
			if (ans) break;
		}
		if (ans) break;
	}
	if (ans) cout << "Yes";
	else cout << "No";
	return 0;
}