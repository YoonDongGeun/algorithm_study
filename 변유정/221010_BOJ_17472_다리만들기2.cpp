#include <iostream>
#include <queue>
using namespace std;

// 하나로 응용문제
// BFS + MST

// 구현 단계
// 1. 섬에 숫자 새기기 (count_island)
// 
// 2. 섬 사이 경로 만들기 (make_bridge)
// 2-1. 만약 다리 길이가 1이거나, 지도를 벗어나거나, 같은 숫자를 만나게 되면 그만
// 2-2. 이걸 방향마다 각 섬의 위치마다 찾아보기
// 
// 3. 다리 선정해서 섬 연결해주기 (connect)
// 3-1. 하나로 문제 풀이와 같음
// 3-2. 섬 개수 - 1 만큼 반복
// 3-3. 다 연결해주면 다리 길이 되돌려주기

// 4-1. 다리 길이가 만약 10000 이상이면 -1 (섬사이를 모두 연결 못해준다는 것)
// 4-2. 그 외에는 다리 길이 모두 출력

int N, M, map[11][11];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool visited[7];
int bridge[7][7];
int cnt_island = 1;

int connect()
{
	int cnt = cnt_island - 1;
	int result = 0;
	int island[7];
	for (int i = 1; i <= cnt_island; i++) island[i] = 10000;
	visited[1] = 1;
	int idx = 1;

	while (cnt--)
	{
		int min_value = 10000;
		int min_idx = 1;
		for (int i = 1; i <= cnt_island; i++)
		{
			if (!visited[i])
			{
				island[i] = min(island[i], bridge[idx][i]);
				if (island[i] < min_value)
				{
					min_value = island[i];
					min_idx = i;
				}
			}
		}
		idx = min_idx;
		visited[min_idx] = 1;
		result += min_value;
	}
	return result;
}

void make_bridge(int ny,int nx,int num,int dir)
{
	int length = 0;
	while (true)
	{
		int ky = ny + dy[dir];
		int kx = nx + dx[dir];
		if (ky < 0 || kx < 0 || ky >= N || kx >= M) break;
		if (map[ky][kx] == num) break;
		else if (map[ky][kx] == 0)
		{
			ny = ky;
			nx = kx;
			length++;
		}
		else
		{
			int temp = map[ky][kx];
			if (length == 1) break;
			bridge[num][temp] = min(bridge[num][temp], length);
			bridge[temp][num] = bridge[num][temp];
			break;
		}
	}
}

void count_island()
{
	bool used[11][11] = { 0, };
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (used[y][x] || map[y][x] == 0) continue;
			queue <pair<int, int>> q;
			used[y][x] = 1;
			map[y][x] = cnt_island;
			q.push({ y,x });
			while (!q.empty())
			{
				int yy = q.front().first;
				int xx = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int ny = yy + dy[i];
					int nx = xx + dx[i];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if (map[ny][nx] == 0 || used[ny][nx]) continue;
					map[ny][nx] = cnt_island;
					used[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			cnt_island++;
		}
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
			cin >> map[y][x];
	count_island();
	cnt_island--;
	for (int i = 1; i <= cnt_island; i++)
		for (int j = 1; j <= cnt_island; j++)
			bridge[i][j] = 10000;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (map[y][x] != 0)
				for (int i = 0; i < 4; i++)
					make_bridge(y, x, map[y][x], i);
	int temp = connect();
	if (temp >= 10000) cout << -1;
	else cout << temp;
}