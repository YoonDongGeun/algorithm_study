#include <iostream>


int DP[1000001] = { 0, };

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int TopDown(int N) {
	if (N == 1) return 0;
	if (DP[N]) return DP[N];
	if (N % 3 == 0 && N % 2 == 0) {
		DP[N]= min(TopDown(N - 1), min(TopDown(N / 3), TopDown(N / 2))) + 1;
		return DP[N];
	}
	else if (N % 3 == 0) {
		DP[N]= min(TopDown(N - 1), TopDown(N / 3)) + 1;
		return DP[N];
	}
	else if (N % 2 == 0) {
		DP[N]= min(TopDown(N - 1), TopDown(N / 2)) + 1;
		return DP[N];
	}
	else {
		DP[N] = TopDown(N - 1)+1;
		return DP[N];
	}
}


int main() {
	int N;
	scanf("%d", &N);
	DP[1] = 0;
	printf("%d", TopDown(N));
}