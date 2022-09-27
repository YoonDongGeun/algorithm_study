#include <iostream>
#include <vector>
using namespace std;

// 시뮬레이션 + 구현
// (봄 + 여름) + (가을 + 겨울) - 구현
// 주의할 점
// 1. 맨 처음 받는 땅은 실제 사용되는 양분이 아니다 (양분 5)
// 2. 코드 위치만 잘 조절해주면 '나이가 어린 나무부터 양분 먹는다' 와 '입력으로 주어지는 나무의 위치는 모두 서로 다름'
// 조건 상충으로 굳이 정렬해줄 필요 없다
// 3. 반복문이 많기 때문에 코드 배열 잘 보기

int N, M, K;
int A[11][11];
int yangboon[11][11];
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
// 나무 위치에 따라 저장해주기
vector <int> S2D2[11][11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> A[y][x];
			yangboon[y][x] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		S2D2[x][y].push_back(z);
	}

	while (K--)
	{
		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (!S2D2[y][x].empty())
				{
					int temp = 0;
					for (int idx = S2D2[y][x].size()-1; idx >=0; idx--)
					{
						if (S2D2[y][x][idx] <= yangboon[y][x]) // 봄
						{
							yangboon[y][x] -= S2D2[y][x][idx];
							S2D2[y][x][idx] += 1;
						}
						else
						{
							// 여름
							temp += S2D2[y][x][idx]/2;
							S2D2[y][x].erase(S2D2[y][x].begin() + idx);
						}
					}
					yangboon[y][x] += temp;
				}
			}
		}

		for (int y = 1; y <= N; y++)
		{
			for (int x = 1; x <= N; x++)
			{
				if (!S2D2[y][x].empty())
				{
					for (int idx = 0; idx < S2D2[y][x].size(); idx++)
					{
						// 가을
						if (S2D2[y][x][idx] % 5 == 0)
						{
							for (int k = 0; k < 8; k++)
							{
								int ny = y + dy[k];
								int nx = x + dx[k];
								if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
								S2D2[ny][nx].push_back(1);
							}
						}
					}
				}
				// 겨울
				yangboon[y][x] += A[y][x];
			}
		}
	}

	int ans = 0;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			if (!S2D2[y][x].empty())
				ans += S2D2[y][x].size();

	cout << ans;
}