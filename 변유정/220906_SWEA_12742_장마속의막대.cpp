#include <iostream>
using namespace std;

/// 처음에 배열로 모두 구할 생각하지 말고
/// 간단하게 공식쓰기

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	long long a, b;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> a >> b;
		long long c = b - a;
		c = c * (c + 1) / 2;

		cout << "#" << tc << " " << c - b << "\n";
	}
}