#include <stdio.h>

int main(void)
{
	int N, i, j;
	scanf("%d", &N);
	for(i = 1; i <= N; i++)
	{
		for(j = N - i - 1; j >= 0; j--)
		{
			printf(" ");
		}
		for(j = 0; j < i; j++)
		{
			printf("*");
		}
		for(j = 0; j < i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
