#include <iostream>
int N;
int M[20][20];
int DP[20][1 << 20] = { 0, };
int min(int a, int b);
int search(int n, int now, int go);
// 흐름을 생각하기
// 마지막 칸 갔을때 어떻게 처리할지 결정하기
// 방문한 칸 어떻게 처리할지 결정하기
// 탑다운

int main(void)
{
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> M[i][j];
		}
	}

	std::cout << search(0, 0, 0) << '\n';
	return 0;
}

int search(int n, int now, int go) {
	if (n == N)
	{
		return 0;
	}
	if (DP[n][now])
	{
		return DP[n][now];
	}
	DP[n][now] = 100000000;
	for (int j = 0; j < N; j++)
	{
		if (!(now & 1 << j))
		{
			DP[n][now] = min(DP[n][now], search(n + 1, now | 1 << j, j) + M[n][j]);
		}
	}

	return DP[n][now];
}

int min(int a, int b)
{
	return a > b ? b : a;
}