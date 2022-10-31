#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <vector<int>> arr(101, vector<int>(101, 0));
	int N;
	cin >> N;

	int cnt = 0;
	while (N--) {
		int a, b;
		cin >> a >> b;
		for (int i = 100 - b - 10; i < 100 - b; i++) {
			for (int j = a; j < a + 10; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					cnt += 1;
				}
			}
		}

	}
	cout << cnt;
	return 0;
}