#include <iostream>
#include <string>
using namespace std;

/// 
/// 육각형 중 최대 접하는 점이 3개라서 최대 색 종류가 3개
/// 
/// DFS 사용 안하고 그냥 하려 했으나 자꾸 오류떠서 사용함
/// 
/// 색칠 가능한 칸이 이어져 있다는 것은 적어도 2개의 색이 필요하다는 의미
/// 그래서 사용표시 배열 (used)에 1,0을 넣어서 색칠해줌
/// 그러다가 색칠 가능한 한 점에서 0,1 이 모두 있으면 색 3개가 필요함
/// 

int N, ans=0,used[51][51];
char hexagon[51][51];
int dy[6] = { -1,-1,0,1,1,0 };
int dx[6] = { 0,1,1,0,-1,-1 };
int ans = 0;

void paint(int y, int x,int color)
{
	used[y][x] = color;
	ans = max(ans, 1);
	for (int k = 0; k < 6; k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (hexagon[ny][nx] == 'X')
		{
			if (used[ny][nx] == -1)
			{
				paint(ny, nx, 1 - color);
				ans = max(ans, 2);
			}

			else if (used[ny][nx] == color)
			{
				ans = 3;
				cout << 3;
				exit(0);
			}
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> hexagon[y][x];

	memset(used, -1, sizeof(used));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (hexagon[y][x] == 'X' && used[y][x] == -1)
				paint(y, x,0);
		}
	}
	cout << ans;
	return 0;
}

// 기존 원래 시도했던 내 코드

//#include <iostream>
//using namespace std;
//
//int N;
//char hexagon[51][51];
//int dy[6] = { -1,-1,0,1,1,0 };
//int dx[6] = { 0,1,1,0,-1,-1 };
//int ans = 0;
//
//void paint(int y, int x)
//{
//	ans = max(ans, 1);
//	bool color[6] = { 0, };
//	for (int k = 0; k < 6; k++)
//	{
//		int ny = y + dy[k];
//		int nx = x + dx[k];
//		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
//		if (hexagon[ny][nx] == 'X') color[k] = 1;
//
//	}
//	for (int i = 0; i < 6; i++)
//	{
//		if (color[i])
//		{
//			if (color[(i + 1) % 6])
//			{
//				cout << 3 << "\n";
//				exit(0);
//			}
//			else ans = max(ans, 2);
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//	for (int y = 0; y < N; y++)
//		for (int x = 0; x < N; x++)
//			cin >> hexagon[y][x];
//
//	for (int y = 0; y < N; y++)
//	{
//		for (int x = 0; x < N; x++)
//		{
//			if (hexagon[y][x] == 'X')
//				paint(y, x);
//		}
//	}
//	cout << ans << "\n";
//	return 0;
//}