#include <iostream>
using namespace std;

// 알고리즘: 누적합
// 1. 숫자 배수되는 것에서 더해주기
// 2. 누적으로 더해주기

// 뒤의 것은 나눠주기 (틀림)

int T, tc;
long long dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 1000000; i++)
		for (int j = i; j <= 1000000; j+=i)
			dp[j] += i;

	for (int i = 2; i <= 1000000; i++)
		dp[i] += dp[i - 1];

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> tc;
		cout << dp[tc] << '\n';
	}
}

//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//int T, tc;
//vector <int> vect(1000001);
//void making()
//{
//	int i = 1;
//	vect[i] = 1;
//	while (i++)
//	{
//		if (i > 1000000) break;
//		long long temp = 0;
//		int idx = sqrt(i) + 1;
//		for (int j = 1; j < idx; j++)
//			if (i % j == 0)
//			{
//				temp += j;
//				if (j != i / j) temp += i / j;
//			}
//		vect[i] += vect[i - 1] + temp;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> T;
//	making();
//	for (int i = 0; i < T; i++)
//	{
//		cin >> tc;
//		cout << vect[tc] << '\n';
//	}
//}