#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/// DFS + 백트래킹?
/// 
/// 간단하게 구현 가능

int N;
int arr[11];
bool used[11] = { 0, };
int ans = 0;

void energy(int cnt, int temp)
{
	if (cnt == N - 2)
	{
		if (temp > ans) ans = temp;
		return;
	}
	for (int i = 1; i < N - 1; i++)
	{
		if (used[i] == 1) continue;
		int front = i - 1;
		int back = i + 1;
		//이미 빠진 숫자면 다음으로 넘어가게 (굳이 삭제하고 넣기 귀찮아서)
		while (used[front] == 1) front--;
		while (used[back] == 1) back++;
		used[i] = 1;
		energy(cnt + 1, temp + arr[front] * arr[back]);
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	energy(0, 0);
	cout << ans;
}


// 벡터사용해서 풀기

//vector<int> v;
//
//
//void dfs(int sum) {
//
//	if (v.size() == 2) {
//		ans = max(ans, sum);
//		return;
//	}
//
//	for (int i = 1; i < v.size() - 1; i++) {
//
//		int add = v[i - 1] * v[i + 1];
//		int tmp = v[i];
//
//		v.erase(v.begin() + i);
//		dfs(sum + add);
//		v.insert(v.begin() + i, tmp);
//	}
//}
//
// 출처 : https://dirmathfl.tistory.com/161