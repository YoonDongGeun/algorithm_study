#include <iostream>
using namespace std;

// 알고리즘 - 수학, 정수론, 소수판정, 에라토스테네스의 체
// 조건 : 1 <= min <= 1,000,000,000,000
//		  min <= max <= min + 1,000,000

long long mn, mx;
bool checked[1100000];
// 조건 : min - max 1,000,000 이기 때문에 체크

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> mn >> mx;
	int ans = 0;

	for (long long i = 2; i * i <= mx; i++)
	{
		long long N = mn / (i * i);
		// 제곱수 배수 최솟값 구하기 (mn 부터 시작해야함)
		if (mn % (i * i)) N++;

		while (N * i * i <= mx)
		{
			checked[N * i * i - mn] = 1;
			N++;
		}
	}
	for (int i = 0; i <= mx - mn; i++)
		if (!checked[i]) ans++;
	cout << ans;
}