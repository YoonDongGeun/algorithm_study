#include <iostream>
#include <queue>
using namespace std;

// 반례 모음집
// https://www.acmicpc.net/board/view/56469

// 큐 활용 잘하기 + 위치 잘 조절하기
// 방향을 바꾸는 시점 - 몸늘리고 나서 방향 변화하기
// 그래서 돌고 나서 방향 더해줘야한다

int N, K, L;
int board[101][101]; // 뱀, 사과 정보 저장하기
int direct[10001]; // 시간대에 따른 방향 변화 배열 저장하기
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue <pair<int, int>> Snake;

int snake()
{
	board[1][1] = 1;
	int dir = 0,cnt = 1;
	Snake.push({ 1,1 });
	while (true)
	{
		int y = Snake.back().first;
		int x = Snake.back().second;
		int ny = y + dy[dir%4];
		int nx = x + dx[dir% 4];
		if (ny <= 0 || nx <= 0 || ny > N || nx > N) break; // 벽과 부딫혔을 때
		if (board[ny][nx] == 1) break; // 자기 몸과 부딫혔을 때
		else if (board[ny][nx] == -1) // 사과와 만났을 때
		{
			board[ny][nx] = 1; // 사과 먹고 자기 몸 늘리기
			Snake.push({ ny,nx });
		}
		else // 그외 빈칸
		{
			board[ny][nx] = 1;
			// 꼬리 정보 + 꼬리 줄이기
			int ey = Snake.front().first;
			int ex = Snake.front().second;
			Snake.pop();
			board[ey][ex] = 0;
			Snake.push({ ny,nx });
		}
		dir += direct[cnt];
		cnt += 1;
	}
	return cnt;
}

int main()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = -1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		if (b == 'D') direct[a] = 1; // 오른쪽 방향
		else direct[a] = 3; // 왼쪽 방향
	}
	cout << snake();
}