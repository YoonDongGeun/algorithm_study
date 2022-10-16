#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define F(x,X) for(int x=0;x<X;++x)

int main() {
	int N,flag=0;
	scanf("%d", &N);
	F(i, N) {
		F(j, N) {
			int ni = i, nj = j;
			for (int n = N; n >= 3; n /= 3) {
				if (ni % 3 == 1 && nj % 3 == 1) { flag = 1; printf(" "); break; }
				ni /= 3; nj /= 3;
			}
			if (!flag) {
				printf("*");
			
			}
			else flag = 0;
		}
		printf("\n");
	}
}