# 221009_TIL

동적 메모리의 활용

동적 메모리는 포인터 변수에 메모리 주소를 할당해서 사용되게끔 하는 방법이다.

포인터와 배열이 결합된 원리라고 생각하면 간단하다.

```cpp
// 1. 기본형 예제
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *pi; // Pointer Integer
	pi = (int *)malloc(sizeof(int)); // malloc = 메모리를 할당해라.
	if(pi == NULL) // 동적 메모리 할당에 실패했다면
	{
		printf("동적 메모리 할당에 실패했습니다.\n")
		exit(1);
	} 
	*pi = 100;
	printf("d\n", *pi);
	// 동적 메모리 사용 이후에는 반드시 해당 메모리를 반환한다.
	free(pi); 
	return 0;
}

// 2. 동적 메모리로 알파벳 출력하기
int main(void)
{
	char *pc = NULL;
	int i = 0;
	pc = (char *)malloc(100 * sizeof(char));
	if(pc == NULL)
	{
		printf("동적 메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	// pc가 가르키는 포인터를 1씩 증가시키며 알파벳 소문자를 삽입한다. 
	for(i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;
	}
	// 아스키 코드에서 0은 NULL이므로 문자열의 종료를 의미한다. 
	*(pc + i) = 0;
	
	printf("%s\n", pc);
	free(pc);
	return 0;
}

// 3. 동적 메모리로 정수 5개 처리하기
int main(void)
{
	int *pi, i;
	pi = (int *)malloc(5 * sizeof(int));
	if(pi == NULL)
	{
		printf("동적 메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	pi[0] = 100;
	pi[1] = 200;
	pi[2] = 300;
	pi[3] = 400;
	pi[4] = 500;
	for(i = 0; i < 5; i++)
	{
		printf("%d\n", *(pi + i));
	}
	free(pi);
	return 0;
}
```

```cpp
#include <stdio.h>
#include <stdlib.h>

// 1. 구조체 동적 메모리 할당 
struct Book
{
	int number;
	char title[100];
}

void showBook(struct Book *p, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("번호 %d : %s\n", (p + i)->number, (p + i)->title);
	}
	
	
	
}
int main(void)
{
	struct Book *p;
	p = (struct Book *)malloc(2 * sizeof(struct Book));
	if(p == NULL)
	{
		printf("동적 메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	
	p->number = 1;
	strcpy(p->title, "C Programming");
	
	(p + 1)->number = 2;
	strcpy((p+1)->title, "Data Structure");
	
	return 0;
}

// 2. 2차원 동적 메모리 할당
int main(void)
{
	int i, x, y;
	int** pptr = (int**)malloc(sizeof(int*) * 8);
	for(i = 0; i < 8; i++)
	{
		*(pptr + i) = (int *)malloc(sizeof(int) * 6);
	}
	
	for(y = 0; y < 8; y++)
	{
		for(x = 0; x < 6; x++)
		{
			*(*(pptr + y) + x) = 6 * y + x;
		}
	}
	
	for(y = 0; y < 8; y++)
	{
		for(x = 0; x < 6; x++)
		{
			printf("%3d", *(*(pptr + y) + x));
		}
		printf("\n");
	}
	
	for(y = 0; y < 8; y++)
	{
		free(*(pptr + y));
	}
	
	return 0;
}
```