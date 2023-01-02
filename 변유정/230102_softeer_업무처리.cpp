#include<iostream>
#include <queue>
using namespace std;

int H, K, R, S = 1; // H: 조직도 트리의 높이, K: 업무 개수, R: 날짜;
queue <int> q[2048]; // 큐 트리 (말단 직원 - 부서장의 업무 트리)
int tt = 1; // tt : 현재 시각, ans: 답(업무 번호의 합)
long long ans = 0;

void work()
{
	while (tt < R)
	{

		for (int i = 1; i < S; i++)
		{
			if (q[i * 2 + tt % 2].empty()) continue;
			// 추가해 준것 : tt%2
			q[i].push(q[i * 2 + tt % 2].front());
			q[i * 2 + tt % 2].pop();
		}
		tt++;
	}
	while (!q[1].empty()) // 부서장 R일 동안 진행된 업무
	{
		ans += q[1].front();
		q[1].pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> H >> K >> R;
	for (int i = 0; i < H; i++) // 높이에 따른 말단 직원 수 (S)
		S *= 2;
	int a;
	for (int i = S; i < 2 * S; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> a; // 말단 직원 i 의 업무j의 번호
			q[i].push(a);
		}
	}
	work();
	cout << ans;
}

// 이전 코드
//
//#include<iostream>
//#include <queue>
//using namespace std;
//
//int H, K, R, S = 1; // H: 조직도 트리의 높이, K: 업무 개수, R: 날짜;
//queue <int> q[2048]; // 큐 트리 (말단 직원 - 부서장의 업무 트리)
//int tt = 1, ans = 0; // tt : 현재 시각, ans: 답(업무 번호의 합)
//
//void work()
//{
//	while (tt < R)
//	{
//		for (int i = 1; i < S; i++)
//		{
//			if (q[i * 2].empty()) continue;
//			if (tt % 2)
//			{
//				q[i].push(q[i * 2 + 1].front());
//				q[i * 2 + 1].pop();
//			}
//			else
//			{
//				q[i].push(q[i * 2].front());
//				q[i * 2].pop();
//			}
//		}
//		tt++;
//	}
//	while (!q[1].empty()) // 부서장 R일 동안 진행된 업무
//	{
//		ans += q[1].front();
//		q[1].pop();
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> H >> K >> R;
//	for (int i = 0; i < H; i++) // 높이에 따른 말단 직원 수 (S)
//		S *= 2;
//	int a;
//	for (int i = S; i < 2 * S; i++)
//	{
//		for (int j = 0; j < K; j++)
//		{
//			cin >> a; // 말단 직원 i 의 업무j의 번호
//			q[i].push(a);
//		}
//	}
//	work();
//	cout << ans;
//}