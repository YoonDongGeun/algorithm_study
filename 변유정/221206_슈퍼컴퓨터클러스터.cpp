#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long B;

vector <int> cluster;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> B;
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		cluster.push_back(a);
	}
	sort(cluster.begin(), cluster.end());
	long long right = 2000000000;
	long long left = cluster[0];
	cout << left << '\n';
	while (right - left > 1)
	{
		long long mid = (right + left) / 2;
		long long cost = 0;
		int found = 1;
		for (int i = 0; i < N; i++)
		{
			if (cluster[i] < mid)
			{
				cost += (mid - cluster[i]) * (mid - cluster[i]);
				if (cost > B)
				{
					right = mid;
					found = 0;
					break;
				}
			}
		}
		if (found) left = mid;
	}
	cout << left;
}