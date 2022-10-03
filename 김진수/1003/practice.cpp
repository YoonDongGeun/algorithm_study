#include <stdio.h>

// 재귀함수 사 
void print(int count)
{
	if(count == 0)
	{
		return;
	}
	else
	{
		printf("문자열을 출력합니다.\n");
		print(count - 1);
	}
}


int main(void)
{
	int number;
	printf("문자열을 몇 개 출력할까요? ");
	scanf("%d", &number);
	print(number);
	return 0; 
}
