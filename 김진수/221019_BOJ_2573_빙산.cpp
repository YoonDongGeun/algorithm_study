#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string.h>
using namespace std;
// Sam2형 채고
// [A] 전역 변수 선언
int N, M;
int sea[300][300];
bool visited[300][300];

// [B] delta 방향 설정
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

// [C] 빙산이 녹는 melt 함수 설정
void melt()
{	// 녹는 빙산의 좌표와 양을 melting[n]에 tuple로 저장
	vector<tuple<int, int, int>> melting;
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 1; j < M-1; j++)
		{
			if (sea[i][j] != 0)
			{
				int cnt = 0;
				for (int dr = 0; dr < 4; dr++)
				{
					int ni = i + di[dr];
					int nj = j + dj[dr];
					if (sea[ni][nj] == 0)
					{
						cnt++;
					}
				}
				if (cnt > 0)
				{
					melting.push_back(make_tuple(i, j, cnt));
				}
			}
		}
	}
	// melting에 저장한 빙산을 녹인다.
	for (int n = 0; n < melting.size(); n++)
	{
		int a, b, cnt, melted;
		a = get<0>(melting[n]);
		b = get<1>(melting[n]);
		cnt = get<2>(melting[n]);
		melted = sea[a][b] - cnt;
		
		if (melted < 0)
		{
			sea[a][b] = 0;
		}
		else
		{
			sea[a][b] = melted;
		}
	}
}

// [D] BFS 함수 설정
int bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visited[i][j] = true;

	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		
		for (int dr = 0; dr < 4; dr++)
		{
			int ni = i + di[dr];
			int nj = j + dj[dr];

			if (sea[i][j] && visited[ni][nj] == false)
			{
				q.push(make_pair(ni, nj));
				visited[ni][nj] = true;
			}
		}

	}
	return 1;
}


// [1] 입력값 설정
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> sea[i][j];
		}
	}
	// [2] 매년 빙산이 녹는다.
	int time = 0;
	while (true)
	{
		melt();
		time++;
		// [2-1] BFS 탐색으로 녹은 후 빙산이 몇 덩어리인지 센다.
		int iceberg = 0;
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (sea[i][j] && visited[i][j] == false)
				{
					iceberg += bfs(i, j);
				}
			}
		}
		// [2-2] 1덩어리라면 continue, 아니라면 출력
		if (iceberg == 1)
		{
			memset(visited, false, sizeof(visited));
			continue;
		}
		else if (iceberg == 0)
		{
			cout << iceberg << '\n';
			break;
		}
		else
		{
			cout << time << '\n';
			break;
		}
	}
	return 0;
}