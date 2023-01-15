#include <iostream>
using namespace std;

// 알고리즘 : 두 포인터, 슬라이딩 윈도우
// 주의할 점 : 마을에 있는 집의개수(N), 도둑이 돈을 훔칠 연속된 집의 개수(M)이 같을 떄에는,
// 한번만 진행해야 한다 (질문게시판에 반례 참고하기)

// 진행방법 : 전부 더한 값에서 맨앞의 집을 빼주고, 다음 갈집을 더한 다음 값 비교
// 일일이 전부 더해주면서 하다보면 시간초과가 난다

int T, N, M, K;
// T : testcase, N : 마을에 있는 집의 개수, M : 도둑이 돈을 훔칠 연속된 집의 개수
// K : 방범장치 작동하는 최소 돈의 양
int home[2000010];
// home : 집에 보관중인 돈의 양 - 원형이기 때문에, 2번씩 저장해줌

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++)
		{
			cin >> home[i];
			home[i + N] = home[i];
			// 2번씩저장!
		}

		int cnt = 0, sum = 0;
		for (int i = 0; i < M; i++)
			sum += home[i];
		if (sum < K) cnt++;
		if (N == M) // 위에서 설명한 N == M 이 같을 경우
		{
			cout << cnt << '\n';
			continue;
		}
		for (int i = 1; i < N; i++)
		{
			sum += (home[i -1 + M] - home[i - 1]);
			if (sum < K) cnt++;
		}
		cout << cnt << '\n';
	}
}