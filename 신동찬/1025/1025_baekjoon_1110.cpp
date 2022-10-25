#include <iostream>
using namespace std;

int main() {
	int n, a, b, c, new_n;
	cin >> n;
	new_n = n;

	int cnt = 0;
	while (true)
	{	
		a = new_n / 10;
		b = new_n % 10;
		c = (a + b) % 10;
		new_n = b*10 + c;
		cnt++;

		if (new_n == n) {
			cout << cnt;
			break;
		}
	}

	return 0;
}