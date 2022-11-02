#include <iostream>

//------------
#define F(x,s,e) for(int x=s;x<=e;++x)

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	int N = board.size();
	int M = board[0].size();
	vector<vector<int>> sub_board(N+1, vector<int>(M+1, 0));

	for (int c = 0; c < skill.size(); ++c) {
		int d;
		if (skill[c][0] == 1) d = -skill[c][5];
		else d = skill[c][5];
		sub_board[skill[c][1]][skill[c][2]] += d;
		sub_board[skill[c][3]+1][skill[c][2]] -= d;
		sub_board[skill[c][1]][skill[c][4]+1] -= d;
		sub_board[skill[c][3]+1][skill[c][4]+1] += d;
	}

	F(i, 0, N) {
		F(j, 0, M) printf("%d ", sub_board[i][j]);
		printf("\n");
	}
	printf("\n");


	F(i, 0, N) {
		F(j, 1, M) {
			sub_board[i][j] += sub_board[i][j - 1];
		}
	}

	F(i, 0, N) {
		F(j, 0, M) printf("%d ", sub_board[i][j]);
		printf("\n");
	}
	printf("\n");


	F(j, 0, M) {
		F(i, 1, N) {
			sub_board[i][j] += sub_board[i-1][j];
		}
	}


	F(i, 0, N) {
		F(j, 0, M) printf("%d ", sub_board[i][j]);
		printf("\n");
	}
	printf("\n");



	F(i,0, N-1) F(j, 0,M-1) if (board[i][j]+ sub_board[i][j] > 1) ++answer;
	return answer;
}


//--------------

int main() {
	printf("%d", solution({ {5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5} }, { {1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1} }));
}