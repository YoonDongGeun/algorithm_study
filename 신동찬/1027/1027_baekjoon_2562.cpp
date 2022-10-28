#include <iostream>
using namespace std;

int main() {
	int num, idx, maxV;

	maxV = 0;
	idx = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> num;
		if (num > maxV) {
			maxV = num;
			idx = i;
		}

	}
	printf("%d\n%d", maxV, idx);

	return 0;
}
