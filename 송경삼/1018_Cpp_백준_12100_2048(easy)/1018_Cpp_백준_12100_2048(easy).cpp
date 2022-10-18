#include <iostream>
#define F(x,s,e) for(int x=s;x<=e;++x)
#define F_(x,s,e) for(int x=e;x>=s;--x)

int N, MAX=0;	

void dfs(int (*board)[22],int n) {
	if (n == 5) return;

	int temp_board[22][22];
	bool visit[22][22] = { 0, };	//한번에 두블럭 초과로 합쳐지지 않도록 방문처리 배열입니다.

	F(i, 0, N + 1) F(j, 0, N + 1) temp_board[i][j] = board[i][j];//현재 보드 정보를 기록해둡니다.

	//첫번째 남쪽으로 이동할 경우
	F_(i, 1, N) {
		F(j, 1, N) {
			if (board[i][j]) {
				int ai = i;
				while (!board[ai + 1][j]) ++ai;

				if (!visit[ai+1][j] && board[ai + 1][j] == board[i][j]) {
					board[ai + 1][j] += board[i][j];
					board[i][j] = 0;
					visit[ai + 1][j] = 1;
					if (board[ai + 1][j] > MAX) MAX = board[ai + 1][j];
				}
				else if (ai == i)continue;
				else {
					board[ai][j] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}

	dfs(board, n + 1);

	//돌아왔다면 되돌려줍니다
	F(i, 0, N + 1) F(j, 0, N + 1) {
		board[i][j] = temp_board[i][j];
		visit[i][j] = 0;
	}


	//두번째 동쪽으로 이동할 경우
	F_(j, 1, N) {
		F(i, 1, N) {
			if (board[i][j]) {
				int aj = j;
				while (!board[i][aj + 1]) ++aj;
				if (!visit[i][aj + 1] && board[i][aj + 1] == board[i][j]) {
					board[i][aj + 1] += board[i][j];
					visit[i][aj + 1] = 1;
					board[i][j] = 0;
					if (board[i][aj + 1] > MAX) MAX = board[i][aj + 1];
				}
				else if (aj == j)continue;
				else {
					board[i][aj] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}
	dfs(board, n + 1);
	//돌아왔다면 되돌려줍니다
	F(i, 0, N + 1) F(j, 0, N + 1) {
		board[i][j] = temp_board[i][j];
		visit[i][j] = 0;
	}

	//세번째 남쪽으로 이동할 경우

	F(i, 1, N) {
		F(j, 1, N) {
			if (board[i][j]) {
				int ai = i;
				while (!board[ai - 1][j]) --ai;
				if ( !visit[ai - 1][j] && board[ai - 1][j] == board[i][j]) {
					board[ai - 1][j] += board[i][j];
					visit[ai - 1][j] = 1;
					board[i][j] = 0;
					if (board[ai - 1][j] > MAX) MAX = board[ai - 1][j];

				}
				else if (ai == i)continue;
				else {
					board[ai][j] = board[i][j];
					board[i][j] = 0;
				}
			}

		}
	}

	dfs(board, n + 1);
	//돌아왔다면 되돌려줍니다

	F(i, 0, N + 1) F(j, 0, N + 1) {
		board[i][j] = temp_board[i][j];
		visit[i][j] = 0;
	}


	//네번째 서쪽으로 이동할 경우
	F(j, 1, N) {
		F(i, 1, N) {
			if (board[i][j]) {
				int aj = j;
				while (!board[i][aj - 1]) --aj;
				if (!visit[i][aj - 1] && board[i][aj - 1] == board[i][j]) {
					board[i][aj - 1] += board[i][j];
					visit[i][aj - 1] = 1;
					board[i][j] = 0;
					if (board[i][aj - 1] > MAX) MAX = board[i][aj - 1];
				}
				else if (aj == j)continue;
				else {
					board[i][aj] = board[i][j];
					board[i][j] = 0;
				}
			}
		}
	}

	dfs(board, n + 1);
	//돌아왔다면 되돌려줍니다
	F(i, 0, N + 1) F(j, 0, N + 1) {
		board[i][j] = temp_board[i][j];
		visit[i][j] = 0;
	}

}


int main() {
	scanf("%d", &N);
	int fisrt_board[22][22] = { 0, };
	F(i, 0, N + 1) {
		F(j, 0, N + 1) {
			if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
				fisrt_board[i][j] = -1;
			}
			else {
				scanf("%d", &fisrt_board[i][j]);
				if (fisrt_board[i][j] > MAX) MAX = fisrt_board[i][j];
			}
		}
	}
	dfs(fisrt_board, 0);
	printf("%d", MAX);
}