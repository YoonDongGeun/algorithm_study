#include <iostream>
using namespace std;

// 시간 오래걸린 코드 (DFS)
// 
// 구현 방법
// 1. 입력받은 배열 하나씩 돌면서 점 기준 오른쪽(시작점)이 같은지 확인
// 2. 같다면, 한바퀴 돌고 올 곳은 점 기준 아래쪽 (도착점)
// 3. dfs에서 돌면서 도착점을 거쳐갈 수 있는지 확인
// 
// 3-1. 시작점과 다른 점이 있으면 무시, 이미 사용했던 점이면 무시
// 
// 더 좋은 방법은 거쳐온 방향은 제외하면 됐었다ㅠ

int N, M;
char board[50][50];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ey, ex;
bool used[50][50];
char check;
bool ans;

void dfs(int y, int x,int dir)
{
	if (y == ey && x == ex)
	{
		ans = 1;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int k = (dir + i) % 4;
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (board[ny][nx] != check || used[ny][nx] == 1) continue;
		used[ny][nx] = 1;
		dfs(ny, nx, dir + i);
		used[ny][nx] = 0;
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
			if (board[y][x] == board[y][x + 1])
			{
				ey = y+1;
				ex = x;
				used[y][x] = 1;
				used[y][x + 1] = 1;
				check = board[y][x];
				dfs(y, x+1, 0);
				if (ans == 1) break;
			}
		}
		if (ans == 1) break;
	}
	if (ans == 1) cout << "Yes";
	else cout << "No";
	return 0;
}

// 더 좋은 방법
//#include <cstdio>
//
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,-1,0,1 };
//
//int n, m, ans = 1;
//char map[50][51];
//bool visit[50][50] = { false };
//
//bool dfs(int x, int y, int d) {
//	visit[x][y] = true;
//	for (int i = 0; i < 4; i++) {
//		if ((i + 2) % 4 == d) continue; // 이전에 지나친 지점 제외
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[x][y] != map[nx][ny]) continue;
//		if (visit[nx][ny]) return false;
//		if (!dfs(nx, ny, i)) return false;
//	}
//	return true;
//}
//
//int main() {
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) scanf("%s", map[i]);
//	for (int i = 0; i < n && ans; i++) {
//		for (int j = 0; j < m && ans; j++) {
//			if (visit[i][j]) continue;
//			if (!dfs(i, j, -1)) ans = 0;
//		}
//	}
//	printf("%s", ans ? "No" : "Yes");
//}