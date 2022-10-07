# 221005_TIL

## 포인터

C 언어의 가장 큰 특징 및 장점. 특정 데이터가 저장된 **메모리의 주소를 저장**하는 변수이다.

```cpp
int x = 70;
int *y = &x; // 라고 할 때
x의 주소값이 예를 들면 00AA00BB라고 하자.
y가 그 주소값 00AA00BB를 담고,
*y가 비로소 70을 의미한다.

x = *y,
&x = y가 성립한다.
```

```cpp
#include <stdio.h>

// 두 변수의 값을 서로 변환하는 포인터 함수 
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	int x = 1;
	int y = 2;
	swap(&x, &y);
	printf("x = %d\ny = %d\n", x, y);
	return 0;
 }
```

이게 굳이 포인터가 아니어도 작동하지 않나? 싶지만 *을 빼고 동작시켰을 경우,

x와 y 값은 swap 함수 안에서만 바뀌기 때문에 main 함수에서는 영향을 주지 못한다.

```cpp
#include <stdio.h>

// 포인터 변수의 값을 바꿔보기 
int main(void)
{
	int i = 10;
	int *p;
	p = &i;
	pritnf("i = %d\n", i); // i = 10
	*p = 20;
	printf("i = %d\n", i); // i = 20
	return 0;
 }
```

## 문자열

배열은 내부적으로 포인터와 매우 유사한 원리를 사용하는데, 문자열 또한 이 배열 구조를 사용하여 저장한다.

```cpp
#include <stdio.h>

int main(void)
{
	char input[1001];
	gets(input); // 입력한 값이 엔터를 치면 input이라는 char에 들어간다 
	int count = 0;
	while(input[count] != '\0')
	{
		count++;
	}
	printf("입력한 문자열의 길이는 %d입니다.", count);
	printf("입력한 문자열 : %s", input); // 저장된 string(문자열)을 출력할 수 있다. 
	return 0;
 }

#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[5] = "Love";
	printf("문자열의 길이 : %d\n", strlen(input)); // 문자열의 길이를 읽는 함수
	return 0;
 }

int main(void)
{
	char inputOne[5] = "A";
	char inputTwo[5] = "B";
	printf("문자열 비교 : %d\n", strcmp(inputOne, inputTwo)); // 문자열 순서 읽는 함수(사전순)
	return 0;
 }

int main(void)
{
	char input[10] = "I Love You";
	char result[5] = "Love";
	strcpy(result, input) // 길이에 상관 없이 문자열을 복사하는 함수 
	printf("문자열 복사 : %s\n", result);
	return 0;
 }
```