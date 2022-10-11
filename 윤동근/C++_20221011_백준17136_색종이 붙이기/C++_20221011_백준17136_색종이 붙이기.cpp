#include <iostream>
int M[10][10];
int possible[10][10] = { 0, };
int pp[5] = { 5,5,5,5,4 };
int y, x, w, h, cnt, min = 26, ans = 0;
void search(int k, int y, int x)
{

	if (cnt == 0)
	{
		if (min > ans)
		{
			min = ans;
		}
		return;
	}
	if (min == ans + 1)
	{
		return;
	}
	if (k == 0)
	{
		if (cnt <= 5)
		{
			if (min > ans + cnt)
			{
				min = ans + cnt;
			}
		}
		return;
	}
	if (k == 1)
	{
		if (cnt > 25)
		{
			return;
		}
	}


	if ((k + 1)*(k + 1) <= cnt && pp[k])
	{
		for (int i = y; i < 10-k; i++)
		{
			for (int j = 0; j < 10-k; j++)
			{
				if (M[i][j] && (possible[i][j] & (1 << k)) && M[i + k][j + k] && M[i + k][j] && M[i][j + k])
				{
					for (int i2 = i; i2 < i + k + 1; i2++)
					{
						for (int j2 = j; j2 < j + k + 1; j2++)
						{
							M[i2][j2] = 0;
						}
					}

					cnt -= (k + 1)*(k + 1);
					ans += 1;
					pp[k] -= 1;
					search(k, i, j);
					pp[k] += 1;
					cnt += (k + 1)*(k + 1);
					ans -= 1;
					for (int i2 = i; i2 < i + k + 1; i2++)
					{
						for (int j2 = j; j2 < j + k + 1; j2++)
						{
							M[i2][j2] = 1;
						}
					}
				}
			}
		}
	}

	if (k >0)
	{
		search(k - 1, 0, 0);
	}
}


int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cin >> M[i][j];
			if (M[i][j])
			{
				cnt++;
			}
		}
	}

	for (int q = 0; q < 10; q++)
	{
		for (int e = 0; e < 10; e++)
		{
			if (M[q][e])
			{
				int flag = 1;
				h = 0;
				while (flag != 5)
				{
					h = 0;
					while (h != flag)
					{
						if (q + flag >= 10)
						{
							h = flag - 1;
							flag = 5;
							break;
						}
						if (e + flag >= 10)
						{
							h = flag - 1;
							flag = 5;
							break;
						}
						if (!M[q + flag][e + h])
						{
							h = flag - 1;
							flag = 5;
							break;
						}

						if (!M[q + h][e + flag])
						{
							h = flag - 1;
							flag = 5;
							break;
						}
						h++;
					}
					if (flag!=5)
					{
						flag++;
					}
				}
				while (h != -1)
				{
					possible[q][e] |= 1 << h;
					h--;
				}

			}
		}
	}


	search(4,0,0);
	min == 26 ? min = -1 : min = min;
	std::cout << min << '\n';



	return 0;

}
