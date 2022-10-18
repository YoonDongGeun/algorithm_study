// 공통 부분 문자열 문제의 DP 풀이이다.
// 처음으로 접하는 문자열 입력 문제였는데, C에서는 문자열의 길이를 지정해줘야 했었다.
// 하지만 C++에서 제공하는 string 클래스를 이용하면 getline()으로 간단하게 입력받을 수 있다.
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	int L1, L2;
	L1 = s1.length();
	L2 = s2.length();
	
	// dp라는 2차원 배열을 동적 할당하는 부분. int**와 new int*로 2중 포인터가 들어간다.
	int** dp = new int* [L1];
	for (int i = 0; i < L1; i++)
	{
		dp[i] = new int[L2];
	}

	// 2중 for문을 돌면서, s1과 s2의 문자열이 겹치는 (i, j) 칸에 숫자를 표기한다.
	// (i-1, j-1) 칸의 +1을 표기하면 연속되는 문자열의 길이를 의미한다.
	int result = 0;
	for (int i = 0; i < L1; i++)
	{
		for (int j = 0; j < L2; j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 or j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					// dp에 저장되는 가장 큰 값을 result에 할당한다.
					if (result < dp[i][j])
					{
						result = dp[i][j];
					}
				}
			}	
		}
	}

	// 동적 할당 시 메모리 누수 방지를 위해 메모리를 해제해줘야 한다.
	for (int i = 0; i < L1; i++)
	{
		delete[] dp[i];
	}

	cout << result << endl;

	return 0;
}