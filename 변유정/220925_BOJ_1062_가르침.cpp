#include <iostream>
using namespace std;

// 비트마스킹
// 과정
// 1. K(허용되는 알파벳) 범위로 나누기
// 1-1. K 가 5보다 작으면 구현 가능한 단어 없음
// 1-2. K가 26이면 모든 알파벳 사용 가능 (언급한 단어 모두 구현가능)

// 2. 알파벳 사용 배열 만들기
// 2-1. antic 은 기본 사용이므로 미리 표시
// 2-2. 나머지 알파벳은 개수에 맞춰서 선택하기

// 3. 개수에 맞춰서 선택한 알파벳 배열로 구현할 수 있는 단어 최대 개수 찾기
// 3-1. 만약 단어 속 알파벳이 선택되지 않았다면 그 단어는 구현 불가능

// 4. 단어 개수 구했으면 되돌려서 2부터 반복

int N, K;
string words[51];
bool used[26];
int ans = -1;

void dfs(int now, int cnt)
{
	if (cnt + 5 == K)
	{
		int teaching = 0;
		for (int idx = 0; idx < N; idx++)
		{
			bool flag = 0;
			// 범위 좁혀주기 (단어 앞,뒤 4글자는 언제나 동일하다)
			for (int k = 4; k < words[idx].size()-4; k++)
			{
				char tt = words[idx][k];
				if (!used[tt - 'a'])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
				teaching++;
		}
		if (ans < teaching)
			ans = teaching;
		return;
	}

	for (int i = now; i < 26; i++)
	{
		if (used[i])
			continue;
		used[i] = 1;
		dfs(i + 1, cnt + 1);
		used[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		words[i] = temp;
	}

	if (K < 5)
		cout << 0;
	else if (K == 26)
		cout << N;
	else
	{
		string ess = "antic";
		for (int i = 0; i < 5; i++)
			used[ess[i] - 'a'] = 1;
		dfs(0, 0);
		cout << ans;
	}
}