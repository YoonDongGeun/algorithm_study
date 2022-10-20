#include <iostream>
#include <string>
#include <vector>
using namespace std;
// getline 왜안대냐 동근아
// [A] 전역 변수 선언
int R, C;
vector<vector<string>>arr;
vector<vector<string>>visited;
int result = 0;

// [B] delta 방향 설정
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

// [D] DFS 함수 설정
void dfs(int i, int j, string alphabet)
{
	for (int dr = 0; dr < 4; dr++)
	{
		int ni = i + di[dr];
		int nj = j + dj[dr];

		if (0 <= ni < R and 0 <= nj < C and (alphabet.find(arr[ni][nj]) != string::npos))
		{
			if (visited[ni][nj] != alphabet + arr[ni][nj])
			{
				visited[ni][nj] = alphabet + arr[ni][nj];
				dfs(ni, nj, alphabet + arr[ni][nj]);
			}
		}
	}

	if (result < alphabet.length())
	{
		result = alphabet.length();
	}
	return;
}


// [1] 입력값 설정
int main()
{
	cin >> R >> C;
	cin.ignore();
	for (int i = 0; i < R; i++)
	{
		getline(cin, arr[i]);
	}

	visited[0][0] = arr[0][0];
	dfs(0, 0, arr[0][0]);
	cout << result << '\n';
	return 0;
}