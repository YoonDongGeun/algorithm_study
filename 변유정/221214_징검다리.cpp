#include <iostream>
#include <algorithm>
using namespace std;

int N, bridge[3001], rock[3001];
// N : 징검다리 돌의 개수
// bridge : 돌의 높이
// rock : 오름차순 가능한 돌의 개수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> bridge[i];

	rock[1] = 1;
	int ans = 1; // 최대 오름차순 가능한 개수
	for (int i = 2; i <= N; i++)
	{
		int temp = 1;
		for (int j = 1; j < i; j++)
			if (bridge[i] > bridge[j])
				temp = max(temp, rock[j] + 1);
		// i번째 이전의 돌 중 최대로 지나올 수 있는 돌의 개수
		rock[i] = temp;
		// i번째 순서 저장해주기
		ans = max(ans, rock[i]);
		// ans의 값도 max로 갱신
	}
	cout << ans;
}