#include <iostream>
#include <vector>
using namespace std;

// DP 풀이
// 전역 변수 선언
int T, N;
vector<int> DP;

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;

		// DP[0]부터 DP[3]은 초기값이 들어간다.
		DP.push_back(0);
		DP.push_back(1);
		DP.push_back(2);
		DP.push_back(4);

		// 이후 DP[4]부터 DP[N]까지는 조건에 맞게 값을 넣어준다.
		for (int i = 4; i <= N; i++)
		{
			DP.push_back(DP[i - 1] + DP[i - 2] + DP[i - 3]);
		}

		// DP[N] 출력
		cout << DP[N] << '\n';

	}
	return 0;
}