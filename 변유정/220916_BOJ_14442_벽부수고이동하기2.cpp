#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/// 
/// 벽부수고 이동하기 응용문제
/// 구현하는 것은 쉬웠으나 시간초과문제 발생
/// 0. 배열설정을 딱맞게하자
/// 1. 벽부수고 이동하기와 단계 같음
/// 2. 시간초과 줄이기 실행 방법들
/// (1) string으로 받아서 실행했다가 숫자로 바꿈 (string 배열 탐색)
/// (2) used bool 형식 + cnt 따로
/// (3) 배열 범위 조절 (이게 제일 중요)
/// 

struct broke
{
	int y, x;
	int wall;
	int cnt;
};

int N, M, K;

// 0단계
int map[1000][1000];
bool used[1000][1000][10] = { 0, };
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue <broke> now;

void bfs()
{
	while (!now.empty())
	{
		int y = now.front().y;
		int x = now.front().x;
		int wall_ = now.front().wall;
		int cnt = now.front().cnt;
		now.pop();
		if (y == N - 1 && x == M - 1)
		{
			cout << cnt;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (used[ny][nx][wall_] == 0)
			{
				if (map[ny][nx] == 1)
				{
					if (wall_ < K)
					{
						now.push({ ny,nx,wall_ + 1, cnt + 1 });
						used[ny][nx][wall_ + 1] = 1;
					}
				}

				else if (map[ny][nx] == 0)
				{
						now.push({ ny,nx,wall_, cnt + 1 });
						used[ny][nx][wall_] = 1;
				}
			}
		}
	}
	cout << -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	string temp;
	for (int y = 0; y < N; y++)
	{
		cin >> temp;
		for (int x = 0; x < M; x++)
			map[y][x] = temp[x] - '0';
	}
	now.push({ 0,0,0,1 });
	used[0][0][0] = 1;
	bfs() ;
	return 0;
}

//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int R, C;
//int K;
//char map[1001][1002];
//int solve;
//bool chk[1001][1001][11];
//
//struct STATUS {
//	int r, c;
//	int k;
//	int cnt;
//};
//
//queue<STATUS>q;
//
//void Input_Data() {
//	//초기화
//	solve = 0x7fffffff;
//
//	cin >> R >> C >> K;
//	for (int r = 1; r <= R; r++) {
//		cin >> &map[r][1];
//	}
//}
//
//void BFS() {
//	int dr[] = { 0,0,0,1,-1 };
//	int dc[] = { 0,1,-1,0,0 };
//	//초기 조건 정의
//	q.push({ 1,1,K,1 });
//	chk[1][1][K] = 1;
//
//	if (R == 1 && C == 1) {
//		solve = 1;
//		return;
//	}
//
//	// 상태 발전 queue;
//	while (!q.empty()) {
//		STATUS data = q.front(); q.pop();
//
//		//상태 발전 연산
//		for (int dir = 1; dir <= 4; dir++) {
//			STATUS ndata;
//			ndata.r = data.r + dr[dir];
//			ndata.c = data.c + dc[dir];
//			ndata.k = data.k;
//			ndata.cnt = data.cnt + 1;
//
//			//좌표 유효성 확인
//			if (1 > ndata.r || ndata.r > R || 1 > ndata.c || ndata.c > C) continue;
//			if (map[ndata.r][ndata.c] == '1') {
//				if (ndata.k == 0) continue;
//				ndata.k--;
//			}
//			if (chk[ndata.r][ndata.c][ndata.k] == 1) continue;
//			if (ndata.r == R && ndata.c == C) {
//				solve = ndata.cnt;
//				return;
//			}
//
//			q.push(ndata);
//			chk[ndata.r][ndata.c][ndata.k] = 1;
//		}
//	}
//	solve = -1;
//	return;
//}
//
//int main(void)
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	Input_Data();
//	BFS();
//	cout << solve << '\n';
//
//	return 0;
//}