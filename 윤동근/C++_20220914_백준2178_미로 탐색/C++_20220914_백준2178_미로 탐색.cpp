#include <iostream>
using namespace std;

struct position {
	int x;
	int y;
};
int N, M;
int cnt1 = 0;
char str[101][101];

int main()
{
	position move[4] = { {0,1}, {0,-1} , {1,0}, {-1,0} };
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			cin >> str[i][j];
	}

	position pos[100000];
	int visited[100][100];
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			visited[i][j] = 0;
	}

	position *Q = &pos[0];
	pos[0] = { 0,0 };
	int goal = 0;
	position now;
	int temp = 0;
	visited[0][0] = 1;
	while (goal == 0)
	{
		now = *Q;
		Q++;
		for (int i = 0; i < 4; i++)
		{
			if (0 <= now.x + move[i].x < M && 0 <= now.y + move[i].y < N)
			{
				if (str[now.y + move[i].y][now.x + move[i].x] == '1' && visited[now.y + move[i].y][now.x + move[i].x] ==0)
				{
					cnt1++;
					pos[cnt1] = { now.x + move[i].x ,now.y + move[i].y };
					visited[now.y + move[i].y][now.x + move[i].x] = visited[now.y][now.x] + 1;
					if (now.y + move[i].y == N - 1 && now.x + move[i].x == M - 1)
					{
						goal = 1;
						break;
					}
				}

			}
			
		}
	}
	cout << visited[N - 1][M - 1];

	return 0;
}
