#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 알고리즘 : 정렬, 그리디 알고리즘, 우선순위 큐
// 최소 강의실 사용하기 위해
// 1. room (강의실) 정렬해두기 (시작시간 순으로)
// 2. master 우선순위큐에 진짜 강의실 사용표 저장하기

int N,a,b; 
vector <pair<int, int>> room; // 강의실 이용 시간표
priority_queue<int, vector<int>, greater<int>> master; // 이용 강의실 저장소

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		room.push_back({ a,b });
	}
	sort(room.begin(), room.end());
	master.push(room[0].second); // 첫번쨰 강의실은 우선 넣어두기
	for (int i = 1; i < N; i++)
	{
		if (master.top() <= room[i].first) master.pop();
		// master 우선순위 큐에 맞춰서 정렬 후,
		// 다음 시간표 시간과 비교해서 pop 할지 결정
		// 맨처음 시간표 다음으로 강의실 사용 가능하면 pop하고 새로 넣기
		// 아니면 새 강의실을 써야하니까, 그냥 새로 master에 넣기
		master.push(room[i].second);
	}
	cout << master.size();
}

// 밑에는 vector로만 구현 (시간초과남)

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N, a, b;
//vector <pair<int, int>> room;
//vector <int> master;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a >> b;
//		room.push_back({ a,b });
//	}
//	sort(room.begin(), room.end());
//	master.push_back(room[0].second);
//	for (int i = 1; i < N; i++)
//	{
//		sort(master.begin(), master.end());
//		if (master[0] <= room[i].first) master[0] = room[i].second;
//		else master.push_back(room[i].second);
//	}
//	cout << master.size();
//}