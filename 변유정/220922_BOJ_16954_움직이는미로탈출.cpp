#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// BFS (배열로만 풀어보기!!)
// 순서 : 욱제 > 벽
// 벽은 아래로만 움직임
// 욱제는 현재 위치 포함, 총 9가지 방향으로 갈 수 있음

char board[8][8];
int flag = 0;
int dy[9] = { 1, 0,-1, 0, 1, 1,-1,-1,0 };
int dx[9] = { 0, 1, 0,-1, 1,-1, 1,-1,0 };
vector <pair<int, int>> wall;
queue <pair<int, int>> wookjae;
bool used[8][8];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			cin >> board[y][x];
			if (board[y][x] == '#')
				wall.push_back({ y,x });
		}
	}
	wookjae.push({ 7,0 });

	while (!wookjae.empty()) // 욱제가 모두 벽에 압살당했을 때는 갈 곳 없음
	{
		int cnt = wookjae.size(); // 욱제가 있는 자리 개수
		memset(used, 0, sizeof(used));
		while (cnt--)
		{
			int y = wookjae.front().first;
			int x = wookjae.front().second;
			wookjae.pop();

			if (y == 0 && x == 7)
			{
				flag = 1;
				break;
			}

			if (board[y][x] == '#') continue; // 욱제가 압살 당한 흔적이 큐에 남아있을 때 무시

			for (int i = 0; i < 9; i++) // 욱제가 갈수 있는 방향들로 탐색
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
				if (used[ny][nx] || board[ny][nx] == '#') continue;
				used[ny][nx] = 1;
				wookjae.push({ ny,nx });
			}
		}

		for (int y = 0; y < 8; y++) // 벽 이동하기 위해 초기화
			for (int x = 0; x < 8; x++)
				board[y][x] = '.';

		for (int i = 0; i < wall.size(); i++)
		{
			int y = wall[i].first;
			int x = wall[i].second;


			if (y == 7) // 만약 벽이 맨아래로 내려왔을 때
			{
				wall.erase(wall.begin() + i); // 벽 저장소에서 제외시키기
				i--;
				continue;
			}
			board[y + 1][x] = '#'; // 벽 이동
			wall[i].first++;
		}
		if (flag == 1) break; // 만약 도착지점 (0,7) 도착했다면 그만 돌고 멈추기
	}
	cout << flag;
}