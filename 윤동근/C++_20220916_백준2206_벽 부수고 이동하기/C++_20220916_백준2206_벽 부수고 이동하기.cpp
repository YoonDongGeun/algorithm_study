#include <iostream>
using namespace std;
int N, M;
int map[1000][1000];
int dy[4] = { -1, 0, 1 ,0 };
int dx[4] = { 0, 1, 0, -1 };

void bfs(int x, int y, int cnt, int visited[1000][1000])
{
	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		int Q[100000] = { 0, };
		int *now = Q;

		
		if (0 <= nx && nx < M && 0 <= ny && ny < N)
		{
			if (map[ny][nx] == 0)
			{
				if(visited[ny][nx] == 0)
					visited[ny][nx]=visited[y][x]+1;
			}
			else
			{

				if (cnt == 0)
				{
					ny += dy[i];
					nx += dx[i];
					if (0 <= nx && nx < M && 0 <= ny && ny < N)
					{
						if (map[ny][nx] == 0)
						{
							visited[ny][nx]=visited[y][x]+2;
							bfs(nx, ny, 1, visited);
							visited[ny][nx]=0;
						}
					}
				}

			}
		}



	}



}
main()
{
	int visited[1000][1000] = { 0, };
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int x = 0, y = 0;
	visited[0][0]=1;
	bfs(0, 0, 0, visited);
}


