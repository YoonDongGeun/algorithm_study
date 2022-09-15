#include <iostream>
using namespace std;

///  자료형 문제
///  나눗셈으로 시도해봤다가 실패
/// 
/// float, double 등 모두 같은 값이 아니라 최대한 비슷한 값을 저장함
/// 
/// 반례 (48228548,48228549,48228550)
/// 모두 364가 나온다
/// 부동 소수점과 실수처리에 대해 이해 필요

int T;
long long N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (long long x = 1; x <= 1000000; x++)
		{
			if (x * x * x == N)
			{
				cout << "#" << tc << " " << x << "\n";
				break;
			}

			else if (x * x * x > N)
			{
				cout << "#" << tc << " " << -1 << "\n";
				break;
			}
		}
	}
}

//내가 틀렸던 코드

//#include <cmath>
//using namespace std;
//
//int T;
//long long N;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> T;
//	for (int tc = 1; tc <= T; tc++)
//	{
//		cin >> N;
//		int a = cbrt(N);
//		float b = cbrt(N);
//		if (a == b) cout << "#" << tc << " " << a << "\n";
//		else cout << "#" << tc << " " << -1 << "\n";
//	}
//}