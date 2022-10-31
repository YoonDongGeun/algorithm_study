#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> arr(10);
	int maxV, mi, mj;
	maxV = 0;
	mi = 1; mj = 1;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int n;
			cin >> n;
			arr[i].push_back(n);
			if (n > maxV) {
				maxV = n;
				mi = i; mj = j;
			}
		}
	}
	cout << maxV << "\n" << mi << " " <<  mj;
	return 0;
}