#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, val;
	cin >> n >> m;
	int A[100][100] = { 0, }, B[100][100];

	int k = 0;
	while (k < 2)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> val;
				A[i][j] += val;
				if (k == 1) {
					cout << A[i][j] << " ";
				}
			}
			cout << "\n";
		}
		k += 1;
	}

	return 0;
}