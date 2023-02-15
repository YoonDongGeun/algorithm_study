#include <iostream>
using namespace std;

// 봄버맨
// 알고리즘 : 구현, 그래프탐색, 시뮬레이션
// 구현 방법 : N%2 == 1 일때만 고려해주면 된다, 0일 때는 무조건 폭탄으로 다 채워지기 때문

int R, C, N;
char board[210][210][2];
int dy[5] = { 0,1,0,-1 };
int dx[5] = { 1,0,-1,0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> N;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> board[i][j][1];
			board[i][j][0] = 'O';
		}

	int time = N / 2;
	while (time--)
	{
		for (int i = 1;i<=R;i++)
			for (int j = 1; j <= C; j++)
				if (board[i][j][1] == 'O')
					for (int k = 0; k < 5; k++)
						board[i + dy[k]][j + dx[k]][0] = '.';
		for (int i = 1;i<=R;i++)
			for (int j = 1; j <= C; j++)
			{
				board[i][j][1] = board[i][j][0];
				board[i][j][0] = 'O';
			}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			cout << board[i][j][N % 2];
		cout << "\n";
	}
}