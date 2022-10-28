#include <iostream>
using namespace std;

int map[502][502], N, M;           // 최대 25만개라서 전역변수로 선언. 또한 테두리는 -1로 채우기 위해서 2칸 더 크게 했다.
int visited[502][502];    // 방문 하는 곳에서 골인 지점까지(N,M)까지 가는 경우의 수를 저장한다.
int dy[4] = { 0,0,1,-1 };         // 상하좌우 움직이는 델타
int dx[4] = { 1,-1,0,0 };


int search(int y, int x)           // y,x에서 N,M까지 가는 경우의 수를 visited[y][x]에 저장한다. 이때 y,x에서 갈수 있는 길에서 N,M까지 가는 경우의 수를 더한다.
{
	int ny, nx;
	if (visited[y][x]>0)          // 만약 visited[y][x]가 이미 방문이 되서 y,x에서 N,M까지 가는경우의 수가 알려진 경우 그만큼 더해준다.
	{
		return visited[y][x];
	}
	visited[y][x] = 0;            // 방문 하면 0으로 만들어 줘서 기존의 -1과 차별화 해준다.
	for (int i = 0; i < 4; i++)   // 4방향 탐색
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (map[ny][nx] < map[y][x])   // 만약 현재의 값이 갈 곳보다 크면 내리막이니까 이때 시행.
		{
			if (visited[ny][nx]>0)     // 만약 갈 곳이 이미 거기서 가는 경우의 수가 몇개인지 알아냈으면 더해준다.
			{
				visited[y][x] += visited[ny][nx];
			}
			else if(visited[ny][nx] == -1)  // 만약 갈곳이 이미 거기서 가는 경우의 수가 몇개인지 못알아 냈으면 거기서의 가는 경우의수를 구해준다.
			{
				visited[y][x] += search(ny, nx);
			}
		}
	}


	return visited[y][x]; // 최종적으로 경우의 수 구했으면 그값을 리턴해준다.
}




int main(void)
{
	cin >> N >> M;
	for (int i = 0; i <= N + 1; i++) //테두리 처리
	{
		map[i][0] = 10001;
		map[i][M + 1] = 10001;
		visited[i][0] = 0;
		visited[i][M + 1] = 0;
	}
	for (int j = 0; j <= M + 1; j++) //테두리 처리
	{
		map[0][j] = 10001;
		map[N + 1][j] = 10001;
		visited[0][j] = 0;
		visited[N + 1][j] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) // 지도 값 입력받기
		{
			cin >> map[i][j];
			visited[i][j] = -1;      // visited값 -1로 초기화
		}
	}

	visited[N][M] = 1;              // 도착지점에서 도착지점 가는 경우의 수 1로 만들기/
	search(1, 1);                   // 1,1에서 도착지점 까지 가는 경우의 수 구하기.
	cout << visited[1][1];

	return 0;
}