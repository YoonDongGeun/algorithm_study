#include <iostream>

int s, N, K, R1, R2, C1, C2, i,j,l,r, n;

int goback(int s,int di, int dj) {
	if (!s) {
		return 0;
	}
	else {
		int x;
		x=goback(s-1, di / N, dj / N);
		if (!x) {
			if ((di%N) >= l && (di%N) < r && (dj%N) >= l && (dj%N) < r) {
				return 1;
			}
			else return 0;
		}
		else return 1;
	}
}


int main() {
	scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
	l = (N - K)/2;
	r = N - l;
	for (int i = R1; i <= R2; ++i) {
		for (int j = C1; j <= C2; ++j) {
			printf("%d",goback(s,i, j));
		}
		printf("\n");
	}
	printf("\n");
}


