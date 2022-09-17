#include <iostream>
#include <queue>
#include <set>
using namespace std;

// 반대로 생각하는 BFS
// 
// 이제까지 1을 중심으로 움직였다면 이 문제는 0을 중심으로 움직여야함
// ***벽(1)중심으로 움직여도 괜찮지만 시간초과 발생***
//
// 구현 단계
// 1. 0 구역 나누기 (처음 가는 0인지 아님 구역 정해진 0인지)
// 1-1. 처음가는 0이면 구역 지정해주고 다시 구역 탐색
// 
// 2. 벽(1)과 인접한 0구역이 있는지 보기
// 2-1. 4방향 중 동일한 0구역이 있을 수 있으므로 제외하기 위해 set으로 구역 임시 저장
// 2-2. 구역 저장해주기
//
// 주의사항 : 출력 - 10으로 나눈 나머지

int N, M, map[1000][1000];
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
queue <pair<int,int>> change; // 0구역 임시 저장
queue <pair<int, int>> q; // 벽 위치 저장
int section[1000][1000]; // 구역 방문 흔적
int area[1000001]; // 구역별 넓이
int cnt = 1; // 구역 번호


// 1단계 : 0구역 정해주기
void zero()
{
	int zone = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (map[y][x] != 0 || section[y][x] != 0) continue;
			change.push({ y,x });
			section[y][x] = cnt;
			zone++;
			while (!change.empty())
			{
				int nowy = change.front().first;
				int nowx = change.front().second;
				change.pop();
				for (int i = 0; i < 4; i++)
				{
					int ny = nowy + dy[i];
					int nx = nowx + dx[i];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
					if (section[ny][nx] != 0 || map[ny][nx] != 0) continue;
					section[ny][nx] = cnt;
					change.push({ ny,nx });
					zone++;
				}
			}
			area[cnt] = zone;
			cnt++; zone = 0;
		}
	}
}

// 2단계 : 벽에서 갈 수 있는 범위
void one()
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		set<int> s;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 1) continue;
			s.insert(section[ny][nx]);
		}
		for (auto iter = s.begin(); iter != s.end(); ++iter) 
			map[y][x] += area[*iter];
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			// 10으로 나눈 나머지!!!
			cout << map[y][x]%10;
		}
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	string temp;
	for (int y = 0; y < N; y++)
	{
		cin >> temp;
		for (int x = 0; x < M; x++)
		{
			map[y][x] = temp[x] - '0';
			if (map[y][x] == 1) q.push({ y,x });
		}
	}
	zero();
	one();
	return 0;
}

// 참고한 코드
// 
// 출처 : https://nim-code.tistory.com/253
// 
//#include <iostream>
//#include <queue>
//#include <cstdio>//scanf
//#include <cstring>//memset
//using namespace std;
//
//struct Pos {
//	int x, y;
//};
//
//int N, M;
//int Map[1001][1001];
//bool visited[1001][1001];
//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,-1,1 };
//
//void bfs(int startx, int starty) {
//	queue<Pos>q;
//	vector<Pos>wall;
//	q.push({ startx,starty });
//	visited[startx][starty] = true;
//	int cnt = 1;
//	while (!q.empty()) {
//		int x = q.front().x;
//		int y = q.front().y;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
//				continue;
//			if (Map[nx][ny] == 0 && visited[nx][ny] == false) {
//				visited[nx][ny] = true;
//				q.push({ nx,ny });
//				cnt++;
//			}
//			//현재 탐색하는 공간에 인접한 벽 저장
//			else if (Map[nx][ny] != 0 && visited[nx][ny] == false) {
//				visited[nx][ny] = true;
//				wall.push_back({ nx,ny });
//			}
//		}
//	}
//	//탐색하면서 나왔던 벽들에 0의 개수 더해주기
//	for (int i = 0; i < wall.size(); i++) {
//		Map[wall[i].x][wall[i].y] += cnt;
//		visited[wall[i].x][wall[i].y] = false;
//	}
//}
//
//int main() {
//	scanf("%d %d", &N, &M);
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			scanf("%1d", &Map[i][j]);
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (Map[i][j] == 0 && visited[i][j] == false)
//				bfs(i, j);
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			printf("%d", Map[i][j] % 10);
//		}
//		printf("\n");
//	}
//	return 0;
//}