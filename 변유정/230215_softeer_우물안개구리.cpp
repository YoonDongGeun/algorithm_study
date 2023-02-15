#include <iostream>
#include <vector>
using namespace std;

// 우물 안 개구리
// 알고리즘 : 구현

int N, M, A, B, gym[100001] = {0,};
vector <int> ff[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> gym[i];

	// 벡터로 저장해주기
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		ff[A].push_back(B);
		ff[B].push_back(A);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		ans++;
		for (int j = 0; j < ff[i].size(); j++)
		{
			// 만약 자기와 친한 사람 중 무게가 같거나 크면 우물안 개구리가 아니다!
			if (gym[ff[i][j]] >= gym[i])
			{
				ans--; break;
			}
		}
	}
	cout << ans;
}