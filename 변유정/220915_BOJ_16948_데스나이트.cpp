#include <iostream>
#include <queue>
using namespace std;

// 큐 + bfs 기본문제

int N, r1, c1, r2, c2;
// 나이트 저장하는 곳
queue <pair<int, int>> chess;
// 간곳 체크
int board[201][201] = { 0, };

// 갈수있는 곳
int dy[6] = { -2,-2,0,0,2,2 };
int dx[6] = { -1,1,-2,2,-1,1 };
//int dir[6][2] = { {-2, -1}, {-2, 1}, {0, -2,}, {0, 2}, {2, -1}, {2, +1}};

void bfs()
{
	while (!chess.empty())
	{
		int y = chess.front().first;
		int x = chess.front().second;
		chess.pop();
		for (int i = 0; i < 6; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (board[ny][nx] != 0) continue;
			board[ny][nx] = board[y][x] + 1;
			chess.push({ ny, nx });
		}
		if (board[r2][c2] != 0) break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> r1 >> c1 >> r2 >> c2;
	chess.push({ r1,c1 });
	board[r1][c1] = 1;
	bfs();
	cout << board[r2][c2] - 1;
	return 0;
}