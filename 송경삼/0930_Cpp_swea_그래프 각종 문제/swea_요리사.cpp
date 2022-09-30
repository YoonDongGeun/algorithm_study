#include <iostream>

int min,N;

void C(int n, int last, int (*food)[16], int choice[]) {
	if (n == N/2) {

		int c1 = 0, c2 = 0,ans;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (choice[i]&&choice[j]) c1 += food[i][j];
				else if (!choice[i]&&!choice[j]) c2 += food[i][j];
			}

		}
		if (c1 > c2) ans = c1 - c2;
		else ans = c2 - c1;
		if (ans < min) min = ans;
	}
	else{
		for (int i = 0; i < N; ++i) {
			if (i > last && !choice[i]) {
				choice[i] = 1;
				int temp = last;
				last = i;
				C(n + 1, last, food, choice);
				last = temp;
				choice[i] = 0;
			}

		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		min = 1e10;
		scanf("%d", &N);
		int food[16][16], choice[16] = {0,};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%d", &food[i][j]);
			}
		}
		C(0, -1, food, choice);
		printf("#%d %d\n", t, min);
	}
}