#include <iostream>
int small[16][1 << 16];

void search(int M[][16], int &N, int now, int *min, int acted, int &ans)  // DFS+백트래킹
{
	if (acted == ans)
	{
		if (M[now][0])   // 마지막에 원래 위치로 갈 수 있으면 시행
		{
			if (small[now][ans] + M[now][0] < *min)   // 작은값 갱신
			{
				*min = small[now][ans] + M[now][0];
			}
		}

	}
	else
	{
		for (int i = 1; i < N; i++)
		{
			if (acted&(1 << i))
			{
				continue;
			}
			else
			{
				if (M[now][i])
				{
					int go, tot;
					tot = M[now][i] + small[now][acted];
					go = acted | (1 << i);                // 앞으로 갈 상태
					if (tot < small[i][go])               // 만약 그곳으로 갈때 기존값보다 더 작으면 갱신하며 이동.
					{
						small[i][go] = tot;
						search(M, N, i, min, go, ans);
					}
				}

			}
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int N, now, min, ans;
	int M[16][16];
	std::cin >> N;
	ans = (1 << N) - 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> M[i][j];
		}
		for (int j = 0; j < 1 << N; j++)
		{
			small[i][j] = 17000000;
		}
	}

	min = 16000000;
	small[0][1] = 0;
	search(M, N, 0, &min, 1, ans);
	std::cout << min << '\n';
	return 0;
}