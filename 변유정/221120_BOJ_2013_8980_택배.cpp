#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 알고리즘 : 그리디, 정렬
// 참고 : https://j3sung.tistory.com/504
// 중요한 점: 예제를 잘 보면서 어떤 순으로 정렬을 진행하고 더해줘야하는지
// 잘 생각해야 한다!

int N, C, M;
int box[2001];
vector <pair<pair<int, int>, int>> vect;
bool compare(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
{
	if (a.first.second == b.first.second)
		return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	cin >> M;

	int to, from, w;
	for (int i = 0; i < M; i++)
	{
		cin >> to >> from >> w;
		vect.push_back({ {to, from},w });
	}
	sort(vect.begin(), vect.end(), compare);
	int result = 0;
	int temp = 0;
	for (int i = 0; i < vect.size(); i++)
	{
		temp = 0;
		for (int j = vect[i].first.first; j < vect[i].first.second; j++)
			temp = max(temp, box[j]);
		temp = min(C - temp, vect[i].second);
		result += temp;

		for (int j = vect[i].first.first; j < vect[i].first.second; j++)
			box[j] += temp;
	}
	cout << result;
}