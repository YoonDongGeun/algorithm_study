#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/// SWEA 특이한 자석 응용버전(?)
/// 
/// 방향 배열 먼저 구해주고 회전

int N, K;
vector <string> wheel;
int dd[1000] = { 0, };
int ans = 0;

void direction(int idx, int dir) // 1. 방향 설정하기
{
	int left = idx ,dir_l = dir; //왼쪽,오른쪽 방향, 현재 위치 설정
	int right = idx,dir_r = dir;
	dd[idx] = dir; // 현재 기준 방향 저장하기
	while (left > 0) // 왼쪽부터
	{
		if (wheel[left][6] != wheel[left - 1][2])
		{
			if (dir_l == 1)
			{
				dd[left - 1] = -1;
				dir_l = -1;
			}
			else
			{
				dd[left - 1] = 1;
				dir_l = 1;
			}
			left--;
		}
		else break; // 같은 값이 나오면 다음부터는 회전을 안하기 때문에 정지
	}
	while (right < N -1)
	{
		if (wheel[right][2] != wheel[right + 1][6])
		{
			if (dir_r == 1)
			{
				dd[right + 1] = -1;
				dir_r = -1;
			}
			else
			{
				dd[right + 1] = 1;
				dir_r = 1;
			}
			right++;
		}
		else break;
	}
}

void turn() // 2. 회전
{
	for (int i = 0; i < N; i++)
	{
		if (dd[i] == 1)
		{
			char temp = wheel[i][7];
			wheel[i].erase(wheel[i].end()-1);
			wheel[i].insert(wheel[i].begin(),temp);
		}
		else if (dd[i] == -1)
		{
			char temp = wheel[i][0];
			wheel[i].erase(wheel[i].begin());
			wheel[i] += temp;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp; // 톱니바퀴 방향 string으로 받기
		cin >> temp;
		wheel.push_back(temp);
	}
	
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int idx, dir;
		cin >> idx >> dir;
		direction(idx-1, dir);
		turn();
		memset(dd, 0, sizeof(dd)); // 방향배열 초기화
	}

	for (int i = 0; i < N; i++)
		if (wheel[i][0] == '1') ans++;

	cout << ans;
	return 0;
}


// 이건 배열 진짜로 바꾸면서 하는게 아니라, 0시 방향 기준을 저장해놓고 돌리기(!)
//
//int state[1001], change[1001];
//string str[1001];
//
//int main(void) {
//	cin.tie(0);
//	ios::sync_with_stdio(0);
//
//	int n, q, num, x;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> str[i];
//
//	cin >> q;
//	while (q--) {
//		memset(change, 0, sizeof(change));
//		cin >> num >> x;
//		x = -x;
//		change[num] = x;
//		for (int j = num + 1, t = -x; j <= n; j++) {
//			if (str[j][(state[j] + 6) % 8] == str[j - 1][(state[j - 1] + 2) % 8]) break;
//			change[j] = t;
//			t = -t;
//		}
//		for (int j = num - 1, t = -x; j >= 1; j--) {
//			if (str[j][(state[j] + 2) % 8] == str[j + 1][(state[j + 1] + 6) % 8]) break;
//			change[j] = t;
//			t = -t;
//		}
//		for (int i = 1; i <= n; i++)
//			state[i] = (state[i] + change[i] + 8) % 8;
//	}
//
//	num = 0;
//	for (int i = 1; i <= n; i++) num += (str[i][state[i]] == '1');
//	cout << num;
//	return 0;
//}