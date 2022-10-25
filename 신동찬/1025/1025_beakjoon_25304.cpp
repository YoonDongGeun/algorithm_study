#include <iostream>
using namespace std;

int main() {
	int total, n, cost, v, compare;
	cin >> total >> n;

	compare = 0;

	for (int i = 0; i < n; i++) {
		cin >> cost >> v;
		compare += (cost*v);
	}
	if (total == compare) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}

