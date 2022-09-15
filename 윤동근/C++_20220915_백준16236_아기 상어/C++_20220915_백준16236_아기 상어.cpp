#include <iostream>
using namespace std;

int water[21][21] = { 0 };
int movex[4] = { 0, -1, 1, 0 };
int movey[4] = {-1, 0, 0, 1};
int sharkx, sharky;
int shark = 2;
int cnt = 0;
int cnt2 = 0;
int stackx[500000];
int stacky[500000];
int *x = &stackx[0];
int *y = &stacky[0];
int *nx = &stackx[0];
int *ny = &stacky[0];
int c;
int min2;
int flag;

struct food {
	int x;
	int y;
	int size;
};
food foods[400] = { {500,500,500}, };
food *f = &foods[0];
food *temp;

void search(int N)
{
	c = 1;
	int visited[20][20] = { 0, };
	x = nx;
	y = ny;
	*x = sharkx;
	*y = sharky;
	visited[*y][*x] = 1;
	flag = 1;
	while(flag==1)
	{
		flag = 0; /*nx-x+1*/
		int p = 0;
		for (int w = 0; w < c; w++)
		{
			for (int j = 0; j < 4; j++)
			{
				int yy = *y + movey[j];
				int xx = *x + movex[j];
				if (0 <= xx && xx < N && 0 <= yy && yy< N)
				{
					if (water[yy][xx] <= shark && visited[yy][xx] == 0)
					{
						p++;
						nx++;
						ny++;
						*nx = xx;
						*ny = yy;
						visited[yy][xx] = visited[*y][*x] + 1;
						flag = 1;
					}
				}
			}
			x++;
			y++;
		}
		c = p;

	}

	
	min2 = 410;

	temp = foods;
	for (int i = 0; i < f - foods; i++)
	{
		if (visited[foods[i].y][foods[i].x] > 1 && foods[i].size < shark)
		{
			
			if (min2 >= visited[foods[i].y][foods[i].x] - 1)
			{
				if (min2 == visited[foods[i].y][foods[i].x] - 1)
				{
					if ((*temp).y > foods[i].y)
					{
						temp = &foods[i];
					}
					else if ((*temp).y == foods[i].y)
					{
						if((*temp).x > foods[i].x)
							temp = &foods[i];
					}

				}
				else
				{
					min2 = visited[foods[i].y][foods[i].x] - 1;
					temp = &foods[i];

				}
			}
		}
	}
	if (min2 != 410)
	{
		cnt++;
		if (shark == cnt)
		{
			shark++;
			cnt = 0;
		}
		cnt2 += visited[(*temp).y][(*temp).x] - 1;
		sharkx = (*temp).x;
		sharky = (*temp).y;
		(*temp).size = 100;
		search(N);
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> water[i][j];
			if (water[i][j] != 0)
			{
				if (water[i][j] != 9)
				{
					(*f).x = j;
					(*f).y = i;
					(*f).size = water[i][j];
					f++;
					
				}
				else
				{
					sharky = i;
					sharkx = j;
					water[i][j] = 0;
				}
			}
		}
	}
	search(N);
	cout << cnt2;
	return 0;
}