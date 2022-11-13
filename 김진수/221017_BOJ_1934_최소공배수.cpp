#include <iostream>

// 최대공약수 GCD를 찾는 함수
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

// 최소공배수 LCM을 찾는 함수
int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}


int main()
{
	using namespace std;

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int x, y;
		cin >> x;
		cin >> y;

		cout << LCM(x, y) << endl;
	}
	return 0;
}