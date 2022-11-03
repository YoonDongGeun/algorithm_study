#include <iostream>
using namespace std;

// 알고리즘 구현 : 위 - 구간합, 아래 - dfs

int N,ans = 0, arr[5001] = { 0, }, bus[5001][5001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	for (int i = 1; i <= N; i++)
	{
		bus[i][N] = 0;
		if (arr[N] < i) bus[i][N - 1] = 1;
		else bus[i][N - 1] = 0;
		for (int j = N - 2; j > 0; j--)
		{
			if (arr[j + 1] < i) bus[i][j] = bus[i][j+1] + 1;
			else bus[i][j] = bus[i][j + 1];
		}
	}
	for (int i = 1; i < N-1; i++)
		for (int j = i + 1; j < N; j++)
			if (arr[i] < arr[j])
				ans += bus[arr[i]][j];
	cout << ans;
}
//int N, ans, arr[5002];
//vector <int> v;
//
//void bus(int idx, int cnt)
//{
//	if (cnt == 3)
//	{
//		ans += 1;
//		return;
//	}
//	for (int i = idx + 1; i <= N; i++)
//	{
//		if (cnt == 0)
//		{
//			v.push_back(arr[i]);
//			bus(i, cnt + 1);
//			v.pop_back();
//		}
//		else if (cnt == 1)
//		{
//			if (arr[idx] > arr[i]) continue;
//			v.push_back(arr[i]);
//			bus(i, cnt + 1);
//			v.pop_back();
//		}
//		else if (cnt == 2)
//		{
//			if (arr[idx] < arr[i] || v[0] < arr[i]) continue;
//			v.push_back(arr[i]);
//			bus(i, cnt + 1);
//			v.pop_back();
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> arr[i];
//	}
//	ans = 0;
//	bus(0, 0);
//	cout << ans;
//}