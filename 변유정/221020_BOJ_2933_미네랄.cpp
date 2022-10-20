#include <iostream>
#include <queue>
using namespace std;

//구현 단계 (큐로만 구현)
// 1. 미네랄 개수('x') 세기
// 2. 창영, 상근 순서대로 막대기 던지는 높이 입력 받고 깨기 (broken)
// 2-1. 창영 순서 - 0포함 짝수일때. 'x' 만나면 '.'으로 바꾸고 멈춤
// 2-2. 상근 순서 - 홀수 일때, 'x' 만나면 '.' 으로 바꾸고 멈춤

// 3. 미네랄 바닥까지 내리기 (move)
// 3-1. 바닥부터 탐색 - 만나면 큐 q에 넣고 '.'으로 바꿔주고 돌리기
// 3-2. 서로 이어져 있는 미네랄 다 찾고 최대 내려갈 수 있는 높이 찾기
// 3-3. 높이만큼 위치 바꿔주고 'x'로 값 바꿔주기
// 3-4. 탐색한 미네랄 개수가 총 미네랄 개수와 같으면 탐색 멈춤

// 4. N번 만큼 실행하고 cave 배열 출력

// 벡터로만 구현해보기

int R, C, N;
int mineral = 0;
char cave[102][102];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0, 0};

void broken(int h, int dir)
{
	if (dir == 0)
	{
		int st = 0;
		while (st < C)
		{
			if (cave[R - h][st] == 'x')
			{
				cave[R - h][st] = '.';
				mineral--;
				break;
			}
			st++;
		}
	}

	else
	{
		int st = C;
		while (st--)
		{
			if (cave[R - h][st] == 'x')
			{
				cave[R - h][st] = '.';
				mineral--;
				break;
			}
		}
	}
}

void move()
{
	int used[102][102] = { 0, };
	int temp = 0;
	queue <pair<int, int>> q;
	for (int y = R - 1; y >= 0; y--)
	{
		for (int x = 0; x < C; x++)
		{
			if (temp == mineral) break;
			if (used[y][x] == 1 || cave[y][x] == '.') continue;
			used[y][x] = 1;
			q.push({ y,x });
			temp++;
			queue <pair<int, int>> now;
			while (!q.empty())
			{
				int ny = q.front().first;
				int nx = q.front().second;
				q.pop();
				cave[ny][nx] = '.';
				now.push({ ny,nx });
				for (int i = 0; i < 4; i++)
				{
					int nny = ny + dy[i];
					int nnx = nx + dx[i];
					if (nny < 0 || nny >= R || nnx < 0 || nnx >= C) continue;
					if (used[nny][nnx] == 1 || cave[nny][nnx] == '.') continue;
					used[nny][nnx] = 1;
					q.push({ nny,nnx });
					temp++;
				}
			}
			int k = now.size();
			int mxx = 1e9;
			while (k--)
			{
				int ny = now.front().first;
				int nx = now.front().second;
				now.pop();
				int nny = ny;
				while (true)
				{
					if (cave[nny + 1][nx] == 'x' || nny + 1 >= R)
					{
						mxx = min(mxx, nny - ny);
						break;
					}
					nny++;
				}
				now.push({ ny,nx });
			}
			while (!now.empty())
			{
				int ny = now.front().first;
				int nx = now.front().second;
				now.pop();
				used[ny][nx] = 0;
				ny += mxx;
				used[ny][nx] = 1;
				cave[ny][nx] = 'x';
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> cave[i][j];
			if (cave[i][j] == 'x') mineral++;
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int height;
		cin >> height;
		broken(height, i % 2);
		move();
	}

	for (int y = 0; y < R; y++)
		cout << cave[y] << '\n';
}