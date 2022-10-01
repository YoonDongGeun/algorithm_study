# 221001 TIL

<img title="" src="README_assets/8f45c78d547af90a146d0a1317b155e8cc7cc618.png" alt="loading-ag-126">

## 자료형

### char - 문자형 → ※ string 아님

### int - 정수 , float, double - 실수

### void - 없음

이전에 사칙 연산을 하면서 맛본 것처럼 C언어에는 훨씬 다양한 자료형이 있다. 흔히 말하는 자료형은 좌측 Primitive인 경우가 많으므로 char, int, float, double, void 먼저 알고 넘어가자.

```cpp
//실수형
#include <stdio.h>
#define MONTHS 12 // MONTHS 상수를 정의해주는 줄

int main(void)
{
    double monthSalary = 1000.5; // 실수형 double
    printf("$ %.2f", monthSalary * MONTHS);
    return 0;
}

//문자형, 정수형
#include <stdio.h>

int main(void)
{
    char x = 'A';
    // char x = 65;
    // int x = 65;
    // ※ C언어에서는 아스키 코드를 활용하기 때문에 위 3가지 모두 같은 결과가 나온다.
    printf("%c", x)
    // printf("%d", x)
    // 마찬가지로 출력을 정수형으로 바꾸면 3가지 모두 같은 결과 65가 나온다.
    return 0;
}

//진수 변환
#include <stdio.h>

int main(void)
{
    int x = 100;
    printf("10진수로 출력 : %d\n", x);
    printf("8진수로 출력 : %o\n", x);
    printf("16진수로 출력 : %x\n", x);
    return 0;
}
```

## 연산자

```cpp
// 사칙연산
#include <stdio.h>

int main(void)
{
    int x = 0;
    printf("현재의 x는 %d입니다.\n", x); // x = 0
    x++;
    printf("현재의 x는 %d입니다.\n", x); // x = 1
    printf("현재의 x는 %d입니다.\n", x--); // x = 1. 출력 후 x-1을 실시 
    printf("현재의 x는 %d입니다.\n", x);  // x = 0
    printf("현재의 x는 %d입니다.\n", --x); // x = -1. x-1 후 출력
    x += 50;
    x -= 50;
    x *= 50;
    x /= 50;
    x %= 50; // 이 문법은 python과 동일
    return 0;
}

// 값 비교
#include <stdio.h>

int main(void)
{
    int x = 50, y = 30;
    printf("x가 y와 같은가 ? %d\n", x == y); // 연산에 대한 값이 0 또는 1로 표시
    printf("x가 y와 다른가 ? %d\n", x != y);
    printf("x가 y보다 큰가 ? %d\n", x > y);
    printf("x가 y보다 작은가 ? %d\n", x < y);
    printf("x에 y값을 넣으면 ? %d\n", x = y); // -> 30이 출력됨.
    printf("x가 y보다 크고 y는 40 미만입니까 ? %d\n", (x > y) && (y < 40));
    printf("x가 y보다 작거나 혹은 y가 30입니까 ? %d\n", (x > y) || (y == 30));
    return 0;
}

// 조건 연산자
#include <stdio.h>

int main(void)
{
    int x = -50, y = 30;
    int absoluteX = (x > 0) ? x : -x; // x가 양수인 경우 x, 아닐 경우 -x가 된다.
    int max = (x > y) ? x : y;
    int min = (x < y) ? x : y;
    printf("x의 절대값은 %d입니다.\n", absoluteX);
    printf("x와 y중에서 최댓값은 %d입니다.\n", max); 
    printf("x와 y중에서 최솟값은 %d입니다.\n", min);
    return 0;
}

#include <stdio.h>
#include <math.h> // pow(), abs() 함수를 포함하는 라이브러리

int main(void)
{
    double x = pow(2.0, 20.0); // 2의 20승 
    printf("2의 20제곱은 %.0f입니다.\n", x);
    printf("2의 20제곱은 %.2f입니다.\n", x); // 소수점 2째자리까지 출력
    return 0;
 }
```

## 조건문과 반복문

```cpp
//if 조건문
#include <stdio.h>

int main(void)
{
    int x = -150;
    if(x < 0)
    {
        x = -x;
    }
    printf("x의 절댓값은 %d입니다.\n", x);
    return 0;
 }

int main(void)
{
    int score = 85;
    if(score >= 90)
    {
        printf("당신의 학점은 A입니다.\n");
    }
    else if(score >= 80)
    {
        printf("당신의 학점은 B입니다.\n");
    }
    else if(score >= 70)
    {
        printf("당신의 학점은 C입니다.\n");
    }
    else
    {
        printf("당신의 학점은 F입니다.\n");
    }
    return 0;
 }

int main(void)
{
    int year = 2022;
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("%d년은 윤년입니다.\n", year);
    }
    else
    {
        printf("%d년은 윤년이 아닙니다.\n", year);
    }
    return 0;
}

// while 반복문
#include <stdio.h>

int main(void)
{
    int i = 1, sum = 0;
    while(i <= 1000)
    {
        sum = sum + i;
        i++;
    }
    printf("1부터 1000까지의 합은 %d입니다.\n", sum);
    return 0;
}

// for 반복문으로 별찍기
#include <stdio.h>
#define N 10

int main(void)
{
    int i, j;
    for(i = 0; i < N; i++) // i를 0으로 초기화, i가 < N인 동안, i++의 연산 반복
    {
        for(j = 0; j < N; j++)
        {
            printf("★");
        }
        printf("\n");
    }
    return 0;
}

// 피라미드 별찍기
int main(void)
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = N - i - 1; j > 0; j--)
        {
            printf("  ");
        }
        for(j = 0; j < i; j++)
        {
            printf("★");
        }
        for(j = 0; j < i - 1; j++)
        {
            printf("★");
        }
        printf("\n");
    }
    return 0;
}
```