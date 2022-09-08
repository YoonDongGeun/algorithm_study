#include <iostream>
using namespace std;
int Sudoku[9][9];
int k, cnt, cnt2;
void check(int, int);
void search(int);

void search(int q)
{
	int b = 0;
	for (int i = q; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(Sudoku[i][j] == 0)
			{
				cnt2++;
				check(i, j);
				cnt2--;
				b = 1;
				break;
			}
			
		}
		if (b == 1)
		{
			break;
		}
	}
}

void check(int e, int r)
{

	for (int ii = 1; ii < 10; ii++)
	{
		int ch = 0;
		for (int iii = 0; iii < 9; iii++)
		{
			if (Sudoku[e][iii] == ii)
			{
				ch = 1;
				break;
			}
			if (Sudoku[iii][r] == ii)
			{
				ch = 1;
				break;
			}
		}
		if (ch == 0)
		{
			for (int xx = 0; xx < 3; xx++)
			{
				for (int yy = 0; yy < 3; yy++)
				{
					if (Sudoku[(e / 3)*3 + xx][(r / 3)*3 + yy] == ii)
					{
						ch = 1;
						break;
					}
				}
				if (ch == 1)
				{
					break;
				}
			}
		}
		if (ch == 0)
		{
			Sudoku[e][r] = ii;
			if (cnt2 == cnt)
			{
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						cout << Sudoku[i][j] << ' ';

					}
					cout << '\n';
				}

				return;
			}
			search(e);
			Sudoku[e][r] = 0;
		}
	}

}

int main()
{
	cnt = 0;
	cnt2 = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> k;
			Sudoku[i][j] = k;
			if(k == 0)
			{
				cnt++;
			}
		}
	}
	search(0);

	return 0;
}