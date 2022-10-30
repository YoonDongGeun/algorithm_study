#include <iostream>
using namespace std;

int dp[1000001] = { 0, };

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

int func(int n) {
	if (n == 1) return 0;

	if (dp[n] != 0) return dp[n];
	else {
		if (n % 3 == 0 && n % 2 == 0) {
			dp[n] = min(func(n / 3) + 1, min(func(n / 2) + 1, func(n - 1) + 1));
		}
		else if (n % 3 == 0) {
			dp[n] = min(func(n / 3) + 1, func(n - 1) + 1);
		}
		else if (n % 2 == 0) {
			dp[n] = min(func(n / 2) + 1, func(n - 1) + 1);
		}
		else {
			dp[n] = func(n - 1) + 1;
		}
	}

	return dp[n];
}

int main(void) {
	int N;
	cin >> N;
	cout << func(N);
}