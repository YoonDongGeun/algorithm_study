#include <iostream>
#include <vector>
using namespace std;

/// 시간초과 원인 : 예제만 보고 문제 풀지 말기!!
/// 전체 경우의 수 넣어보면서 재귀, 백트래킹


int sudoku[10][10];
bool flag = 0;
vector <pair<int, int>> zero;

// 세로 같은 수 있는지 파악하기
int row(int y, int x, int k)
{
	for (int i = 0; i < 9; i++)
		if (sudoku[i][x] == k) return 1;
	return 0;
}

// 가로 같은 수 있는지 파악하기
int col(int y, int x, int k)
{
	for (int i = 0; i < 9; i++)
		if (sudoku[y][i] == k) return 1;
	return 0;
}

// 정사각형 같은 수 있는지 파악하기
int square(int y, int x, int k)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (sudoku[(y / 3) * 3 + i][(x / 3) * 3 + j] == k) return 1;
	return 0;
}

// 숫자 넣어보기
void board(int cnt)
{
	if (cnt == zero.size())
	{
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
				cout << sudoku[y][x] << " ";
			cout << "\n";
		}
		flag = 1;
		return;
	}
	int y = zero[cnt].first;
	int x = zero[cnt].second;
	for (int j = 1; j <= 9; j++)
	{
		if (row(y, x, j) == 1 || col(y, x, j) == 1 || square(y, x, j) == 1) continue;
		sudoku[y][x] = j;
		board(cnt + 1);
		if (flag == 1) return;
		sudoku[y][x] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
		{
			cin >> sudoku[y][x];
			if (sudoku[y][x] == 0)
				zero.push_back({ y,x });
		}
	board(0);
}