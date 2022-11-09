#include <iostream>
#include <vector>

using namespace std;

int check_n(int n) {
	vector<int> arr;
	int k = 0;

	if (n < 100) {
		return 1;
	}
	else {
		while (n) {
			int a = n % 10;
			arr.push_back(a);
			n /= 10;
		}

		int diff;
		diff = arr[1] - arr[0];

		for (int i = 2; i < arr.size(); i++) {
			int temp = arr[i] - arr[i - 1];
			if (temp != diff) {
				return 0;
			}
		}
	}
	return 1;

}

int main() {
	int x;
	cin >> x;

	int cnt = 0;
	for (int i = 1; i <= x; i++) {
		if (check_n(i)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}