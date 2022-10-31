#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int arr[31], n;
	for (int i = 0; i < 28; i++) {
		cin >> n;
		arr[n] = 1;
	}
	for (int i = 1; i < 31; i++) {
		if (arr[i] != 1) {
		cout << i << "\n";
		}
	}

	return 0;
}