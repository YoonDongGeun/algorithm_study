#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, T;
vector <int> vect[13] = { {}, {0,1,3},{0,1,2}, {1,2,3}, {0,2,3}
,{0,1},{1,2},{2,3},{0,3},{0,3},{0,1},{1,2},{2,3}
};

int diry[4] = { 0,-1,0,1 }, dirx[4] = { 1,0,-1,0 };
int cross[101][101][4];
bool used[101][101][4];
bool ans[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> T;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			for (int i = 0; i < 4; i++)
				cin >> cross[y][x][i];
	queue<pair<int,int>> q;
	q.push({ 0,0});
	used[0][0][0] = 1;
	ans[0][0] = 1;
	int time = 0;
	while (!q.empty())
	{
		int qs = q.size();
		if (time == T) break;
		while (qs--)
		{
			pair <int,int> temp = q.front();
			q.pop();
			int all_dir = cross[temp.first][temp.second][time % 4];
			for (int i = 0; i < vect[all_dir].size(); i++)
			{
				int next_dir = vect[all_dir][i];
				int ny = temp.first + diry[next_dir];
				int nx = temp.second + dirx[next_dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (used[ny][nx][time % 4]) continue;
				used[ny][nx][time % 4] = 1;
				ans[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
		time++;
	}
	int cnt = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (ans[y][x]) cnt++;
	cout << cnt;
}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N, T;
//vector <int> vect[13] = { {},
//	{0,1,3},{1,0,2},{2,1,3},{3,0,2},
//	{0,1},{1,2},{2,3},{3,0},
//	{0,3},{1,0},{2,1},{3,2}
//};;
//int cross[101][101][4];
//int car_y = 0, car_x = 0, diry[4] = { 0,1,0,-1 }, dirx[4] = {1,0,-1,0};
//int used[101][101][4] = {0,};
//
//void dfs(int now, int y, int x)
//{
//	if (now == T) return;
//	int temp = cross[y][x][now % 4];
//	for (int i = 0; i < vect[temp].size(); i++)
//	{
//		int XY = vect[temp][i];
//		int ny = y + diry[XY], nx = x + dirx[XY];
//		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
//		if (used[ny][nx][(now+1)%4] > 0 && used[ny][nx][(now+1) % 4] <= now) continue;
//		used[ny][nx][(now+1)%4] = now + 1;
//		dfs(now + 1, ny, nx);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> T;
//	for (int y = 0; y < N; y++)
//		for (int x = 0; x < N; x++)
//			for (int i = 0; i < 4; i++)
//				cin >> cross[y][x][i];
//	int ans = 0;
//	used[0][0][0] = 1;
//	dfs(0, 0, 0);
//	for (int y = 0; y < N; y++)
//		for (int x = 0; x < N; x++)
//			for (int i = 0; i<4;i++)
//				if (used[y][x][i])
//				{
//					ans++;
//					break;
//				}
//	cout << ans;
//}