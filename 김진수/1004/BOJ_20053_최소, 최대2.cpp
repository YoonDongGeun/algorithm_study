#include <stdio.h>

int main(void)
{
	int T, tc;
	int N, i, max, min;
	scanf("%d", &T);
	for(tc=0; tc < T; tc++)
	{
		scanf("%d", &N);
		int arr[N];
		max = -1000000;
		min = 1000000;
		for(i=0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			if(max <= arr[i])
			{
				max = arr[i];
			}
			
			if(min >= arr[i])
			{
				min = arr[i];
			}
		}
		printf("%d %d\n", min, max);
	}
	return 0;
 }
