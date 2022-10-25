#include <iostream>
using namespace std;

int main() {
	int n, v;
	cin >> n;
	
	int arr[101];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> v;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == v) {
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}