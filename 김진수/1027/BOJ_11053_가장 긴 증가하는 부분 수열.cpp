#include <iostream>
#include <algorithm>
using namespace std;

// 전역 변수 설정
int N, A[1000], check[1000];

int main()
{
	// [1] 입력값 설정
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		check[i] = 1;
	}

	// [2] DP 풀이. 수열 A의 각 i 위치에서 j 위치 값과 비교할 때
	// i의 숫자가 더 크다면 check[i]를 비교 및 갱신한다.
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{
				check[i] = max(check[i], check[j] + 1);
			}
		}
	}

	// [3] check에 담긴 가장 큰 값을 출력한다.
	cout << *max_element(check, check+N) << '\n';
	return 0;
}