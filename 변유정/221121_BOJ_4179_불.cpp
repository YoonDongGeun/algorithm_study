#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// 알고리즘 : BFS
// 지훈이 움직일 수 있는 범위, 불이 갈 수 있는 범위 나눠줘서 진행
// 1-1. 만약 지훈이 있는 곳이 불로 바뀌었다면 진행하지 않기
// 1-2. 지훈이 미로 밖을 벗어났으면 멈추기

// 2-1. 불이 지나갈 자리가 벽이거나 이미 불이 지나간 흔적이 있으면 무시
// 2-2. 만약 지훈이 빠져나갔다면 멈추기

int N, M;
char maze[1001][1001];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue <pair<int, int>> jh;
queue <pair<int, int>> fire;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'F') fire.push({ i,j });
			if (maze[i][j] == 'J') jh.push({i,j});
		}
	int time = 0;
	bool flag = 0;
	
	while (!jh.empty())
	{
		time++;
		if (flag) break;
		int j_len = jh.size();
		while (j_len--)
		{
			pair<int, int> temp_jh = jh.front();
			jh.pop();
			for (int i = 0; i < 4; i++)
			{
				if (maze[temp_jh.first][temp_jh.second] == 'F') continue;
				pair<int, int> next_jh = { temp_jh.first + dy[i], temp_jh.second + dx[i] };
				if (next_jh.first < 0 || next_jh.first >= N || next_jh.second < 0 || next_jh.second >= M)
				{
					flag = 1;
					break;
				}
				if (maze[next_jh.first][next_jh.second] == '.')
				{
					maze[next_jh.first][next_jh.second] = 'J';
					jh.push(next_jh);
				}
			}
		}
		if (flag) break;
		if (fire.empty()) continue;
		int f_len = fire.size();
		while (f_len--)
		{
			pair<int, int> temp_f = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++)
			{
				pair<int, int> next_f = { temp_f.first + dy[i], temp_f.second + dx[i] };
				if (next_f.first < 0 || next_f.first >= N || next_f.second < 0 || next_f.second >= M) continue;
				if (maze[next_f.first][next_f.second] == '#' || maze[next_f.first][next_f.second] == 'F') continue;
				maze[next_f.first][next_f.second] = 'F';
				fire.push(next_f);
			}
		}
	}
	if (flag) cout << time;
	else cout << "IMPOSSIBLE";
}