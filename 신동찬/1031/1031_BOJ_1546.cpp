#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	float arr[1000] = { 0 };

	float maxV = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (arr[i] > maxV) {
			maxV = arr[i];
		}
	}

	float sumV = 0;
	for (int i = 0; i < n; i++) {
		sumV += (arr[i] / maxV) * 100;
	}
	
	cout << sumV / n;
	return 0;
}