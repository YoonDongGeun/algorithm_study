#include <iostream>

int di[4] = { 0,1,0,-1 };
int dj[4] = { 1,0,-1,0 };


int main() {
	int N, N_apples, N_turns;
	int field[102][102] = { 0, };
	int turns[100][2];
	int q=0;
	int i,j;
	char sub;
	scanf("%d", &N);
	scanf("%d", &N_apples);
	while (N_apples--) {
		scanf("%d %d", &i, &j);
		field[i][j] = 2;
	}
	i = 0; j = 0;
	while (i < N + 2) field[i++][j]=1;
	--i;
	while (j < N + 2) field[i][j++] = 1;
	--j;
	while (i >=0) field[i--][j] = 1;
	++i;
	while (j >=0) field[i][j--] = 1;

	scanf("%d", &N_turns);
	for (int n = 0; n < N_turns; ++n) {
		scanf("%d %c", &turns[n][0], &sub);
		if (sub == 'L') turns[n][1] = 3;
		else turns[n][1] = 1;
	}
	int snake[10000][2];
	int tail = 0, head = 0;
	int d = 0,time=0;
	snake[0][0] = 1;
	snake[0][1] = 1;
	field[1][1] = 1;
	while (1) {
		++time;
		if (q < N_turns && turns[q][0] < time) d = (d + turns[q++][1]) % 4;
		i = snake[head][0] + di[d];
		j = snake[head][1] + dj[d];
		if (field[i][j] == 1) break;
		int temp = field[i][j];
		field[i][j] = 1; snake[++head][0] = i; snake[head][1] = j;
		if (temp == 2) continue;
		field[snake[tail][0]][snake[tail++][1]] = 0;




	}
	printf("%d", time);

}