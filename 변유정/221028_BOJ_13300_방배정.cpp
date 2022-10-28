#include <iostream>
using namespace std;

// 알고리즘 분류 : 수학, 구현
// 
// 구현 단계
// 1. 학생 6학년 남녀 배열 만들기
// 2. 배열 학생수가 0이면 pass
// 3. 0이 아니면 한방의 최대 인원수 K 로 나눈 몫 더해주기
// 4. 나누어 떨어지지 않으면 +1 해주기

int N, K;
int student[7][2] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		student[b][a]++;
	}
	int ans = 0;
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (student[i][j] == 0) continue;
			ans += student[i][j] / K;
			if (student[i][j] % K != 0) ans += 1;
		}
	}
	cout << ans;
}