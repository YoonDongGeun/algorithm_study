#include <stdio.h>

int main(void)
{
	int num[9][9];
	int i, j, max, idxI, idxJ;
	max = 0;
	idxI = 10;
	idxJ = 10;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			scanf("%d", &num[i][j]);
			if(max <= num[i][j])
			{
				max = num[i][j];
				idxI = i+1;
				idxJ = j+1;
			}
		}
	 } 
	printf("%d\n", max);
	printf("%d %d\n", idxI, idxJ);
	return 0;
 }
