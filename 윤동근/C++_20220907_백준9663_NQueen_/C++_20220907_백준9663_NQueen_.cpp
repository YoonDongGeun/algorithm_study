#include <iostream>
#include <cstdlib>
using namespace std;
int cnt = 0;
int N, S;
int *n = new int[15]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int *STACK = new int[15]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
/*int n[arraymax] = { 0,0,2,0,0,0,0,0,0,0,0,0,0,0,0 };
int STACK[arraymax] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};*/
int* k = STACK;
int* t = n;

void search()
{
	k++;
	S = 1;
	int W = k - STACK;

	if (W == N)
	{
		cnt++;
		k--;
		return;
	}
	else
	{
		for (int nx = 0; nx < N; nx++)
		{
			t = n + nx; /*검사할 x값 0~ nx*/
			S = 1;
			if (*t == 1)	/*만약 이미 x값이 사용했으면 넘어가기*/
			{
				continue;
			}

			for (int j = 0; j < W; j++) /*스택에 담긴 x값들 검사*/
			{
				if (abs(nx - STACK[j]) == abs(W - j)) /* (사용안된 검사할 x값 - 스택에 담긴[j인덱스] x값) == (y좌표 - 스택의 요소의 y좌표) */
				{
					S = 0;
					break;
				}
			}

			if (S == 1)
			{
				*t = 1;
				*k = nx;
				search();
				t = n + nx;
				*t = 0;
			}
		}
	}
	k--;
	return;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		*STACK = i;
		*(n + i) = 1;
		search();
		*(n + i) = 0;
	}

	cout << cnt << "\n";
	
	delete[] n;
	delete[] STACK;
	return 0;
}