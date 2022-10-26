#include <iostream>
using namespace std;



int main(void)
{
	int N, M;
	int n, m;
	int X1[100][100];
	int X2[100][100];
	int X3[100][100];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> X1[i][j];
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> X2[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < m; j++)
		{
			X3[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)   // 세로 N
	{
		for (int j = 0; j < m; j++) // 가로 m
		{
			for (int k = 0; k < M; k++)
			{
				X3[i][j] += X1[i][k] * X2[k][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < m; j++)
		{
		