#include <stdio.h>

// 특정 금액을 받아 가장 적은 거스름 화폐의 개수를 구하는 함수 
int smallest(int number)
{
	int count = 0;
	while(number >= 500)
	{
		number -= 500;
		count++;
	}
	while(number >= 100)
	{
		number -= 100;
		count++;
	}
	while(number >= 50)
	{
		number -= 50;
		count++;
	}
	while(number >= 10)
	{
		number -= 10;
		count++;
	}
	while(number >= 5)
	{
		number -= 5;
		count++;
	}
	while(number >= 1)
	{
		number -= 1;
		count++;
	}
	return count;
}

int main(void)
{
	int number, change;
	scanf("%d", &number);
	change = 1000 - number;
	printf("%d", smallest(change));
	return 0;
}
