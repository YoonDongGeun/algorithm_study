#include <iostream>
using namespace std;

// 브루트포스 알고리즘  -- 미세먼지 안녕! 문제와 비슷

// 1. 순서 정하기 (make_turn)
// 2. 배열 돌리기 (round)
// 3. 배열 돌리고 나서 최솟값 갱신 (find_min)

int N, M, K, ARR[51][51];
int Data[6][3];
int used[6] = { 0, };
int ans = 1e9;

int find_min()
{
	int mnn = 1e9;
	for (int y = 0; y < N; y++)
	{
		int temp = 0;
		for (int x = 0; x < M; x++)
			temp += ARR[y][x];
		mnn = min(temp, mnn);
	}
	return mnn;
}

void round(int num)
{
	// 중심점 + 거리
	int r = Data[num][0]-1;
	int c = Data[num][1]-1;
	int s = Data[num][2];

	// 거리에 맞게 하나씩 배열 돌려주기
	for (int i = 1; i <= s; i++)
	{
		int temp = ARR[r - i][c - i];
		for (int idx = r - i; idx < r + i; idx++)
			ARR[idx][c - i] = ARR[idx + 1][c - i];
		
		int temp1 = ARR[r - i][c + i];
		for (int idx = c + i; idx > c - i; idx--)
			ARR[r - i][idx] = ARR[r - i][idx - 1];
		ARR[r - i][c - i + 1] = temp;

		int temp2 = ARR[r+i][c+i];
		for (int idx = r + i; idx > r - i; idx--)
			ARR[idx][c + i] = ARR[idx - 1][c + i];
		ARR[r - i + 1][c + i] = temp1;

		for (int idx = c - i; idx < c + i; idx++)
			ARR[r + i][idx] = ARR[r + i][idx + 1];
		ARR[r+i][c+i-1] = temp2;
	}
}

void make_turn(int cnt, int now)
{
	if (cnt == K)
	{
		ans = min(ans, find_min());
		return;
	}

	// 임시로 배열 저장 (되돌아갈 때 다시 돌려주기 위해)
	int temp[51][51] = { 0, };
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			temp[y][x] = ARR[y][x];

	for (int i = 0; i < K; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		round(i);

		make_turn(cnt + 1, i);
		used[i] = 0;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				ARR[y][x] = temp[y][x];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> ARR[y][x];
	for (int i = 0; i < K; i++)
		cin >> Data[i][0] >> Data[i][1] >> Data[i][2];
	make_turn(0, 0);
	cout << ans;
}