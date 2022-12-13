#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [A] 전역 변수 선언
int N, K;
vector<int> DP;


int main()
{
	// [1] 입력값 설정
	cin >> N >> K;

	for (int i = 0; i <= K; i++)
	{
		DP.push_back(0);
	}

	// [2] 1차원 DP 풀이
	//     K부터 W까지 역순으로 DP[i](= 현재까지의 최대값)과 V+DP[i-W](= 이번 물건을 포함한 최대값)을 비교한다.
	for (int n = 0; n < N; n++)
	{
		int W, V;
		cin >> W >> V;

		for (int i = K; i >= W; i--)
		{
			DP[i] = max(DP[i], V + DP[i - W]);
		}
	}

	cout << DP[K] << endl;
	return 0;
}
