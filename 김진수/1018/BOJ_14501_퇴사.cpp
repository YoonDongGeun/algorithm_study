#include <iostream>
using namespace std;

// [A] 전역 변수 설정
int N, result;
int* T;
int* P;

// [B] DFS 함수 설정
void dfs(int start, int money)
{
	// [B-1] 가지치기 조건. N+1일을 넘기면 그대로 종료한다.
	if (start > N + 1)
	{
		return;
	}
	// [B-2] 종료 조건. N+1일에 도달하면 money를 result값과 비교한다.
	else if (start == N + 1)
	{
		if (result < money)
		{
			result = money;
		}
		return;
	}

	dfs(start + T[start], money + P[start]); // 오늘 상담을 잡는 경우
	dfs(start + 1, money); // 오늘 상담을 잡지 않는 경우
	
}


// [1] 입력값 설정
int main()
{
	cin >> N;
	
	// [1-1] 동적 할당으로 T와 P 배열을 만들어 값을 받는다.
	T = new int[N + 1];
	P = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
	{
		cin >> T[i];
		cin >> P[i];
	}

	// [2] DFS 탐색 및 출력
	dfs(1, 0);
	cout << result << endl;

	// [1-2] 메모리 누수 방지를 위한 메모리 해제
	delete[] T;
	delete[] P;

	return 0;
}
