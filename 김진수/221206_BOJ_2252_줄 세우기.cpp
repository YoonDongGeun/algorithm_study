#include <iostream>
#include <vector>
using namespace std;

// [A] 전역 변수 선언
int N, M;
vector<int> check(32001, 0);
vector<int> ans;

int main()
{
	// [1] 입력값 설정
	cin >> N >> M;

	// [2] M개 줄에서 주어지는 학생을 a, b라고 했을 때,
	//     a는 ans 앞에, b는 뒤에 세우고 check 처리한다.
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		if (check[a] == 0)
		{
			check[a] = 1;
			ans.insert(ans.begin(), a);
		}
		if (check[b] == 0)
		{
			check[b] = 1;
			ans.push_back(b);
		}
	}

	// [3] 순번을 세우지 않은(check 처리되지 않은) 학생들을 추가한다.
	for (int i = 1; i < N + 1; i++)
	{
		if (check[i] == 0)
		{
			ans.push_back(i);
		}
	}

	// [4] ans를 출력한다.
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
