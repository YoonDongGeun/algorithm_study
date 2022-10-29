#include <iostream>
#include <vector>
using namespace std;

// [A] 전역변수 선언
int M, N;
vector<vector<int>> arr;
vector<vector<int>> visited;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

// [B] dfs 함수 설정
int dfs(int i, int j)
{
	// [B-1] 백트래킹 조건. 이미 탐색한 적이 있다면 visited에 저장된 값을 반환.
	if (visited[i][j] != -1)
	{
		return visited[i][j];
	}
	// [B-2] 재귀 종료 조건. (M-1, N-1) 칸에 도달했다면 1을 반환.
	if (i == M - 1 && j == N - 1)
	{
		return 1;
	}
	
	// [B-3] Top-Down 연산. 탐색한 적 없는 (i, j)에 대해 다음 연산을 해준다.
	// visited[i][j]에 저장될 값은 (i, j)부터 (M-1, N-1) 칸에 도달할 수 있는 경우의 수이다.
	// 탐색한 적 없는 visited의 기본값을 0으로 하지 않고 -1로 한 이유는 경우의 수를 합칠 때 복잡해지기 때문이다.
	// 따라서 먼저 visited가 -1이 아닌지 확인한 후, 값을 0으로 초기화해놓고 경우의 수를 계산한다.
	visited[i][j] = 0;
	for (int dr = 0; dr < 4; dr++)
	{
		int ni = i + di[dr], nj = j + dj[dr];
		if (0 <= ni && ni < M && 0 <= nj && nj < N && arr[i][j] > arr[ni][nj])
		{
			visited[i][j] += dfs(ni, nj);
		}
	}
	
	return visited[i][j];
}

// 입력값 설정 및 dfs 탐색
int main()
{
	cin >> M >> N;
	arr.assign(M, vector<int>(N));
	visited.assign(M, vector<int>(N));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = -1;
		}
	}
	dfs(0, 0);
	cout << visited[0][0];
	return 0;
}
