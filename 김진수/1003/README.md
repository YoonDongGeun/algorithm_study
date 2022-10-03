# 221003_TIL

## 반복 함수와 재귀 함수

```cpp
#include <stdio.h>

// 반복함수로 숫자 피라미드 만들기
int print(int a)
{
	int i, j;
	for(i = 0; i < a; i++)
	{
		for(j = 0; j <= i; j++)
		{
			printf("%d ", j+1);
		}
		printf("\n");
	}
}

int main(void)
{
	int a;
	scanf("%d", &a);
	print(a);
	return 0;
}

#include <stdio.h>

// 재귀함수로 조합의 개수 찾기

int nCr(int n, int r)
{
	if(r == 0 || r == n)
	{
		return 1;
	}
	else
	{
		return nCr(n - 1, r - 1) + nCr(n - 1, r);
	}
}

int main(void)
{
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d", nCr(n, r));
	return 0;
}
```

반복문과 재귀문도 문법상 크게 다르지 않아 금방 배울 수 있었다.

배열을 배우고 나면 재귀를 사용해서 조합 하