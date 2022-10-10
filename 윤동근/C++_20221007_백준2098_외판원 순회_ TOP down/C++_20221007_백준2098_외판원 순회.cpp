#include <iostream>
int small[16][1 << 16], M[16][16]{ 0, }, N, ans, min;

int search(int now, int acted)
{
	if (small[now][acted] != -1)      // 이미 지났으면 return
	{
		return small[now][acted];
	}

	if (acted == ans)                 // 모두 순회했으면
	{
		if (M[now][0] == 0)          // 순회 불가하면
		{
			return 1000000000;
		}
		return M[now][0];           // 아니면 return
	}
	small[now][acted] = 1000000000;
	for (int i = 0; i < N; i++)
	{
		if (acted&(1 << i) || M[now][i] == 0)
		{
			continue;
		}
		int v = search(i, acted | (1 << i));
		if (small[now][acted] > v + M[now][i])
		{
			small[now][acted] = v + M[now][i];
		}
	}
	return small[now][acted];
}

int main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> N;
	ans = (1 << N) - 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> M[i][j];
		}
		for (int j = 0; j < (1 << N); j++)
		{
			small[i][j] = -1;
		}
	}
	min = search(0, 1);
	std::cout << min << '\n';
	return 0;
}