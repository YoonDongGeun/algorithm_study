#include <iostream>
#include <algorithm>
using namespace std;

// 알고리즘 구현: dp
// 중요한 점: 배열 설정 
// dp[날짜][이용권 쿠폰 갯수] - 에 맞춰서 최소 비용을 저장해야함

// 아래 코드 : 5일 > 3일 + 하루 라서 거르지 못함
// 위 코드 : 메모이제이션(?)

int N, M, a;
bool resort[101] = { 0, };
int dp[101][101] = { 0, };

int dfs(int day, int ticket)
{
	if (day > N) return 0;
	if (dp[day][ticket] != 1e9) return dp[day][ticket];
	if (resort[day]) return dp[day][ticket] = dfs(day + 1, ticket);
	dp[day][ticket] = min(dp[day][ticket], dfs(day + 1, ticket) + 10000);
	dp[day][ticket] = min(dp[day][ticket], dfs(day + 3, ticket + 1) + 25000);
	dp[day][ticket] = min(dp[day][ticket], dfs(day + 5, ticket + 2) + 37000);
	if (ticket >= 3) dp[day][ticket] = min(dp[day][ticket], dfs(day + 1, ticket - 3));
	return dp[day][ticket];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		resort[a] = 1;
	}
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			dp[i][j] = 1e9;
	cout << dfs(1, 0);
}

//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int N, M, a;
//int ticket[3] = { 10000,25000,37000 };
//bool resort[101] = { 0, };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a;
//		resort[a] = 1;
//	}
//
//	int dp[101][2] = { 0, };
//	memset(dp, 0, sizeof(dp));
//	if (!resort[1]) dp[1][0] = ticket[0];
//
//	if (!resort[2]) dp[2][0] = dp[1][0] + ticket[0];
//	else dp[2][0] = dp[1][0];
//
//	if (!resort[3])
//	{
//		if (dp[2][0] + ticket[0] >= dp[0][0] + ticket[1])
//		{
//			dp[3][0] = dp[0][0] + ticket[1];
//			dp[3][1] = 1;
//		}
//		else dp[3][0] = dp[2][0] + ticket[0];
//	}
//	else dp[3][0] = dp[2][0];
//
//	if (!resort[4])
//	{
//		if (dp[3][0] + ticket[0] >= dp[1][0] + ticket[1])
//		{
//			dp[4][0] = dp[1][0] + ticket[1];
//			dp[4][1] = dp[1][1] + 1;
//		}
//		else dp[4][0] = dp[3][0] + ticket[0];
//	}
//	else dp[4][0] = dp[3][0];
//
//	for (int i = 5; i <= N; i++)
//	{
//		if (resort[i])
//		{
//			dp[i][0] = dp[i - 1][0];
//			dp[i][1] = dp[i - 1][1];
//		}
//		else
//		{
//			int t1 = dp[i - 1][0] + ticket[0];
//			int t2 = dp[i - 3][0] + ticket[1];
//			int t3 = dp[i - 5][0] + ticket[2];
//
//			if (dp[i - 1][1] >= 3)
//			{
//				if (t1 - ticket[0] < t2 && t1 - ticket[0] < t3)
//				{
//					dp[i][0] = dp[i - 1][0];
//					dp[i][1] = dp[i - 1][1] - 3;
//					continue;
//				}
//			}
//			
//			if (t1 < t2 && t1 < t3)
//			{
//				dp[i][0] = t1;
//				dp[i][1] = dp[i - 1][1];
//			}
//			else if (t2 <= t1 && t2 < t3)
//			{
//				dp[i][0] = t2;
//				dp[i][1] = dp[i - 3][1] + 1;
//			}
//			else if (t3 <= t1 && t3 <= t2)
//			{
//				dp[i][0] = t3;
//				dp[i][1] = dp[i - 5][1] + 2;
//			}
//		}
//	}
//	cout << dp[N][0];
//}