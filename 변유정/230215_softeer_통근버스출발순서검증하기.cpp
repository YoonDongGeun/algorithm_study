#include <iostream>
using namespace std;

// 통근버스 출발 순서 검증하기
// i, j, k 번째 버스가 arr[i] < arr[j] && arr[i] > arr[k] 가 되는 케이스 찾기
// 알고리즘 : 구간합

int N, arr[5001] = { 0, }, bus[5001][5001] = { 0, };
long long ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	// arr[i][j] : j번째보다 오른쪽에 있는 숫자들 중, i 보다 값이 작은 것들의 개수
	for (int i = 1; i <= N; i++)
	{
		bus[i][N] = 0;
		for (int j = N; j >= 1; j--)
		{
			if (arr[j] < i) bus[i][j - 1] = bus[i][j] + 1;
			else bus[i][j - 1] = bus[i][j];
		}
	}

	for (int i = 1; i < N; i++)
		for (int j = i + 1; j <= N; j++)
			// arr[i] < arr[j]
			if (arr[i] < arr[j])
				// j 보다 뒤에 있는 숫자들 중, arr[i] > arr[k] 인 개수들 더해주기
				ans += bus[arr[i]][j];
	cout << ans;
}