#include <iostream>
#include <vector>
using namespace std;

// 구현 + 시뮬레이션

// 구현 과정
// 1. get_fish - 가장 근처인 물고기 잡기
// 2. moving - 물고기 이동 (물고기의 이동 전과 이동 후가 겹칠수 있기 때문에 나눠주기)
// 2-1. 이동했을 때, 이미 물고기가 존재한다면 크기 큰거만 남기게 하기

// 3. 시간 초과의 문제
// ***속도(1초당 이동거리) 가 낚시하는 곳 크기를 벗어나는 경우가 있다 - 이걸 줄여주는 것이 포인트

struct Data
{
	int s, d, z;
};
int ans = 0;
int R, C, M;
vector <Data> fish[101][101];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,1,-1 };

void get_fish(int num)
{
	for (int y = 1; y <= R; y++)
	{
		if (!fish[y][num].empty() > 0)
		{
			ans += fish[y][num][0].z;
			fish[y][num].pop_back();
			break;
		}
	}
}

void moving()
{
	vector <Data> another[101][101];
	for (int y = 1; y <= R; y++)
	{
		for (int x = 1; x <= C; x++)
		{
			if (!fish[y][x].empty())
			{
				Data temp = fish[y][x][0];
				fish[y][x].pop_back();

				int ns = temp.s;
				int cy = y;
				int cx = x;

				while (ns--)
				{
					int ny = cy + dy[temp.d];
					int nx = cx + dx[temp.d];
					if (ny < 1 || nx < 1 || ny > R || nx > C)
					{
						if (temp.d % 2 == 1) temp.d++;
						else temp.d--;
					}
					cy += dy[temp.d];
					cx += dx[temp.d];
				}

				if (!another[cy][cx].empty())
				{
					if (another[cy][cx][0].z < temp.z)
					{
						another[cy][cx].pop_back();
						another[cy][cx].push_back(temp);
					}
				}
				else another[cy][cx].push_back(temp);
			}
		}
	}
	for (int y = 1; y <= R; y++)
		for (int x = 1; x <= C; x++)
			fish[y][x] = another[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		if (d <= 2) s %= ((R - 1) * 2);
		else s %= ((C - 1) * 2);
		fish[r][c].push_back({s,d,z});
	}
	if (M == 0) cout << ans;
	else
	{
		for (int i = 1; i <= C; i++)
		{
			get_fish(i);
			moving();
		}
		cout << ans;
	}
}