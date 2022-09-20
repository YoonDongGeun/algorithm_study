#include <iostream>
#include <queue>

using namespace std;

struct ax {
	int I;
	int J;
};


char board[101][101];
char board_[101];
bool visit[101][101];
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
ax sub,dsub;
queue <ax> Q;
int N, i, j, d, cnt=0,cnt2=0;
bool neer,is_RG;

void rgb(char C) {

	while (!Q.empty()) {
		

		sub = Q.front();

		Q.pop();

		for (d = 0; d < 4; ++d) {
			dsub = { sub.I + di[d],sub.J + dj[d] };
			
			
			if (dsub.I < 0 || dsub.I >= N || dsub.J < 0 || dsub.J >= N) continue;
			if (is_RG && visit[dsub.I][dsub.J] && board[dsub.I][dsub.J] != 'B' && board[dsub.I][dsub.J]!=C) {
				neer = 1;
				is_RG = 0;
			}
			if (!visit[dsub.I][dsub.J] && board[dsub.I][dsub.J] == C) {
				
				visit[dsub.I][dsub.J] = 1;
				Q.push(dsub);
			}
			

		}
	}
	++cnt;
}


int main() {
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%s", &board_);
		for (j = 0; j < N; ++j) {
			board[i][j] = board_[j];
		}
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (!visit[i][j]) {
				if (board[i][j]!='B') is_RG= 1;
				else is_RG = 0;
				Q.push({ i,j });
				visit[i][j] = 1;
				rgb(board[i][j]);
				if (neer) { neer = 0; }
				else ++cnt2;
			}
		}
	}
	printf("%d %d", cnt, cnt2);

}