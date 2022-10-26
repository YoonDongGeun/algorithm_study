#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, num, ismax, ismin;
	cin >> n;
	
	ismax = -1000000; ismin = 1000000;

	for (int i = 0; i < n; i++) {
		cin >> num;

		if (num > ismax) {
			ismax = num;
		}
		if (num < ismin) {
			ismin = num;
		}
	}	
	printf("%d %d", ismin, ismax);

	return 0;
}
