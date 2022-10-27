#include <iostream>
using namespace std;

// 알고리즘 분류 : 브루트포스 알고리즘

// 구현 단계 : 재귀 사용
// 1. 방 3개의 인원수 차례대로 빼주기
// 2. 0이 되면 ans 출력 1으로 바꾸고 되돌아가기
// 3. 이미 성공했거나, 남은 사람 수가 음수면 되돌아가기

int ans = 0, room[3] = { 0, },sixth;
void nobed(int now, int left)
{
	if (ans == 1 || left < 0) return;
	if (left == 0)
	{
		ans = 1;
		return;
	}
	for (int i = now; i < 3; i++)
		nobed(i, left - room[i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ans = 0;
	for (int i = 0; i < 3; i++)
		cin >> room[i];
	cin >> sixth;
	nobed(0, sixth);
	cout << ans;
	return 0;
}