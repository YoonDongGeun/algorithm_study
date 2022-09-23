#include <iostream>
#include <vector>
using namespace std;

void comb(vector<int> &a,int *b ,int *c, int d, int &sum, int &B, int &max) {	// a 키 리스트, b 사용한 사람, c 사람 수, d 몇번 싸이클인지, sum 키의 합, B 달성해야하는 키, max 달성해야하는 키와 가장 가까운 키.
	if (sum >= B and sum<max) {
			max = sum;
	}
	for (int i = d; i < *c; i++)
	{
		if (!b[i])
		{
			b[i] = 1;
			sum += a[i];
			comb(a, b, c, i, sum, B, max);
			sum -= a[i];
			b[i] = 0;

		}

	}
}

int main() {
	int T, N, B, temp, sum, max;
	vector<int> L;
	int used[20] = { 0, };
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		sum = 0;
		max = 200000;
		cin >> N >> B;
		for (int w = 0; w < N; w++)
		{
			cin >> temp;
			L.push_back(temp);
		}
		comb(L, used, &N, 0, sum, B, max);
		cout << '#' << q << ' ' << max-B << '\n';
		L.clear();
	}
}