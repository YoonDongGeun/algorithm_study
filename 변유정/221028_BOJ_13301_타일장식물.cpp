#include <iostream>
using namespace std;

// 알고리즘 분류 : 수학, DP
//
// 구현 단계
// 1. DP 숫자 구하기 (피보나치 수열)
// 2. 1을 제외한 나머지는 N * 4 + (N-1) * 2

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	long long dp[81] = { 0, };
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	if (N == 1) cout << 4;
	else cout << dp[N-1] * 4 + dp[N - 2] * 2;
}