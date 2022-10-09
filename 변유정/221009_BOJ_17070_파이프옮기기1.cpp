#include <iostream>
using namespace std;

// 구현 + 시뮬레이션
// 구현 과정
// 1. 파이프 놓을 때, 끝점 기준으로 생각하기
// 2. 파이프 초기 놓아둔 방향 - 가로 (가로따라서 개수 미리 설정해두기)
// 3. 배열 3가지로 나눠서 따지기 (가로, 세로, 대각선 순)
// 4. 파이프 이동할 때, 벽이 있는지 없는지 따져서 옮기기

int N, home[17][17];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> home[y][x];
	int dp[17][17][3] = {0,};
	dp[1][2][0] = 1;
	for (int x = 3; x <= N; x++)
		if (!home[1][x]) dp[1][x][0] = dp[1][x - 1][0];

	for (int y = 2;y<=N;y++)
		for (int x = 2; x <= N; x++)
		{
			if (!home[y][x])
			{
				dp[y][x][0] = dp[y][x - 1][0] + dp[y][x - 1][2];
				dp[y][x][1] = dp[y - 1][x][1] + dp[y - 1][x][2];
			}
			if (!home[y][x] && !home[y - 1][x] && !home[y][x - 1])
				dp[y][x][2] = dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
		}
	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}