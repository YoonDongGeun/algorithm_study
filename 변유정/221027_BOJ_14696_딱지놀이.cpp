#include <iostream>
using namespace std;

// 알고리즘 : 구현
// 배열로 구분하고 숫자에 맞게 ++ 하기
// 같은 인덱스의 배열 비교했을 때, 숫자가 큰 어린이(A,B) 출력 후 멈춤
// 만약 끝까지 안나왔을 때, 무승부 D 출력

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cntA, cntB;
		int AA[5] = { 0, }, BB[5] = { 0, };
		cin >> cntA;
		for (int k = 0; k < cntA; k++)
		{
			int a;
			cin >> a;
			AA[a]++ ;
		}

		cin >> cntB;
		for (int k = 0; k < cntB; k++)
		{
			int b;
			cin >> b;
			BB[b]++;
		}
		
		int k = 4;
		while (k > 0)
		{
			if (AA[k] > BB[k])
			{
				cout << 'A' << '\n';
				break;
			}
			else if (AA[k] < BB[k])
			{
				cout << 'B' << '\n';
				break;
			}
			k--;
		}
		if (k == 0) cout << 'D' << '\n';
	}
}