#include <iostream>
#include <vector>
using namespace std;

int N, num, A, B;
vector <int> vect[110];
char alpha[110], temp;

void ff(int nn)
{
	if (vect[nn].size() >= 1) ff(nn * 2);
	cout << alpha[nn];
	if (vect[nn].size() == 2)ff(nn * 2 + 1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int tc = 1; tc <= 10; tc++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num >> temp;
			alpha[num] = temp;
			if (num * 2 == N)
			{
				cin >> A;
				vect[num].push_back(A);
			}
			else if (num * 2 < N)
			{
				cin >> A >> B;
				vect[num].push_back(A);
				vect[num].push_back(B);
			}
		}
		cout << "#" << tc << " ";
		ff(1);
		cout << "\n";
		for (int i = 1; i <= N; i++)
			vect[i].clear();
	}
}