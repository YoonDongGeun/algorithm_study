#include <iostream>

struct T {	//input의 정보를 한번에 다룰 구조체
	int I;
	int J;
	int D;
};
void DFS(int n, int* MIN, int(*table)[51], T Tlist[], int visit[], int& K, int& N, int& M);
void turn(int(*table)[51], T Ta, int dir);

int main() {
	int N, M,K;
	scanf("%d %d %d", &N, &M, &K);
	int table[51][51];
	T Tlist[6];	//회전 수는 최대 6개입니다

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			scanf("%d", &table[i][j]);
		}
	}

	int I, J, D;
	for (int k = 0; k < K;++k) {
		scanf("%d %d %d", &I, &J, &D);	
		Tlist[k] = { I,J,D };		//회전 정보를 회전 리스트에 추가합니다.
	}

	int visit[6] = { 0, };
	int MIN = 1 << 15;
	DFS(0, &MIN, table, Tlist, visit, K, N, M);	//DFS를 호출합니다
	printf("%d", MIN);
}

void DFS(int n, int* MIN, int(*table)[51], T Tlist[], int visit[], int& K, int& N, int& M) {

	if (n == K) {	//만약 순열이 완성되었다면
		for (int i = 1; i <= N; ++i) {	//각 행의 합을 구한 후
			int sum = 0;
			for (int j = 1; j <= M; ++j) {
				sum += table[i][j];
			}
			if (sum < *MIN) *MIN = sum;	//최소값이라면 갱신합니다.
		}
	}
	else {						
		for (int i = 0; i < K; ++i) {
			if (!visit[i]) {		//i가 고르지 않았던 인덱스라면
				visit[i] = 1;		//i를 방문처리하고
				turn(table, Tlist[i], 1);	//i번째 회전정보를 적용합니다.
				DFS(n + 1, MIN, table, Tlist, visit, K, N, M);	//DFS
				turn(table, Tlist[i], -1);	//돌아왔다면 다시 역으로 회전합니다.
				visit[i] = 0;	//방문 처리도 철회합니다.
			}
		}
	}
}

void turn(int(*table)[51], T Ta, int dir) {	//dir이 1:시계회전 -1:반시계회전

	for (int d = 1; d <= Ta.D; ++d) {
		int i = Ta.I - d, j = Ta.J - d*dir, c = 2 * d;
		int temp = table[i][j];
		while (c--) {
			table[i][j] = table[i + 1][j];
			++i;
		}
		c = 2 * d;
		while (c--) {
			table[i][j] = table[i][j + dir];
			j += dir;
		}
		c = 2 * d;
		while (c--) {
			table[i][j] = table[i - 1][j];
			--i;
		}
		c = 2 * d - 1;
		while (c--) {
			table[i][j] = table[i][j - dir];
			j -= dir;
		}
		table[i][j] = temp;
	}
}
