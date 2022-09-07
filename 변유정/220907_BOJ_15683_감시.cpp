#include <iostream>
#include <vector>
using namespace std;

/// 필요한 알고리즘 : 구현, 시뮬레이션
/// 
/// 방향 잡고 종류에 따라 구현하는 연습을 해야한다!
/// 문제풀때 중요한 것
/// 1. 필요한 함수 (변화, 방향에 따라 재귀)
/// 2. 1~5 cctv 종류에 따라 구분하기
/// 3. 방향 배열 사용해서 구현하기
/// 
/// 필요없는 건 cctv 순서! 쓸데없이 하지 말기
/// 방향에 따라서 모두 시뮬레이션 해보지 말고, 방향에 따라 최댓값 구해서
/// 시간 줄여보기....

struct Node {
	int direct;
	int y, x;
};

int N, M;
int room[9][9];
vector<Node> cctv;
int dy[6] = { -1,0,1,0,-1,0 };
int dx[6] = { 0,1,0,-1,0,1 };
int ans = 1e9;

void change(int dir, int y, int x)
{
	for (int k = 1; k < 8; k++)
	{
		if (y + dy[dir] * k >= N || y + dy[dir] * k < 0 || x + dx[dir] * k >= M || x + dx[dir] * k < 0) break;
		if (room[y + k * dy[dir]][x + k * dx[dir]] == 6) break;
		if (room[y + k * dy[dir]][x + k * dx[dir]] == 0 || room[y + k * dy[dir]][x + k * dx[dir]]>=10) room[y + k * dy[dir]][x + k * dx[dir]] += 10;
	}
}

void change_origin(int dir, int y, int x)
{
	for (int k = 1; k < 8; k++)
	{
		if (y + dy[dir] * k >= N || y + dy[dir] * k < 0 || x + dx[dir] * k >= M || x + dx[dir] * k < 0) break;
		if (room[y + k * dy[dir]][x + k * dx[dir]] == 6) break;
		if (room[y + k * dy[dir]][x + k * dx[dir]] >= 10) room[y + k * dy[dir]][x + k * dx[dir]] -= 10;
	}
}

void watch(int cnt)
{
	if (cnt == cctv.size())
	{
		int temp = 0;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (room[y][x] == 0) temp++;
		if (temp < ans) ans = temp;
		return;
	}
	
	else
	{
		if (cctv[cnt].direct == 1)
		{
			for (int k = 0; k < 4; k++)
			{
				change(k, cctv[cnt].y, cctv[cnt].x);
				watch(cnt + 1);
				change_origin(k, cctv[cnt].y, cctv[cnt].x);
			}
		}

		else if (cctv[cnt].direct == 2)
		{
			for (int k = 0; k < 2; k++)
			{
				change(k, cctv[cnt].y, cctv[cnt].x);
				change(k+2, cctv[cnt].y, cctv[cnt].x);
				watch(cnt + 1);
				change_origin(k, cctv[cnt].y, cctv[cnt].x);
				change_origin(k + 2, cctv[cnt].y, cctv[cnt].x);
			}
		}

		else if (cctv[cnt].direct == 3)
		{
			for (int k = 0; k < 4; k++)
			{
				change(k, cctv[cnt].y, cctv[cnt].x);
				change(k+1, cctv[cnt].y, cctv[cnt].x);
				watch(cnt + 1);
				change_origin(k, cctv[cnt].y, cctv[cnt].x);
				change_origin(k+1, cctv[cnt].y, cctv[cnt].x);
			}
		}

		else if (cctv[cnt].direct == 4)
		{
			for (int k = 0; k < 4; k++)
			{
				change(k, cctv[cnt].y, cctv[cnt].x);
				change(k + 1, cctv[cnt].y, cctv[cnt].x);
				change(k + 2, cctv[cnt].y, cctv[cnt].x);
				watch(cnt + 1);
				change_origin(k, cctv[cnt].y, cctv[cnt].x);
				change_origin(k + 1, cctv[cnt].y, cctv[cnt].x);
				change_origin(k + 2, cctv[cnt].y, cctv[cnt].x);
			}
		}

		else
		{
			change(0, cctv[cnt].y, cctv[cnt].x);
			change(1, cctv[cnt].y, cctv[cnt].x);
			change(2, cctv[cnt].y, cctv[cnt].x);
			change(3, cctv[cnt].y, cctv[cnt].x);
			watch(cnt + 1);
			change_origin(0, cctv[cnt].y, cctv[cnt].x);
			change_origin(1, cctv[cnt].y, cctv[cnt].x);
			change_origin(2, cctv[cnt].y, cctv[cnt].x);
			change_origin(3, cctv[cnt].y, cctv[cnt].x);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			cin >> room[y][x];
			if (room[y][x] >= 1 && room[y][x] < 6)
				cctv.push_back({room[y][x],y,x});
		}
	watch(0);
	cout << ans;
}