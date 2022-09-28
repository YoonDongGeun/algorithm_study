#include <iostream>
using namespace std;

// 비트연산자 참고 사이트
//https://sf2020.tistory.com/29

int N;
double work[16][16];
// 비트연산자 + dp
double dp[1 << 16];
double dp1[16];

double make_dp(int now, int used)
{
	// 그 이상 넘어가버림면 되돌아오기
	if (now >= N) return 1;
	// -1 이 아니게 되면 최댓값 찾게 되는 것
	if (dp[used] != -1) return dp[used];
	// 가장 최솟값인 0으로 바꿔주기
	dp[used] = 0;
	for (int i = 0; i < N; i++)
		// 조건문 : 전에 i를 사용하지 않았다면(겹치는게 없다면)    // | 합쳐서 가져가기
		if (!(used & 1 << i)) dp[used] = max(dp[used], make_dp(now + 1, used | 1 << i) * work[now][i]);
	return dp[used];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				cin >> work[y][x];
				work[y][x] /= 100;
			}

		// 초기값 -1로 바꿔주기
		for (int i = 0; i < (1 << N); i++)
			dp[i] = -1;
		cout << '#' << tc << " ";
		cout << fixed;
		cout.precision(6);
		cout << make_dp(0,0) * 100 << '\n';
	}
}