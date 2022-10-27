#include <iostream>
#include <algorithm>
using namespace std;

// 알고리즘 분류 : DP
// 배열 DP[N 구간 개수][K 시간]

// Bool operator 응용하면 더 빨리 풀수 있음

int N, K;
int time[101][2];
int money[101][2];
// 0 - 도보, 1 - 자전거
int DP[101][100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++)
			cin >> time[i][j] >> money[i][j];
	// 구간 0 일때까지 최대 시간은 정해져 있기 때문에 미리 정해주기
	DP[0][time[0][0]] = max(DP[0][time[0][0]], money[0][0]);
	DP[0][time[0][1]] = max(DP[0][time[0][1]], money[0][1]);

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			// DP 배열 안에 숫자가 있을 때만 진행해주기
			if (DP[i - 1][j] > 0)
			{
				// 시간을 더해도 초과가 되지 않으면 값 비교 후 DP 배열에 집어넣기 (도보 , 자전거 따로 값 비교)
				if (j + time[i][0] <= K) DP[i][j + time[i][0]] = max(DP[i][j + time[i][0]], DP[i - 1][j] + money[i][0]);
				if (j + time[i][1] <= K) DP[i][j + time[i][1]] = max(DP[i][j + time[i][1]], DP[i - 1][j] + money[i][1]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= K; i++)
		ans = max(ans, DP[N-1][i]);
	cout << ans;
}

// 밑에는 완전탐색으로 진행한 코드 (서브태스크 1만 진행 가능함)

//void trip(int now, int left, long long don)
//{
//	if (now == N)
//	{
//		if (ans < don) ans = don;
//		return;
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		if (left - time[now][i] < 0) continue;
//		trip(now + 1, left - time[now][i], don + money[now][i]);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> K;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < 2; j++)
//			cin >> time[i][j] >> money[i][j];
//	ans = 0;
//	trip(0, K, 0);
//	cout << ans;
//	return 0;
//}