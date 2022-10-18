#include <iostream>
int N;
int DP[1001][3] = {0, };
int M[1000][3];
int temp[3] = { 100000000 };
int ans;
int min(int a, int b) {
	return a < b ? a : b;
}
int main(void)
{
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> M[i][0] >> M[i][1] >> M[i][2];
	}
	DP[0][0] = M[0][0];
	DP[0][1] = M[0][1];
	DP[0][2] = M[0][2];
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (k == j)
			{
				DP[0][k] = M[0][k];
			}
			else
			{
				DP[0][k] = 100000000;
			}
		}
		for (int i = 1; i < N; i++)
		{
			DP[i][0] = M[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
			DP[i][1] = M[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
			DP[i][2] = M[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
		}
		temp[j] = min(DP[N - 1][(j + 1)%3], DP[N - 1][(j + 2)%3]);
	}
	ans = temp[0];
	for (int i = 1; i < 3; i++)
	{
		ans = min(ans, temp[i]);
	}
	std::cout << ans << '\n';
}