#include <stdio.h>

int min(int a, int b, int c, int d)
{
	if(a <= b && a <= c && a <= d)
	return a;
	
	else if(b <= a && b <= c && b <= d)
	return b;
	
	else if(c <= a && c <= b && c <= d)
	return c;
	
	else
	return d;
}


int main(void)
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	printf("%d", min(x, y, w-x, h-y));
	return 0;
}
