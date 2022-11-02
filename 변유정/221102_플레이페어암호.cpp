#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 알고리즘 : 구현, 시뮬레이션
// 놓치기 쉬운 부분 : 연속된 같은 문자열은 X -> Q 로 바뀜
// 예시에 J 가 없어서 놓칠 수 있다! J -> I로 바꿔주기
// '구현' 문제서 제일 중요한 것 : 언급한것들은 그냥 다 해주기...

// vector - alpha : 알파벳 순서에 따라 좌표 저장
// beta : 좌표에 따라 알파벳 저장

string message, key;
bool used[26] = { 0, };
vector <pair<int, int>> alpha(26);
int beta[5][5] = { 0, };

void odd(int leng)
{
	int idx = 0;
	while (idx < leng)
	{
		int aa, bb;
		aa = message[idx] - 'A';
		if (aa == 9) aa = 8;
		idx += 1;
		if (idx < leng)
		{
			bb = message[idx] - 'A';
			if (bb == 9) bb = 8;
			if (aa == bb)
			{
				if (aa == 23) bb = 16;
				else bb = 23;
			}
			else idx += 1;
		}
		else bb = 23;

		if (alpha[aa].first == alpha[bb].first)
		{
			int y = alpha[aa].first;
			int ax = alpha[aa].second;
			int bx = alpha[bb].second;
			ax++; bx++;
			if (ax == 5) ax = 0;
			if (bx == 5) bx = 0;
			cout << char(beta[y][ax] + 'A') << char(beta[y][bx] + 'A');
		}
		else if (alpha[aa].second == alpha[bb].second)
		{
			int x = alpha[aa].second;
			int ay = alpha[aa].first;
			int by = alpha[bb].first;
			ay++; by++;
			if (ay == 5) ay = 0;
			if (by == 5) by = 0;
			cout << char(beta[ay][x] + 'A') << char(beta[by][x] + 'A');
		}
		else
		{
			cout << char(beta[alpha[aa].first][alpha[bb].second] + 'A');
			cout << char(beta[alpha[bb].first][alpha[aa].second] + 'A');
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> message >> key;
	int y = 0;
	int x = 0;
	used[9] = 1;
	for (int i = 0; i < key.length(); i++)
	{
		int idx = key[i] - 'A';
		if (idx == 9) idx = 8;
		if (used[idx]) continue;
		used[idx] = 1;
		alpha[idx] = {y,x};
		beta[y][x] = idx;
		x++;
		if (x == 5)
		{
			y++;
			x = 0;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (used[i]) continue;
		beta[y][x] = i;
		alpha[i] = { y,x };
		x++;
		if (x == 5)
		{
			y++;
			x = 0;
		}
	}
	int leng = message.length();
	odd(leng);
	return 0;
}