#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int c;
	cin >> c;
	for (int tc = 0; tc < c; tc++) {
		int n;
		cin >> n;
		int arr[1000] = { 0 };
		int sumV = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sumV += arr[i];
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > sumV / n) {
				cnt += 1;
			}
		}
		cout<<fixed;
		cout.precision(3);
		cout << (float)cnt / n*100 << "%" << "\n";
	}
	

	return 0;
}