# 220929_TIL

유튜브 동빈나 - C언어 기초 프로그래밍 강좌 보면서 기초 문법 익히고 있습니다.

## 1. BOJ_2557. Hello World

```cpp
#include <stdio.h>

// main이라는 함수를 실행하여 int값을 반환할 것이다.
int main(void)
{
  printf("Hello World!");
  return 0; // 반환할 int 값은 0이다.
}
```

C언어는 python과 다르게 처음부터 print와 같은 내장함수를 사용할 수 없다.

printf, scanf 등 기본 함수를 사용하기 위해서는 라이브러리를 추가해야 한다.

이 문제는 간단한 입/출력 함수들을 제공하는 <stdio.h>를 추가해서 printf 함수를 사용할 수 있었다.

void는 함수가 처리할 값들을 받아온다고 한다.

int main(void) → return 0; 구조는 하나의 약속과도 같아서 형태에 익숙해져야 한다.

## 2. BOJ_10869. 사칙연산

```cpp
#include <stdio.h>

int main(void)
{
  int A, B;
  scanf("%d %d", &A, &B);
  printf("%d\n", A + B);
  printf("%d\n", A - B);
  printf("%d\n", A * B);
  printf("%d\n", A / B);
  printf("%d\n", A % B);
  return 0;
}
```

이 문제에서는 python의 input에 해당하는 scanf 사용법과 변수 정의, 연산 방법을 익힐 수 있었다.

가장 눈에 띄는 점은 input을 받기 전에 A, B의 자료형을 먼저 지정해줘야 한다는 점과,

입/출력 시 %d 및 %d\n이 사용되는 점이다.

int는 %d, char은 %c를 사용하는 것으로 보아 자료형에 따른 문법이 있는 것 같은데 정리해야겠다.

그리고 파이썬에서 기본적으로 print에 붙어있는 \n(줄바꿈)을 C 언어는 출력시에 유의해야 한다.