#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

// BFS + 큐 2번 해주는 문제

int N;

// 적록색약인 사람, 아닌 사람으로 나눠서 생각하기
char grid_c[101][101];
char grid_nc[101][101];
// pop해서 어차피 비니까 다시 사용
queue <pair<int,int>> color;
int C = 0, NC = 0;
int used[101][101] = { 0, };
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void bfs()
{
	// 적록색약이 아닌 사람이 보는 그림
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (used[y][x] == 1) continue;
			else
			{
				color.push({ y,x });
				used[y][x] = 1;
				while (!color.empty())
				{
					int y = color.front().first;
					int x = color.front().second;
					color.pop();
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
						if (grid_c[y][x] != grid_c[ny][nx]) continue;
						if (used[ny][nx] != 0) continue;
						used[ny][nx] = 1;
						color.push({ ny,nx });
					}
				}
				// 구역하나 끝날때마다 더해주기
				C++;
			}
	 	}
	}
	// used 재사용으로 초기화
	memset(used, 0, sizeof(used));
	// 적록색약인 사람이 보는 그림
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (used[y][x] == 1) continue;
			else
			{
				color.push({ y,x });
				used[y][x] = 1;
				while (!color.empty())
				{
					int y = color.front().first;
					int x = color.front().second;
					color.pop();
					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
						if (grid_nc[y][x] != grid_nc[ny][nx]) continue;
						if (used[ny][nx] != 0) continue;
						used[ny][nx] = 1;
						color.push({ ny,nx });
					}
				}
				NC++;
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
	{
		string temp;
		cin >> temp;
		for (int x = 0; x < N; x++)
		{
			// 적록색약 X 저장
			grid_c[y][x] = temp[x];
			// 적록색약 O 그냥 저장
			if (temp[x] == 'R' || temp[x] == 'G') grid_nc[y][x] = 'R';
			else grid_nc[y][x] = 'B';
		}
	}
	bfs();
	cout << C << " " << NC;
}

// DFS로도 풀수 있다
//#include <iostream>
//#include<cstring>
//using namespace std;
//
//char a[101][101];
//
//int ch[101][101];
//
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { -1,1,0,0 };
//
//int n;
//
//void DFS(int x, int y)
//{
//	ch[x][y] = true;
//	for (int i = 0; i < 4; i++)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
//		if (ch[nx][ny] == 0 && a[x][y] == a[nx][ny])
//		{
//			DFS(nx, ny);
//		}
//	}
//}
//
//int main()
//{
//	int cnt = 0;
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ch[i][j] == 0)
//			{
//				DFS(i, j);
//				cnt++;
//			}
//		}
//	}
//
//	cout << cnt << " ";
//	memset(ch, 0, sizeof(ch));
//	cnt = 0;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] == 'G')
//				a[i][j] = 'R';
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (ch[i][j] == 0)
//			{
//				DFS(i, j);
//				cnt++;
//			}
//		}
//	}
//	cout << cnt << endl;
//}