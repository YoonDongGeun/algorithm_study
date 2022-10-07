#include <iostream>
int small[16][1 << 16] = { 0, } , M[16][16], N, ans, min, v;
int Q[16];
int search(int now, int acted)
{
	if (small[now][acted] != 0)
	{
		return small[now][acted];
	}

	if (acted == ans)
	{
		if (M[now][0] == 0)
		{
			return -1;
		}
		return M[now][0];
	}

	int *p = Q;
	for (int i = 0; i < N; i++)
	{
		if (acted&(1 << i) || M[now][i] == 0)
		{
			continue;
		}
		v = search(i, acted | (1 << i));
		if (v == -1)
		{
			continue;
		}
		*p = v + M[now][i];
		p++;
		

	}
	if (p - Q == 0)
	{
		return -1;
	}
	if (*p > Q[0])
	{
		small[now][acted] = Q[0];
	}
	else
	{
		small[now][acted] = *p;
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
	}

	min = search(0, 1);
	std::cout << min << '\n';
	return 0;
}