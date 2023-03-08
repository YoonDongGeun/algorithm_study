#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, A, S, P, M, Q;
vector <pair<int, int>> customer[100010];
set <int> number;
vector <pair<int, long long>> ans;

long long sum_num(int num)
{
	long long smm = 0;
	for (int i = 1; i <= N; i++)
	{
		int tmp = 0;
		for (int j = 0; j < customer[i].size(); j++)
		{
			if (customer[i][j].first > num) continue;
			tmp = max(customer[i][j].second, tmp);
		}
		smm += tmp;
	}
	return smm;
}

void return_num()
{
	for (set<int>::iterator iter = number.begin(); iter != number.end(); iter++)
		ans.push_back({ *iter, sum_num(*iter) });
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		for (int j = 0; j < A; j++)
		{
			cin >> S >> P;
			customer[i].push_back({ S,P });
			number.insert(S);
		}
	}
	return_num();
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> Q;
		bool flag = 0;
		for (int j = 0; j < ans.size(); j++)
		{
			if (ans[j].second >= Q)
			{
				cout << ans[j].first << " ";
				flag = 1;
				break;
			}
		}
		if (!flag) cout << -1 << " ";
	}
	return 0;
}