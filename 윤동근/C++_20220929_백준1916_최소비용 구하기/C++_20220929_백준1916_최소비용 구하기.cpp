#include <iostream>
#include <queue>
#include <vector>

int MAP[1002][1002] = { 0, };
int visited[1002];
std::priority_queue<std::pair<int, int>> q;


int main(void)
{
	int N, M, s, e, w;
	int nows, nowe, noww;
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++)
		visited[i] = 2000000000;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			MAP[i][j] = -1;
		}

	}

	for (int i = 0; i < M; i++)
	{
		std::cin >> s >> e >> w;
		if (MAP[s][e]!=-1)
		{
			if (MAP[s][e] > w)
				MAP[s][e] = w;
		}
		else
		{
			MAP[s][e] = w;
		}
	}

	std::cin >> s >> e; // s시작 e 도착
	visited[s] = 0;
	q.push(std::make_pair(0, s));
	while (!q.empty())
	{
		noww = -q.top().first;
		nows = q.top().second;
		if (nows == e)
			break;
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (MAP[nows][i]>=0 && visited[i] > visited[nows] + MAP[nows][i])
			{
				visited[i] = visited[nows] + MAP[nows][i];
				q.push(std::make_pair(-visited[i], i));
			}
		}
	}
	std::cout << visited[e] << '\n';
	return 0;
}