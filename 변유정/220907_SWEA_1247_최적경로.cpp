#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/// <summary>
/// 간단한 문제 재귀 + 백트래킹(?)
/// 중간에 dist가 임시 ans보다 크면 잘라야함

int T, N;
vector <pair<int, int>> v;
int used[10] = { 0, };
int hy, hx, cy, cx;
int ans;

void dfs(int sy, int sx,int dist, int cnt)
{
	if (ans < dist) return;
	if (cnt == N)
	{
		if (ans > dist + abs(sy - hy) + abs(sx - hx)) ans = dist + abs(sy - hy) + abs(sx - hx);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (used[i] == 1) continue;
		used[i] = 1;
		int ny = v[i].first;
		int nx = v[i].second;
		dfs(ny, nx, dist + abs(sy - ny) + abs(sx - nx), cnt + 1);
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		cin >> cy >> cx >> hy >> hx;
		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		ans = 1e9;
		memset(used, 0, sizeof(used));
		dfs(cy, cx, 0, 0);
		cout << "#" << tc << " " << ans << "\n";
		v.clear();
	}
}