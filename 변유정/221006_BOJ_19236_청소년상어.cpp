#include <iostream>
using namespace std;

// 구현 + 시뮬레이션
// 구현 단계
// 1. (0,0) 상어 두기
// 2. 물고기 이동 (번호 순서대로 하는 것이 매우 중요!)
// 2-1. 만약 해당 번호의 물고기가 이동을 한번 했다면 표시해주기 (중복 움직임 가능있음)
// 2-2. 해당 번호의 물고기가 갈 수 있는 곳만 가기
// * 갈 수 없는 곳 : 공간 벗어난 곳, 상어 있는 곳

// 3. 그다음 상어 이동
// 3-1. 상어가 먹을 수 있는 물고기 최대값 찾아야 하기 때문에, 배열 되돌려줘야 함
//  ** temp 배열이 그 역할
// 3-2. 상어가 갈 수 없는 곳 : 공간 벗어난 곳, 먹이 먹을 곳이 없는 곳
// 3-3. 상어 갈 수 있는 곳 가고 ans 계속 갱신해주기

int fish[4][4][2]; // fish[][][0] - 물고기 번호, fish[][][1] - 물고기 방향
int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int dx[9] = {0,0,-1,-1,-1,0,1,1,1};
int s_dir,ans = 0;

// 2단계
void moving(int sy,int sx)
{
	for (int i = 1; i <= 16; i++)
	{ 
		int flag = 0;
		for (int y = 0; y < 4; y++)
		{
			if (flag == 1) continue;
			for (int x = 0; x < 4; x++)
			{
				if (flag == 1) continue;
				if (fish[y][x][0] == i)
				{
					int dirr = fish[y][x][1];
					while (true)
					{
						if (dirr == 9) dirr = 1;
						int ny = y + dy[dirr];
						int nx = x + dx[dirr];
						if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4)
						{
							dirr++;
							continue;
						}
						if (ny == sy && nx == sx)
						{
							dirr++;
							continue;
						}
						int temp1 = fish[y][x][0];
						int temp2 = dirr;
						fish[y][x][0] = fish[ny][nx][0];
						fish[y][x][1] = fish[ny][nx][1];
						fish[ny][nx][0] = temp1;
						fish[ny][nx][1] = temp2;
						flag = 1;
						break;
					}
				}
			}
		}
	}
}

// 3단계
void shark(int sy,int sx,int sdir,int result)
{
	if (ans < result) ans = result;
	moving(sy, sx);
	int temp[4][4][2];
	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			for (int i = 0; i < 2; i++)
				temp[y][x][i] = fish[y][x][i];

	for (int i = 1; i <= 3; i++)
	{
		int ny = sy + i * dy[sdir];
		int nx = sx + i * dx[sdir];
		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
		if (fish[ny][nx][0] == 0) continue;
		int ndir = fish[ny][nx][1];
		int plus = fish[ny][nx][0];
		fish[ny][nx][1] = 0;
		fish[ny][nx][0] = 0;
		shark(ny, nx, ndir, result + plus);

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				for (int i = 0; i < 2; i++)
					fish[y][x][i] = temp[y][x][i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
			cin >> fish[y][x][0] >> fish[y][x][1];

	int k = fish[0][0][0];
	ans += k;
	fish[0][0][0] = 0;
	s_dir = fish[0][0][1];
	fish[0][0][1] = 0;
	shark(0, 0, s_dir, k);
	cout << ans;
}