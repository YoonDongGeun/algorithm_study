#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

// 시간이 걸림. 왜 걸리는지 이유 찾아야함.
// 조건 주기전에 자를 위치 찾기

int N;
int start, finish;
int used[10001] = { 0, };
queue <int> pw;

bool prime(int num)
{
	int num_p = (int)sqrt(num);
	for (int i = 3; i <= num_p; i++)
		if (num % i == 0) return false;
	return true;
}

int password(int num, int i, int j)
{
	int a[4] = { 0, };
	int temp = num;
	for (int k = 0; k <4; k++)
	{
		a[k] = temp % 10;
		temp = (temp - a[k]) / 10;
	}
	a[i] = j;
	return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

void bfs()
{
	while (!pw.empty())
	{
		int now = pw.front();
		if (now == finish) break;
		pw.pop();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == 0 && j % 2 == 0) continue;
				if (i == 3 && j == 0) continue;

				int next = password(now, i, j);
				if (used[next] != 0) continue;
				if (prime(next) == false) continue;
				used[next] = used[now] + 1;
				if (next == finish) break;
				pw.push(next);
			}
		}
		if (used[finish] != 0) break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> finish;
		if (start == finish)
		{
			cout << 0 << "\n";
		}
		else
		{
			used[start] = 1;
			pw.push(start);
			bfs();
			if (used[finish] == 0) cout << "Impossible" << "\n";
			else cout << used[finish] - 1 << "\n";
		}
		memset(used, 0, sizeof(used));
		while (!pw.empty()) pw.pop();
	}
}


// 다른 사람의 코드
//
//#include <stdio.h>
//#include <queue>
//using namespace std;
//
//int T, isprime[10000] = { 0 };
//
//int digit(int a[]) { return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0]; }
//
//void prime()
//{
//	int i, j;
//
//	for (i = 2; i <= 100; i++)
//	{
//		if (isprime[i] == 1) continue;
//		for (j = 2 * i; j <= 9999; j += i)
//		{
//			isprime[j] = 1;
//		}
//	}
//}
//
//int BFS(int x, int y)
//{
//	queue<int> q, seq;
//	int f, i, j, tmp, cnt, k, a[4] = { 0 }, visit[10000] = { 0 };
//	q.push(x);
//	visit[x] = 1;
//	seq.push(0);
//
//	while (!q.empty())
//	{
//		f = q.front();
//		cnt = seq.front();
//		q.pop();
//		seq.pop();
//		if (f == y) return cnt;
//		tmp = f;
//		for (i = 0; i < 4; i++)
//		{
//			a[i] = tmp % 10;
//			tmp = (tmp - a[i]) / 10;
//		}
//
//		for (i = 0; i < 4; i++)
//		{
//			k = a[i];
//			for (j = 0; j < 10; j++)
//			{
//				a[i] = j;
//				tmp = digit(a);
//				if (tmp < 1000) continue;
//				if (isprime[tmp] == 0 && visit[tmp] == 0)
//				{
//					q.push(tmp);
//					seq.push(cnt + 1);
//					visit[tmp] = 1;
//				}
//			}
//			a[i] = k;
//		}
//	}
//
//	return -1;
//}
//
//int main()
//{
//	int i, j, x, y, k;
//	scanf("%d", &T);
//	prime();
//	for (i = 0; i < T; i++)
//	{
//		scanf("%d %d", &x, &y);
//		k = BFS(x, y);
//		if (k == -1) printf("impossible\n");
//		else printf("%d\n", k);
//	}
//
//	return 0;
//}