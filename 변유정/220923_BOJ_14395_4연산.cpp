#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 사전순 >>> BFS
// 자료형 매우 중요! 범위가 커질 수 있으니 long long으로 바꾸기
// 사전순 : *, +, -, /
// 사전순으로 배열 집어넣기
// 0, 1이 반복으로 사용되게 되면 무한루프로 빠질 수 있다
// 그래서 0, 1 사용했으면 더 사용하지 않게 체크하기

struct play {
	long long num;
	string str;
};
queue <play> pp;
string ans = "-1";
bool used[2];

void program(int goal)
{
	while (!pp.empty())
	{
		play now = pp.front();
		pp.pop();
		if (now.num == goal)
		{
			ans = now.str;
			break;
		}

		long long k = now.num;
		string temp = now.str;
		if (k * k <= goal && k * k != k) pp.push({ k * k, temp + '*' });
		if (2 * k <= goal && 2 * k != k) pp.push({ 2 * k, temp + '+' });

		if (k != 0 && !used[0])
		{
			used[0] = 1;
			pp.push({ 0,temp + '-' });
		}
		if (k != 0 && k != 1 && !used[1])
		{
			used[1] = 1;
			pp.push({ 1, temp + '/' });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long a, b;
	cin >> a >> b;
	
	if (a == b) cout << 0;
	else
	{
		pp.push({ a,"" });
		program(b);
		cout << ans;
	}
}