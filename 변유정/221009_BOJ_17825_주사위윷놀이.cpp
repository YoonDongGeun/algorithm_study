#include <iostream>
using namespace std;

// 시뮬레이션 + 구현
// 조건들을 잘 생각해봐야하는 문제

// 과정
// 1차 : 갈래를 모두 생각해서 구현 - 문제점 : 중복되는 갈래가 많다
// 2차 : 중복 갈래 고려해서 제외시킴 - 문제점 : 값으로 비교하다가 중복 갈래가 아닌 같은 값 제외 시켜버림 (ex: 30)
// 3차 : 갈래 모두 생각하지 말고 그냥 보드 대로만 구현 (갈래 고려 X)

// 구현 과정
// 1-1. 말 4개를 동시에 옮김 (a,b,c,d)
// 1-2. 말이 옮겨졌을 때, 이미 놓여져 있는 값이면 이동 X (도착점 제외)
// 1-3. 10번 모두 말을 옮겼을 때의 합이 ans 보다 크면 ans 갱신

// 2. 말 옮길 때 파란색 갈래 지점 / 갈래 길 지점 고려


int dice[10];
int board[33] = { 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,13,16,19,22,24,28,27,26,25,30,35,40,0 };
int ans = 0;

// 2단계
int move_h(int now, int num)
{
	// 2-1. 파란색 지점
	if (now == 5)
	{
		if (num <= 3) now = num + 19;
		else now = num + 24;
	}
	else if (now == 10)
	{
		if (num <= 2) now = num + 22;
		else now = num + 25;
	}
	else if (now == 15)
		now = num + 24;
	// 2-2. 갈래길 지점 (보드 지점 번호가 이어지지 않기 때문에 순서 고려)
	else if (now >= 20 && now <= 22 && now + num > 22)
		now += num + 5;
	else if (now >= 23 && now <= 24 && now + num > 24)
		now += num + 3;
	else if (now <= 19 && now + num > 19)
		now += num + 11;
	else now += num;
	// 2-3. 만약 도착지점보다 더 많다면 그냥 도착지점으로 정해놓기
	if (now > 31) now = 32;
	return now;
}

// 1단계
void roll(int cnt,int a,int b,int c,int d, int temp)
{
	if (cnt == 10)
	{
		ans = max(ans, temp);
		return;
	}

	if (a != 32)
	{
		int na = move_h(a, dice[cnt]);
		// 1-1 & 1-2 단계
		if (na != b && na != c && na != d || na == 32)
			roll(cnt + 1, na, b, c, d, temp + board[na]);
	}
	if (b != 32)
	{
		int nb = move_h(b, dice[cnt]);
		if (nb != a && nb != c && nb != d  || nb == 32)
			roll(cnt + 1, a, nb, c, d, temp + board[nb]);
	}

	if (c != 32)
	{
		int nc = move_h(c, dice[cnt]);
		if (nc != a && nc != b && nc != d || nc == 32)
			roll(cnt + 1, a, b, nc, d, temp + board[nc]);
	}

	if (d != 32)
	{
		int nd = move_h(d, dice[cnt]);
		if (nd != a && nd != b && nd != c || nd == 32)
			roll(cnt + 1, a, b, c, nd, temp + board[nd]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	roll(0, 0, 0, 0, 0,0);
	cout << ans;
}