#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 알고리즘 : 정렬, 그리디 알고리즘
// 방법 : 회의가 가장 빨리 끝나는 순으로 잡기***
// 만약 회의 시간이 겹치면 그냥 넘어가기

int N,a,b; // N - 회의 개수, a - 회의 시작시간, b - 회의 끝나는 시간
vector <pair<int, int>> room; // 회의 사용표 저장소

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		room.push_back({ b,a }); // 끝나는 시간 중심이기 떄문에, 거꾸로 저장하기
	}
	sort(room.begin(), room.end());
	int cnt = 0, now = 0;
	for (int i = 0; i < N; i++)
	{
		if (now <= room[i].second) // 만약 지금 시간이 다음 회의실 사용자보다 작다
		{
			cnt++; // 이용 가능
			now = room[i].first; // 다시 갱신
		}
	}
	cout << cnt;
}