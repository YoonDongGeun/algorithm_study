#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int arr[42] = { 0 }, n;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		arr[n % 42] += 1;
	}
	int cnt=0;
	for (int i = 0; i < 42; i++) {
		if (arr[i]) {
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}