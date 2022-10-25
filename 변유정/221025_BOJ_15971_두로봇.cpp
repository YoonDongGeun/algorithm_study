#include <iostream>
#include <vector>
using namespace std;

// DFS

// 그냥 배열로 풀게되면 시간초과 - 벡터 활용하기
// 최댓값 나오게 되면 기존 최댓값 갱신 & length에 더해주기

// 방향이 없기 때문에, 벡터 양방향으로 설정해주기
struct Data
{
	int y, length;
};

int N, robot1, robot2, ans;
vector <Data> v[100001];
bool used[100001] = { 0, };

void connect(int now,int length, int minu)
{
	if (now == robot2)
	{
		if (ans > length) ans = length;
		return;
	}

	for (int i = 0; i < v[now].size(); i++)
	{
		int next_d = v[now][i].y;
		if (used[next_d]) continue;
		used[next_d] = 1;
		if (minu < v[now][i].length) connect(next_d, length + minu, v[now][i].length);
		else connect(next_d, length + v[now][i].length, minu);
		used[next_d] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> robot1 >> robot2;
	for (int i = 0; i < N-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	ans = 1e9;
	used[robot1] = 1;
	connect(robot1, 0, 0);
	cout << ans;
}