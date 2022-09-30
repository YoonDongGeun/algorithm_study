#include <iostream>

int FD(int a, int *P) {
	while (a !=P[a]) a = P[a];
	return a;
}
void UN(int a, int b, int *P) {
	P[FD(b, P)] = FD(a, P);
}

int main() {
	int T;
	scanf("%d", &T);
	for ( int t = 1; t <= T; ++t ){
		int N, M, P[101], cntA[101] = { 0, }, cnt = 0, a, b, sub;
		scanf("%d %d", &N, &M);
		for (int i = 0; i <= N; ++i) P[i] = i;
		while (M--) {
			scanf("%d %d", &a, &b);
			if (a > b) UN(b, a,P);
			else UN(a, b, P);
		}
		for (int i = 1; i <= N; ++i) {
			sub=FD(i, P);
			if (!cntA[sub]) {
				cntA[sub] = 1;
				++cnt;
			}
		}
		printf("#%d %d\n", t, cnt);
	}
}