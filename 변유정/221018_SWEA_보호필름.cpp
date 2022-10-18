#include <iostream>
#include <cstring>
using namespace std;

// 구현 문제 + 백트래킹
// 시간 줄이기
// 1. 구해둔 최솟값 ans보다 현재 약품투입 횟수 now가 커지면 return
// 2. 성능검사 중 하나라도 통과 못하면 break

// 구현 단계
// 1. 셀 하나씩 0 또는 1로 바꿔주기
// 2. 하나씩 바꿔주면서 확인하기
// 3. 0, 1 둘다 탐색하고 되돌아왔을 때는 원래의 배열로 돌려주기

int D, W, MK;
bool film[13][20];
int ans;
bool used[13];

void pass_test(int now, int put_p)
{
	if (now > ans) return;
	int p = 0;
	for (int i = 0; i < W; i++)
	{
		int kk = MK;
		int idx = D - 1;
		while (--kk)
		{
			if (idx == 0) break;
			if (film[idx][i] != film[idx - 1][i])
				kk = MK;
			idx--;
		}
		if (kk == 0) p++;
		else break;
	}
	if (p == W)
	{
		if (ans > now) ans = now;
		return;
	}

	for (int i = put_p; i < D; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		int temp[20];
		for (int k = 0; k < W; k++) temp[k] = film[i][k];
		for (int k = 0; k < W; k++) film[i][k] = 0;
		pass_test(now + 1, i);
		for (int k = 0; k < W; k++) film[i][k] = 1;
		pass_test(now + 1, i);
		for (int k = 0; k < W; k++) film[i][k] = temp[k];
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> D >> W >> MK;
		for (int y = 0; y < D; y++)
			for (int x = 0; x < W; x++)
				cin >> film[y][x];
		ans = 1e9;
		memset(used, 0, sizeof(used));
		pass_test(0, 0);
		cout << "#" << tc << " " << ans << '\n';
	}
}