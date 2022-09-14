#include <iostream>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int s, a, b;
	int cnt = 1;
	cin >> n >> m;
	n = n + 1;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> s >> a >> b;
		if (s == 0)
		{
			if (a == b)
				continue;

			if (arr[a] != 0 && arr[b] != 0)
			{
				if (arr[a] == arr[b])
					continue;
				int temp = arr[b];
				for (int j = 0; j < n; j++)
				{
					if (arr[j] == temp)
					{
						arr[j] = arr[a];
					}
				}
			}
			else if (arr[a] != 0)
			{
				arr[b] = arr[a];
			}
			else if (arr[b] != 0)
			{
				arr[a] = arr[b];
			}
			else
			{
				arr[a] = cnt;
				arr[b] = cnt;
				cnt++;
			}

		}
		else
		{

			if (a == b)
			{
				cout << "YES" << '\n';
			}
			else
			{
				if (arr[a] == arr[b] && arr[a] != 0)
					cout << "YES" << '\n';
				else
					cout << "NO" << '\n';
			}
		}
	}

	return 0;
}