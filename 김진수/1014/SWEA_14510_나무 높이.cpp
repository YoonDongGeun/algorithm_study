#include <iostream>
#include <algorithm>

int main(void)
{
	using namespace std;

	int T;
	cin >> T;
	
	for (int tc = 1; tc < T + 1; tc++)
	{
		int N;
		cin >> N;
		int* trees = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> trees[i];
		}

		int *max_tree = max_element(trees, trees + N);

		int odd, even;
		odd = 0;
		even = 0;
		for (int i = 0; i < N; i++)
		{
			int water = *max_tree - trees[i];
			even += water / 2;

			if (water % 2)
			{
				odd += 1;
			}

		}
	
		delete[] trees;

		while (even - odd > 1)
		{
			even -= 1;
			odd += 2;
		}

		int result;
		if(odd > even)
		{
			result = odd * 2 - 1;
		}
		else
		{
			result = even * 2;
		}
		cout << "#" << tc << " " << result << endl;
	}

	
	return 0;
}