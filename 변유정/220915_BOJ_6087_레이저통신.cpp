#include <iostream>
#include <queue>
using namespace std;

/// 
/// 다익스트라 + bfs
/// 공부해서 다시 풀어보기
/// 참고 : https://velog.io/@nacean/%EB%B0%B1%EC%A4%806087-%EB%A0%88%EC%9D%B4%EC%A0%80-%ED%86%B5%EC%8B%A0-C-%ED%92%80%EC%9D%B4
///

/// 우선순위 큐
/// 참고한 곳에서는 cnt때문에 - 진행 (높은것부터)
struct mirror
{
	int y, x, dir, cnt;
	bool operator < (const mirror& m) const {
		return cnt > m.cnt;
	}
	/// cnt 작은 것 부터
};

char map[101][101];
// used와 거울 cnt 같이 비교해가면서 진행하기
int used[101][101] = { 0, };
int W, H;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
priority_queue <mirror> lazer;
int my, mx;
int ans;

void bfs()
{
	int cy = lazer.top().y;
	int cx = lazer.top().x;
	int cdir = lazer.top().dir;
	int c_cnt = lazer.top().cnt;
	lazer.pop();

	for (int i = 0; i < 4; i++)
	{
		int nc = cy + dy[i];
		int nr = cx + dx[i];
		
		if (nc < 0 || nr < 0 || nc >= H || nr >= W) continue;
		if (map[nc][nr] == '*') continue;

		lazer.push({ nc,nr,i,0 });
		used[nc][nr] = 0;
	}

	while (!lazer.empty())
	{
		int y = lazer.top().y;
		int x = lazer.top().x;
		int dir = lazer.top().dir;
		int cnt = lazer.top().cnt;
		lazer.pop();

		if (used[y][x] < cnt) continue;
		if (y == my && x == mx) continue;

		for (int i = 0; i < 4; i++)
		{
			if (abs(dir - i) == 2) continue;
			int ny = y + dy[i];
			int nx = x + dx[i];
			int ncnt;
			if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
			if (map[ny][nx] == '*') continue;

			if (abs(i - dir) == 1 || abs(i - dir) == 3) ncnt = cnt + 1;
			else if (i == dir) ncnt = cnt;

			if (used[ny][nx] >= ncnt)
			{
				used[ny][nx] = ncnt;
				lazer.push({ ny,nx,i, ncnt });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> W >> H;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			cin >> map[y][x];
			used[y][x] = 1e9;
			if (map[y][x] == 'C' && lazer.empty())
			{
				lazer.push({ y,x,-10,0 });
				used[y][x] = 0;
			}
			else if (map[y][x] == 'C' && !lazer.empty())
			{
				my = y;
				mx = x;
			}
		}
	}
	bfs();
	cout << used[my][mx];
}