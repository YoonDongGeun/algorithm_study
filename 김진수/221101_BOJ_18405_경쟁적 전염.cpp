#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// [A] 전역 변수 선언
int N, K, S, X, Y;
vector<vector<int>> tube;

int main()
{
	// [1] 입력값 설정
	cin >> N >> K;
	tube.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tube[i][j];
		}
	}
	cin >> S >> X >> Y;
	
	// [2] (x, y) 칸을 기준으로 바이러스가 존재하는지 찾는다.
	int x = X - 1;
	int y = Y - 1;

	// [2-1] 만약 (x, y)칸에 바이러스가 이미 있다면 출력한다.
	if (tube[x][y])
	{
		cout << tube[x][y];
	}
	// [2-2] (x, y)부터 거리를 1씩 늘려가며 바이러스가 있는지 탐색한다.
	// 바이러스를 발견하면 최솟값을 출력하고, 끝까지 발견하지 못하면 0을 출력한다.
	else
	{
		vector<int> virus;
		int flag = 1;
		for (int n = 1; n <= S; n++)
		{

			for (int i = x-n; i <= x+n; i++)
			{
				for (int j = y-n; j <= y+n; j++)
				{
					if (0 <= i && i < N && 0 <= j && j < N && abs(x - i) + abs(y - j) == n && tube[i][j])
					{
						virus.push_back(tube[i][j]);
					}
				}
			}
			if (virus.size())
			{
				int min = *min_element(virus.begin(), virus.end());
				cout << min << '\n';
				break;
			}
		}

		if (virus.size() == 0)
		{
			cout << 0;
		}
	}
	return 0;
}
