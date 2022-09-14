#include <iostream>
#include <vector>
using namespace std;

// 벡터로 구현...했는데 디큐로 해도 됐었을 듯
// 컨베이어벨트와 로봇 위치를 따로 구현
// 1. 올라가는 위치와 내려가는 위치 파악
// 2. 내려가는 위치는 항상 비워두기
// 3. 설명순서에 따라 진행하기 (미리 시작위치에 올려놓고 시작하지 말기!)

int N, K;
vector <int> belt;
vector <bool> robot;
int cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
	{
		int a;
		cin >> a;
		belt.push_back(a);
		robot.push_back(0);
	}

	while (true)
	{
		// 1. 벨트 각 칸위에 있는 로봇과 함께 한칸 회전
		int temp = belt[2*N-1];
		belt.pop_back();
		belt.insert(belt.begin(), temp);

		bool temp1 = robot[2 * N - 1];
		robot.pop_back();
		robot.insert(robot.begin(), temp1);
		robot[N - 1] = 0;

		// 2. 로봇 이동하기 (이동할 칸에 로봇이 없고, 내구성이 0보다 크기)
		for (int i = N - 2; i >= 0; i--)
		{
			if (robot[i] == 1 && belt[i + 1] > 0 && robot[i + 1] == 0)
			{
				robot[i] = 0;
				robot[i + 1] = 1;
				belt[i + 1]--;
			}
		}
		if (robot[N - 1] == 1) robot[N - 1] = 0;

		// 3. 올릴 위치(0)에 내구도 0보다 크고 로봇이 없으면 올리기
		if (belt[0] > 0 && robot[0] == 0)
		{
			belt[0]--;
			robot[0] = 1;
		}

		// 4. 내구도 0인칸 개수 K 이상이면 종료
		int zero = 0;
		for (int i = 0; i < 2 * N; i++)
			if (belt[i] == 0) zero++;
		if (zero >= K) break;
		// 아니면 계속 진행하기
		cnt++;
	}
	cout << cnt + 1;
	return 0;
}

// deque로 진행하기 
//#include <iostream>
//#include <deque>
//using namespace std;
//
//int n, k, zeroPower;
//struct Info {
//	bool isRobot;
//	int power;
//};
//deque<Info> belt;
//
//void input()
//{
//	int power;
//	cin >> n >> k;
//	for (int i = 0; i < 2 * n; i++) {
//		cin >> power;
//		belt.push_back({ false, power });
//	}
//}
//
//void rotate()
//{
//	Info info = belt.back();
//	belt.pop_back();
//	belt.push_front(info);
//	if (belt[n - 1].isRobot) belt[n - 1].isRobot = false;
//}
//
//void moveRobot()
//{
//	for (int i = n - 2; i >= 0; i--) {
//		if (belt[i].isRobot == true && belt[i + 1].isRobot == false && belt[i + 1].power >= 1) {
//			belt[i + 1].isRobot = true;
//			belt[i + 1].power--;
//			if (belt[i + 1].power == 0) zeroPower++;
//			if (i + 1 == n - 1) belt[i + 1].isRobot = false;
//			belt[i].isRobot = false;
//		}
//	}
//}
//
//void addRobot()
//{
//	if (belt[0].power > 0) {
//		belt[0].isRobot = true;
//		belt[0].power--;
//		if (belt[0].power == 0) zeroPower++;
//	}
//}
//
//int solve()
//{
//	int level = 0;
//	while (true) {
//		level++;
//		rotate();
//		moveRobot();
//		addRobot();
//		if (zeroPower >= k) break;
//	}
//	return level;
//}
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	input();
//	cout << solve() << '\n';
//
//	return 0;
//}