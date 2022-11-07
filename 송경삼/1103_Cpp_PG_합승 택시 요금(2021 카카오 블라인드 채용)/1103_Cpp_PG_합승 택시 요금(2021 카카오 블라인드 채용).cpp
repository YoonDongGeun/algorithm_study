#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 1e7;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e7));

	for (int i = 0; i < fares.size(); ++i) {
		dp[fares[i][0]][fares[i][1]] = fares[i][2];
		dp[fares[i][1]][fares[i][0]] = fares[i][2];
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][i] = 0;
	}


	for (int c = 1; c <= n; ++c) {
		for (int s = 1; s <= n; ++s) {
			for (int e = 1; e <= n; ++e) {
				
				if (dp[s][e] > dp[s][c] + dp[c][e]) dp[s][e] = dp[s][c] + dp[c][e];
			}
		}
	}
	for (int m = 1; m <= n; ++m) {
		int temp = dp[s][m] + dp[m][a] + dp[m][b];
		if (temp < answer) answer = temp;
	}

	return answer;
}



int main() {
	printf("%d", solution(7, 3, 4, 1, { {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6} }));
}