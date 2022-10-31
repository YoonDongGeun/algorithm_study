#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, score, sumV;

	cin >> n;

	for (int tc = 0; tc < n; tc++) {
		char rst[80];
		sumV = 0;
		score = 1;
		cin >> rst;
		for (int i = 0; rst[i] != '\0'; i++) {
			if (rst[i] == 'O') {
				sumV += score;
				score += 1;
			}
			else {
				score = 1;
			}
		}
		cout << sumV << "\n";
	}

	return 0;
}