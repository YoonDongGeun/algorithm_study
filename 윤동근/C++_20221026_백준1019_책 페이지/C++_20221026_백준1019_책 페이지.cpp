#include <iostream>
using namespace std;
int power(int x, int n){
	for (int i = 0; i < n; i++)
	{
		x *= 10;
	}
	return x;
}


int main(void) {
	char NC[11];
	int N, dg, N2;
	cin >> NC;
	dg = -1, N=0;
	for (int i = 0; i < 11; i++)
	{
		dg++;
		if (NC[i] == '\0')
			break;
	}
	int dg2 = dg;
	while (dg)
	{
		N += (NC[dg2-dg]-'0')*power(1, dg-1);
		dg--;
	}

	int A[11] = {0, 1, };
	int B[11] = { 0, 0, };
	int ans[10] = { 0, };
	for (int i = 2; i <= 10; i++)
	{
		A[i] = A[i - 1] * 10 + power(1, i-1);
		B[i] = B[i-1] + A[i - 1] * 9;
	}
	ans[0] = B[dg2-1];
	for (int i = 1; i < 10; i++)
	{
		ans[i] = A[dg2 - 1];
	}

	int s = 0;
	N2 = N;
	for (int i = 0; i < dg2; i++)
	{
		N = NC[i] - '0';
		N2 -= N * power(1, dg2 - i - 1);
		if (i == 0)
		{
			if (dg2 - i - 1 != 0)
			{
				for (int j = 1; j < N; j++)
				{
					ans[j] += power(1, dg2 - i-1);
				}
				s += (power(1, dg2 - i-1) * (dg2 - i-1) / 10)*(N-1);
				ans[N] += N2 + 1;
			}
			else
			{
				for (int j = 0; j <= N; j++)
				{
					ans[j] += 1;
				}
				if (dg2 == 1)
				{
					ans[0] -= 1;
				}
			}
		}
		else
		{
			if (dg2 - i - 1 != 0) // 마지막 자릿수 아니면
			{
				for (int j = 0; j < N; j++)
				{
					ans[j] += power(1, dg2 - i-1); //dg2자리수 
				}
				s += (power(1, dg2 - i-1) * (dg2 - i-1) / 10)*N;
				ans[N] += N2 + 1;
			}
			else  //마지막 자릿수면
			{
				for (int j = 0; j <= N; j++)
				{
					ans[j] += 1;
				}

			}

		}
	}
	for (int i = 0; i < 10; i++)
	{
		ans[i] += s;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}