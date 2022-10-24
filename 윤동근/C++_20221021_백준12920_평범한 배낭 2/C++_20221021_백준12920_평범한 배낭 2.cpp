#include <iostream>
#include <algorithm>
using namespace std;
struct VCK {
	int V;
	int C;
	int K;
};

int N, M;
VCK item[101];
int DP[101][10001] = { 0, };
bool comp(VCK a, VCK b);
void search(int M);



int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> item[i].V >> item[i].C >> item[i].K;
	}
	sort(item+1, item + (N+1), comp);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			DP[i][j] = item[i].K;
		}
	}
	for (int i = 0; i <= M; i++)
	{
		DP[0][i] = 0;
	}


	for (int i = 1; i <= M; i++)
	{
		search(i);
	}

	cout << DP[0][M]<< '\n';

	return 0;
}



bool comp(VCK a, VCK b)
{
	return (a.V < b.V);
}

void search(int K)
{
	int temp = -1;
	for (int i = 1; i <=N; i++)
	{
		int mass = K - item[i].V;
		if (mass >= 0)
		{
			int nm = DP[0][mass] + item[i].C;
			if (DP[i][mass] && DP[0][K] < nm && DP[0][K-1] < nm)
			{
				DP[0][K] = nm;
				temp = i;
			}
		}
		else
		{
			break;
		}
	}

	if (temp != -1)
	{
		for (int j = 1; j <= N; j++)
		{
			DP[j][K] = DP[j][K - item[temp].V];
		}
		DP[temp][K] -= 1;
	}
	else
	{
		DP[0][K] = DP[0][K-1];
		for (int j = 1; j <= N; j++)
		{
			DP[j][K] = DP[j][K -1];
		}

	}

}
