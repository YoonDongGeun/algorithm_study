#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		int N, M;
		cin >> N >> M;

		long long DP[31];
		DP[0] = 1;
		DP[1] = 1;
		for (int i = 2; i <= M+1; i++)
		{
			DP[i] = i * DP[i - 1];
		}
		cout << (DP[M] / (DP[M - N] * DP[N])) << '\n';
	}
	return 0;
}