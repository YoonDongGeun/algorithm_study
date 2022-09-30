#include <iostream>

int min, max;

void P(int n, int N, int comb[], int op[], int last[], int used[], int num[]) {
	if (n == N-1) {
		int pre=num[0];
		for (int i = 0; i < N - 1; ++i) {
			if (comb[i] == 1) {
				pre += num[i+1];
			}
			else if (comb[i] == 2) {
				pre -= num[i + 1];
			}
			else if (comb[i] == 3) {
				pre *= num[i + 1];
			}
			else if (comb[i] == 4) {
				pre/=num[i + 1];
			}

		}
		if (pre > max)max = pre;
		if (pre < min) min = pre;

	}
	else if (n<op[1]){
		for (int i = 0; i < N - 1; ++i) {
			if (last[1] < i && !used[i]) {
				int temp = last[1];
				last[1] = i;
				used[i] = 1;
				comb[i] = 1;
				P(n + 1, N, comb, op, last, used,num);
				last[1] = temp;
				used[i] = 0;
				comb[i] = 0;
			}
		}
	}
	else if (n < op[1]+op[2]) {
		for (int i = 0; i < N - 1; ++i) {
			if (last[2] < i && !used[i]) {
				int temp = last[2];
				last[2] = i;
				used[i] = 1;
				comb[i] = 2;
				P(n + 1, N, comb, op, last, used, num);
				last[2] = temp;
				used[i] = 0;
				comb[i] = 0;
			}
		}
	}
	else if (n < op[1] + op[2]+op[3]) {
		for (int i = 0; i < N - 1; ++i) {
			if (last[3] < i && !used[i]) {
				int temp = last[3];
				last[3] = i;
				used[i] = 1;
				comb[i] = 3;
				P(n + 1, N, comb, op, last, used, num);
				last[3] = temp;
				used[i] = 0;
				comb[i] = 0;
			}
		}
	}
	else if (n < op[1] + op[2]+op[3]+op[4]) {
		for (int i = 0; i < N - 1; ++i) {
			if (last[4] < i && !used[i]) {
				int temp = last[4];
				last[4] = i;
				used[i] = 1;
				comb[i] = 4;
				P(n + 1, N, comb, op, last, used, num);
				last[4] = temp;
				used[i] = 0;
				comb[i] = 0;
			}
		}
	}
	

}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		min = 1e10, max = -1e10;
		int N, op[5], num[12], comb[11], used[11] = {0,};
		scanf("%d", &N);
		for (int i = 1; i < 5; ++i) scanf("%d", &op[i]);
		for (int i = 0; i < N; ++i) scanf("%d", &num[i]);
		int last[5];
		for (int i = 1; i < 5; ++i) last[i]=-1;
		P(0, N, comb, op, last, used, num);
		printf("#%d %d\n", t, (max - min));
	}
}