#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// DP 풀이
// 전역 변수 선언
int N;
vector<int> DP;

int main()
{
	cin >> N;

	// DP[0]과 DP[1]은 초기값 0이 들어간다.
	DP.push_back(0);
	DP.push_back(0);

	// 이후 DP[2]부터 DP[N]까지는 조건에 맞게 값을 넣어준다.
	// 2나 3의 배수라면 해당 DP[i/2] 혹은 DP[i/3] +1을, 이외에는 DP[i-1]+1을 넣는다.
	for (int i = 2; i <= N; i++)
	{
		DP.push_back(DP[i - 1] + 1);
		if (i % 2 == 0)
		{
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
	}
	
	// DP[N] 출력
	cout << DP[N];

	return 0;
}