#include <string>
#include <vector>

using namespace std;

int max(int a,int b) {
	if (a > b) return a;
	return b;
}

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int N = size(triangle);
	vector<vector<int>> dp(N);
	for (int i = 0; i < N; ++i) dp[i].resize(i+1);
	for (int i = 0; i < N; ++i) for (int j = 0; j < i+1; ++j) dp[i][j] = -1;
	dp[0][0] = triangle[0][0];

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if (j == 0) dp[i][j] = dp[i - 1][j]+triangle[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
		}
	}
	int last = N - 1;
	for (int j = 0; j < N; ++j) if (dp[last][j] > answer) answer = dp[last][j];
	return answer;
}