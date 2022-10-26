#include <iostream>
using namespace std;

int main() {
	int N, n, x;
	cin >> N >> x;

	for (int i = 0; i < N; i++) {
		//seq[i] = scanf("%d", n);
		cin >> n;
		if (n < x) {
			cout << n << " ";
		}
	}

	return 0;
}