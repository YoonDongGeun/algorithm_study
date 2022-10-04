#include <iostream>
#include <queue>
using namespace std;

// 문제 구현 단계
// 
// 1. ord - 승객 태울 순서 정하기
// 승객 태울 순서 조건 : 1. 거리 2. 행 작은 순 3. 열 작은 순
// 2. moving - 거리 구하기 (bfs)
// 3. 한명씩 태우다가 연료 양이 이동거리보다 부족하게 되면 flag 표시 & 멈춤
// 4. flag 표시 : 승객을 다 못태웠다 - -1 출력
// 5. 그외 : 연료 사용량 출력
// 
// 헷갈리지 말기 : 연료 최대 남는 양이 아니라 순서에 따라 진행 후, 연료 남는 양 (재귀로 최대값 찾는 것 아님!)
// 
// *연산자 오버로딩 이용해서 ord 시간 줄이기

int N, M, fuel, map[21][21], ty, tx;
bool flag = 0;
int dest[404][4];
int used[404] = { 0, };
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int moving(int sy, int sx, int ey, int ex)
{
	queue <pair<int, int>> q;
	int visited[21][21] = { 0, };
	visited[sy][sx] = 1;
	q.push({ sy,sx });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == ey && x == ex) break;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > N || nx > N || visited[ny][nx]) continue;
			if (map[ny][nx] == 1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	if (visited[ey][ex] == 0) return 2e9;
	else return visited[ey][ex] - 1;
}

void ord()
{
	int cnt = 0;
	while (cnt < M)
	{
		int mxx = 1e9;
		int idx = 0;
		for (int i = 0; i < M; i++)
		{
			// 시간 줄일 포인트
			if (used[i]) continue;
			int temp = moving(ty, tx, dest[i][0], dest[i][1]);
			if (mxx > temp)
			{
				mxx = temp;
				idx = i;
			}
			else if (mxx == temp)
			{
				if (dest[idx][0] > dest[i][0])
				{
					mxx = temp;
					idx = i;
				}
				else if (dest[idx][0] == dest[i][0])
				{
					if (dest[idx][1] > dest[i][1])
					{
						mxx = temp;
						idx = i;
					}
				}
			}
		}
		fuel -= mxx;
		int temp1 = moving(dest[idx][0], dest[idx][1], dest[idx][2], dest[idx][3]);
		if (fuel < 0 || fuel - temp1 < 0)
		{
			flag = 1;
			break;
		}
		fuel += temp1;
		ty = dest[idx][2];
		tx = dest[idx][3];
		used[idx] = 1;
		cnt++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> fuel;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> map[y][x];
	cin >> ty >> tx;
	for (int i = 0; i < M; i++)
		cin >> dest[i][0] >> dest[i][1] >> dest[i][2] >> dest[i][3];

	ord();
	if (flag == 1) cout << -1;
	else cout << fuel;
}