#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M,sub;
	cin >> N >> M;
	int L[100][100];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> L[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> sub;
			cout << L[i][j] + sub << " ";
		}
		cout << "\n";
	}

}