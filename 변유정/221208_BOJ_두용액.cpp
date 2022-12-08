#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 알고리즘 : 정렬, 두 포인터
// 1. 용액들을 크기 순으로 정렬해주기
// 2. 용액 처음, 마지막 포인터를 정해주고 용액 값을 비교해주면서 움직여주기

int N; // 주어지는 숫자(용액) 개수
vector <int> liquid; // 용액 특성값 저장소

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		liquid.push_back(a);
	}
	sort(liquid.begin(), liquid.end()); // 1차적으로 정렬해주기
	int s = 0, e = N - 1; // 두 포인터 위치
	int ans = 2000000000; // 두 용액 혼합 최대값 -> 최소값 찾아주기
	int ans1 =0, ans2=0; // 두 용액 값 저장하기
	while (s < e)
	{
		int temp = liquid[e] + liquid[s];

		if (abs(temp) < ans) // 두 용액 더한 값이 더 작다면
		{
			ans = abs(temp); // ans 갱신
			ans1 = liquid[s]; // 값 저장해주기
			ans2 = liquid[e];
			if (ans == 0) break; // 나올수 있는 가장 작은 값이 0이므로 0이면 멈추기
		}
		if (temp < 0) s++; // 만약 temp 값이 음수면 앞 포인터를 움직이기
		else e--; // 만약 temp값이 양수면 뒷 포인터를 움직이기
		// 포인터를 움직여서 두 용액 합을 줄이기
	}
	cout << ans1 << ' ' << ans2;
}