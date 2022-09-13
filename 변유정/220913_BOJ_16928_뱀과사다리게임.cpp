#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/// 문제 : bfs의 경우, 반복문 안에서 더해주는 경우가 많으니
/// 범위 설정을 똑바로 해줘야함 (안그럼 out of bounds)
/// 그리고 순서도 바르게 세우기 (next 부분)

int N, M;
int used[101] = { 0, };
vector <pair<int, int>> ladder;
vector <pair<int, int>> snake;
queue <int> now;

void bfs()
{
	while (!now.empty())
	{
		int n = now.front();
		now.pop();
		if (n == 100) break;
		for (int i = 1; i <= 6; i++)
		{
			int next = n + i;
			// 100을 넘어가지 않게 next 범위 설정 해주기
			if (next > 100) continue;
			// 뱀을 피하지 않고 그냥 넣은 이유 : 
			// 뱀을 사용해서 단거리 나올 수 있다고 판단
			for (int k = 0; k < M; k++)
				if (snake[k].first == next) next = snake[k].second;
			for (int k = 0; k < N; k++)
				if (ladder[k].first == next) next = ladder[k].second;
			
			// 사다리, 뱀에서 next 바뀌기 때문에 이때 next 확인해줘야함
			if (used[next] != 0) continue;
			used[next] = used[n] + 1;
			now.push(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder.push_back({ a,b });
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		snake.push_back({ a,b });
	}
	used[1] = 1;
	now.push(1);
	bfs();
	// 1을 더한 상태에서 시작했기 때문에 1 다시 빼주기
	cout << used[100]-1;
	return 0;
}

/// 그냥 사다리랑 뱀을 합치면 빠르고 짧은 코드 될듯
// 합친 코드

//int los[101];
//int d[101];
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < n; ++i)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		los[n1] = n2;
//	}
//	for (int i = 0; i < m; ++i)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		los[n1] = n2;
//	}
//
//	queue<int> q;
//	memset(d, -1, sizeof(d));
//	q.push(1);
//	d[1] = 0;
//	while (!q.empty())
//	{
//		int x = q.front();
//		q.pop();
//		for (int i = 1; i <= 6; ++i)
//		{
//			int nx = x + i;
//			if (nx > 100) continue;
//
//			// ladder or snake라면 이동해야 한다.
//			if (los[nx] != 0) {
//				nx = los[nx];
//			}
//			if (d[nx] == -1) {
//				d[nx] = d[x] + 1;
//				q.push(nx);
//			}
//		}
//	}
//	cout << d[100] << "\n";
//	return 0;
//}
// 출처 : https://100100e.tistory.com/194