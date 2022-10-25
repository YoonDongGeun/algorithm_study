#include <iostream>
using namespace std;

int N, score[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, score[1001];
	int mxx = -1, mnn = 1e9;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
		if (mxx < score[i]) mxx = score[i];
		if (mnn > score[i]) mnn = score[i];
	}
	cout << mxx - mnn;
}