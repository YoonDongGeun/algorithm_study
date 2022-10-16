#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int N, M;
		int flag = 0;
		scanf("%d %d", &N, &M);
		char field[51][50];
		for (int i = 0; i < N; ++i) scanf("%s", field[i]);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (field[i][j] == '#') {
					for (int di = 0; di < 2; ++di) {
						for (int dj = 0; dj < 2; ++dj) {
							int ni = i + di, nj = j + dj;
							if (ni >= N || nj >= M || field[ni][nj] == '.') {
								flag = 1;
								break;
							}
							field[ni][nj] = '.';
						}
						if (flag) break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if (flag) printf("#%d NO\n", t);
		else printf("#%d YES\n", t);
	}


}