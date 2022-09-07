#include <iostream>
#include <cstring>
using namespace std;

/// 문제 이해하기
/// 필요한 개념 : DP(메모이제이션), 누적합
/// 
/// 중요한 것은 2차원 배열이기 때문에 각 방향에서 최소값끼리 더해줘야 한다
/// - 구현 중요!
/// - DP topdown bottom-up 다시 공부하기 (이거는 최대값부터 구하기 때문에 topdown)

int T, N, M;
int arr[51][51]; // 초콜릿 위치당 건포도
int summ[51][51]; // 건포도 위치에서의 누적합
int dp[51][51][51][51];///[a][b][c][d] : a,b 에서 c,d 까지 자르는데 필요한 건포도 수

void prefix_sum() ///위치당 누적합 미리 구하기
{
	for (int y = 1;y<=N;y++)
		for (int x = 1; x <= M; x++)
			summ[y][x] = summ[y][x - 1] + summ[y - 1][x] - summ[y-1][x - 1] + arr[y][x];
}

int div_choco(int s_y,int s_x,int e_y,int e_x)
{
	if (s_y == e_y && s_x == e_x) return 0;
	if (dp[s_y][s_x][e_y][e_x] != -1) return dp[s_y][s_x][e_y][e_x];

	dp[s_y][s_x][e_y][e_x] = 1e9;
	// 미리 큰값으로 만들어두기
	int temp = summ[e_y][e_x] - summ[s_y - 1][e_x] - summ[e_y][s_x - 1] + summ[s_y-1][s_x-1];
	// {s_y,s_x} ~ {e_y,e_x} 범위 arr 누적합 구하기
	for (int i = s_y; i < e_y; i++)
		dp[s_y][s_x][e_y][e_x] = min(dp[s_y][s_x][e_y][e_x], div_choco(s_y, s_x, i, e_x) + div_choco(i + 1, s_x, e_y, e_x) + temp);
	//가로 자르기 (y)
	// 가로 잘라보고 합이 더 작으면 그걸로 바꾸기

	for (int i = s_x; i < e_x; i++)
		dp[s_y][s_x][e_y][e_x] = min(dp[s_y][s_x][e_y][e_x], div_choco(s_y, s_x, e_y, i) + div_choco(s_y, i+1, e_y, e_x) + temp);
	// 세로 자르기 (x)
	// 세로로 잘라보고 합이 더 작으면 그걸로 바꾸기


	return dp[s_y][s_x][e_y][e_x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= M; x++)
				cin >> arr[y][x];

		memset(summ, 0, sizeof(summ));
		memset(dp, -1, sizeof(dp));

		prefix_sum();
		int ans = div_choco(1, 1, N, M);
		cout << "#" << tc << " " << ans << "\n";
	}
}