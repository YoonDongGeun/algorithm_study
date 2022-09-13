#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

//BFS + 백트래킹
//초반에 여러번 틀렸는데, 조건 설정 위치를 잘 해줘야 한다.
// 처음 used_coin에 1을 더해줬기 때문에, 제한 범위를 잘 생각하고 풀어야한다ㅠ

struct Coin {    ///코인 두개 위치 한번에 큐에 저장하기
	int y1, x1, y2, x2;
};

int N, M;
char arr[21][21];
queue <Coin> q;
int used[21][21][21][21] = {0,};
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans = 1e9;
int yy1 = 0, xx1 = 0, yy2 = 0, xx2 = 0; //코인 위치 저장

void bfs()
{
	while (!q.empty())
	{
		int y1 = q.front().y1;
		int x1 = q.front().x1;
		int y2 = q.front().y2;
		int x2 = q.front().x2;
		q.pop();
		if (used[y1][x1][y2][x2] > 10) continue; //10번이 넘어가면 제한되기 때문에 되돌아가기
		for (int i = 0; i < 4; i++)
		{
			int ny1 = y1 + dy[i];
			int nx1 = x1 + dx[i];
			int ny2 = y2 + dy[i];
			int nx2 = x2 + dx[i];
			// 동전 2개 모두 보드 밖으로 가버려서 되돌가가기
			if ((ny1<0 || ny1>=N || nx1 < 0 || nx1 >= M) && (ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= M)) continue;
			// 둘다 보드 안에 있을 경우
			else if (ny1 >= 0 && ny1 < N && nx1 >=0 && nx1 < M && ny2 >= 0 && ny2 < N && nx2 >= 0 && nx2 < M)
			{
				// 1. 동전 두개 모두 벽에 막혔을 때 저장하지 않고 되돌아가기
				if (arr[ny1][nx1] == '#' && arr[ny2][nx2] == '#') continue;
				// 2. 동전 한개씩만 막혔을 때
				if (arr[ny1][nx1] == '#')
				{
					ny1 = y1;
					nx1 = x1;
				}
				if (arr[ny2][nx2] == '#')
				{
					ny2 = y2;
					nx2 = x2;
				}
				// 만약 사용했던 자리면 되돌아가기
				if (used[ny1][nx1][ny2][nx2] != 0) continue;
				used[ny1][nx1][ny2][nx2] = used[y1][x1][y2][x2] + 1;
				q.push({ ny1,nx1,ny2,nx2 });
			}
			// 동전 1개만 보드 밖으로 가버렸을 때 ans에 저장해두기
			else ans = min(ans,used[y1][x1][y2][x2]);
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
	{
		string str;
		cin >> str;
		for (int x = 0; x < M; x++)
		{
			arr[y][x] = str[x];
			if (arr[y][x] == 'o')
			{
				if (yy1 == 0)
				{
					yy1 = y;
					xx1 = x;
				}
				else
				{
					yy2 = y;
					xx2 = x;
				}
			}
		}
	}
	// 두개 동전 처음 위치 큐에 넣기
	q.push({ yy1,xx1,yy2,xx2 });
	used[yy1][xx1][yy2][xx2] = 1;
	bfs();
	//ans값이 그대로거나 혹시 10이 넘어가버리면 -1 출력
	if (ans > 10) cout << -1;
	else cout << ans;
	return 0;
}

//DFS로 구현한 코드

//#define pii pair<int, int>
//int N, M, result = 1e9 + 7;
//int Map[21][21];    // 2 : 동전 위치   0 : 벽 위치   1 : 빈칸
//vector< pii > startP;
//int dr[4] = { 0, 0, 1, -1 }, dc[4] = { 1, -1, 0, 0 };
//
//void input() {
//	// Map에서 벗어나는 경우는 -1로 설정
//	memset(Map, -1, sizeof(Map));
//
//	cin >> N >> M;
//	string str;
//	for (int i = 1; i <= N; i++) {
//		cin >> str;
//		for (int j = 0; j < M; j++) {
//			if (str[j] == 'o') {
//				Map[i][j + 1] = 2;
//				startP.push_back({ i, j + 1 });
//			}
//			else if (str[j] == '#') Map[i][j + 1] = 0;
//			else Map[i][j + 1] = 1;
//		}
//	}
//}
//
//bool isOut(const pii& A) {
//	if (A.first < 1 || A.first > N || A.second < 1 || A.second > M) return true;
//	return false;
//}
//
//void dfs(pii A, pii B, int cnt) {
//	// 현재 result보다 cnt가 크다면 더이상의 탐색은 불필요
//	if (result < cnt) return;
//
//	// cnt 가 10보다 커지면 result값 갱신
//	if (cnt > 10) {
//		result = min(result, cnt);
//		return;
//	}
//
//	// 둘 다 떨어졌으면 되돌아감
//	if (isOut(A) && isOut(B)) return;
//	// 하나만 떨어졌으면 result를 최소 cnt값으로 교체
//	else if ((isOut(A) && !isOut(B)) || (!isOut(A) && isOut(B))) {
//		result = min(result, cnt);
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		pii An = { A.first + dr[i], A.second + dc[i] };
//		pii Bn = { B.first + dr[i], B.second + dc[i] };
//		if (!Map[An.first][An.second]) An = A;
//		if (!Map[Bn.first][Bn.second]) Bn = B;
//
//		dfs(An, Bn, cnt + 1);
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	input();
//	dfs(startP[0], startP[1], 0);
//
//	if (result > 10) cout << -1;
//	else cout << result;
//
//	return 0;
//}

// 출처 : https://hyeo-noo.tistory.com/126