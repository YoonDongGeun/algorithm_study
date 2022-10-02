# 221002_TIL

## 입출력

```cpp
#include <stdio.h>

int main(void)
{
	char o;
	int x, y;
	while(1)
	{
		printf("수식을 입력하세요 : ");
		scanf("%d %c %d", &x, &o, &y);
		if(o == '+')
		{
			printf("%d %c %d = %d\n", x, o, y, x + y);
		 } 
		else if(o == '-')
		{
			printf("%d %c %d = %d\n", x, o, y, x - y);
		 } 
		else if(o == '*')
		{
			printf("%d %c %d = %d\n", x, o, y, x * y);
		 } 
		else if(o == '/')
		{
			printf("%d %c %d = %d\n", x, o, y, x / y);
		 } 
		else
		{
			printf("입력이 잘못되었습니다.\n");
		}
		getchar(); // 버퍼 처리
		printf("프로그램을 종료하시겠습니까? (y/n)");
		scanf("%c", &o);
		if(o == 'n' || o == 'N')
		{
			continue;
		}
		else if(o == 'y' || o == 'Y')
		{
			break;
		}
		else
		{
			printf("입력이 잘못되었습니다.\n");
		}
	}
	return 0;
}
```

위 코드는 입력에 따라 사칙연산을 수행한다. 한 번의 연산 후 프로그램을 종료할 것인지 여부를 묻도록 작성하였다. 그러나 실행하면 가장 밑의 (”입력이 잘못되었습니다.) 문구가 덩달아 출력되는 것을 볼 수 있다. 이는 우리가 엔터를 칠 때 그것을 입력으로 인식해서 생기는 오류이다.

C언어에서는 이를 해결하기 위해 getchar()라는 버퍼 처리를 해주어야 한다.

## 사용자 정의 함수

```cpp
#include <stdio.h>

// global 변수 선언
int hour;
int minute;
int minuteAdd;

// return값이 필요없는 함수에는 void를 사용 
void counter()
{
	minute += minuteAdd;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;
 }

int main(void)
{
	printf("시를 입력하세요 : ");
	scanf("%d", &hour);
	printf("분을 입력하세요 : ");
	scanf("%d", &minute);
	printf("더할 분을 입력하세요 : ");
	scanf("%d", &minuteAdd);
	counter();
	printf("더해진 시간은 %d시 %d분 입니다.\n", hour, minute);
	return 0;
}

```

적절한 함수 사용은 가독성을 좋게 한다.