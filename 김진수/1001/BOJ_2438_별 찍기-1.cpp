#include <stdio.h>

int main(void)
{
	int N, n, i;
 	scanf("%d", &N);
	for(n = 0; n < N; n++)
	{
		for(i = N; i > n; i--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
