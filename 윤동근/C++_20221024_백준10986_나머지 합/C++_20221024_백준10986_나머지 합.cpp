#include <iostream>
using namespace std;
long long NS[1000002];
long long CNS[1002];

int main(void)
{
	long long N, M, cnt=0;
	cin >> N >> M;
	cin.ignore();
	NS[0] = 0;
	long long temp;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		NS[i] = (temp + NS[i - 1])%M;
	}

	for (int i = 0; i < M; i++)
	{
		CNS[i] = 0;
	}

	for (int i = 1; i <=N; i++)
	{
		CNS[NS[i]]++;
	}

	cnt += CNS[0];
	for (int i = 0; i < M; i++)
	{
		if (CNS[i] >= 2)
		{
			cnt += (CNS[i] * (CNS[i] - 1)) / 2;
		}
	}
	cout << cnt << '\n';
	return 0;
}