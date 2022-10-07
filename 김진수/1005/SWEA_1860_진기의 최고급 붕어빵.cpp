#include <stdio.h>
#include <string.h> // char 사용을 위한 라이브러리 
#include <algorithm> // sort 사용을 위한 라이브러리 
using namespace std; // std 생략을 위한 namespace 

char result2[11] = "Impossible";

int main(void)
{
	int tc, T;
	scanf("%d", &T);
	for(tc = 0; tc < T; tc++)
	{
		int N, M, K, i;
		scanf("%d %d %d", &N, &M, &K);
		char result[9] = "Possible";
		int arr[N];
		for(i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+N);
		for(i = 0; i < N; i++)
		{
			if(arr[i]/M*K < i+1)
			{
				strcpy(result, result2); // for문을 돌면서 조건에 맞지 않는다면 result를 Impossible로 바꿈 
				break;
			}
		}
		printf("#%d %s\n", tc+1, result);
	}
	return 0;
 } 
