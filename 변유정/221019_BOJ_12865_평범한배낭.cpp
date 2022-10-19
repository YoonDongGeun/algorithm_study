#include <iostream>
#include <algorithm>
using namespace std;

//DP 문제
// 힌트 : 무게별로 나누기
// 배낭순서로 계속 돌리면서,
// 1. 현재 버틸만한 무게면 전의 배낭값과 비교해서 최대값 올리기
// 2. 넘어서면 전의 배낭값으로 해주기

int N, K, bag[101][2];
int dp[101][100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> bag[i][0] >> bag[i][1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= bag[i][0]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - bag[i][0]] + bag[i][1]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
}