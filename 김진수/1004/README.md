# 221004_TIL

## 배열

```cpp
#include <stdio.h>
#include <limits.h>
#define NUMBER 5

// 5개의 정수 중에서 최댓값과 최솟값의 위치를 출력하기 

int main(void)
{
    int i, max, min, index;
    int array[NUMBER]; // 이 부분이 배열을 정의하는 부분! 
    max = 0;
    index = 0;
    for(i = 0; i < NUMBER; i++)
    {
        scanf("%d", &array[i]);
        if(max < array[i])
        {
            max = array[i];
            index = i;
        }
    }
    printf("가장 큰 값은 %d입니다. 그리고 %d번째에 있습니다.\n", max, index+1);

    min = INT_MAX;
    for(i = 0; i < NUMBER; i++)
    {
        scanf("%d", &array[i]);
        if(min > array[i])
        {
            min = array[i];
            index = i;
        }
    }
    printf("가장 작은 값은 %d입니다. 그리고 %d번째에 있습니다.\n", min, index+1);
    return 0;
}
```

## 다차원 배열

```cpp
#include <stdio.h>

// 구구단을 이차원 배열로 출력하기 
int main(void)
{
    int i, j;
    int gugudan[10][10];
    for(i = 1; i <= 9; i++)
    {
        printf("\n[ %d단 ]\n\n", i);
        for(j = 1; j <= 9; j++)
        {
            gugudan[i][j] = i * j;
            printf("%d X %d = %d\n", i, j, gugudan[i][j]);
        }
    }
}

#include <stdio.h>

int main(void)
{
    int score[5][2];
    int total[2] = { 0, }; // total이라는 배열을 정의하면서 각 행에 0을 넣는다.
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("%d번 학생의 수학, 영어 점수 : ", i + 1);
        scanf("%d %d", &score[i][0], &score[i][1]);
     } 

    for(i = 0; i < 5; i++)
    {
        total[0] += score[i][0];
        total[1] += score[i][1];
    }

    printf("\n\n5명의 수학 점수 합계 : %d\n", total[0]);
    printf("5명의 영어 점수 합계 : %d\n", total[1]);
    return 0;
 }
```

배열과 이차원 배열을 선언하고 활용하는 문법을 배웠다. 이제 python으로 풀던 많은 배열 문제들을 C언어로 구현해 볼 수 있겠다.