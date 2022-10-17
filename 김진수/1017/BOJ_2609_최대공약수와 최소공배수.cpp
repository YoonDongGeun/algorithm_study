#include <iostream>

// 221017. 오늘은 사용자 정의 함수 연습을 위해 문제를 골랐다.
// 단순히 def로 시작하는 python과 달리 반환값에 따라 함수에도 int, void 등을 붙여줘야 한다.
// 그리고 GCD를 구현하는 과정에서 tmp를 이용해 a, b 두 변수의 값을 바꿔주는 연습도 할 수 있었다.

// 최대공약수 GCD를 찾는 함수. 유클리드 호제법의 원리이다.
int GCD(int a, int b)
{
	int tmp;
	if (a >= b)
	{
		while (b > 0)
		{
			tmp = a;
			a = b;
			b = tmp % a;
		}
		return a;
	}
	else
	{
		while (a > 0)
		{
			tmp = b;
			b = a;
			a = tmp % b;
		}
		return b;
	}
}

int main()
{
	using namespace std;

	int x, y;
	cin >> x;
	cin >> y;

	int G = GCD(x, y);
	cout << G << endl;
	cout << x * y / G << endl;
	return 0;
}