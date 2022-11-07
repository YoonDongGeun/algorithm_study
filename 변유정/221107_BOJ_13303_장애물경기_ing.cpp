#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

// 알고리즘 : 자료구조, 트리구조 활용
// set 활용해야함

struct Data {
	int x, yl, yh;
};
int N, sy, ex;
struct Data1 {
	int y, x, leng, idx;
};
vector <Data> load;
queue <Data1> q;
set <int> sets;
bool cmp(const Data & a, const Data & b)
{
	return a.x < b.x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cin >> sy >> ex;
	q.push({ sy,0,ex,0 });
	for (int i = 0; i < N; i++)
	{
		int x, yl, yh;
		cin >> x >> yl >> yh;
		load.push_back({ x,yl,yh });
	}
	int ans = 1e9;
	sort(load.begin(), load.end(),cmp);

	while (!q.empty())
	{
		Data1 next = q.front();
		q.pop();
		int nidx = next.idx;
		while (nidx < load.size())
		{
			if (load[nidx].yh > next.y && load[nidx].yl < next.y)
			{
				q.push({ load[nidx].yh, load[nidx].x, next.leng + load[nidx].yh - next.y, nidx });
				q.push({ load[nidx].yl, load[nidx].x, next.leng + next.y - load[nidx].yl,nidx });
				break;
			}
			nidx++;
		}
		if (nidx == load.size())
		{
			if (ans > next.leng)
			{
				ans = next.leng;
				sets.clear();
				sets.insert(next.y);
			}
			else if (ans == next.leng)
				sets.insert(next.y);
		}
	}
	cout << ans << '\n';
	cout << sets.size() << " ";
	for (set<int>::iterator iter=sets.begin();iter != sets.end();iter++)
		cout << *iter << " ";
}