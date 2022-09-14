#include <iostream>
using namespace std;
void search(int arr[], int n);
int N;
int main()
{

	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int M;
	cin >> M;
	search(arr, M);

	int cnt, button;
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != -2)
		{
			button = 0;
			for (int j = 0; j < N; j++)
			{
				if (arr[j] == i)
				{
					button = 1;
					break;
				}
			}
			if (button == 0)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}


void search(int arr[], int n)
{
	arr[n] = -2;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == n)
		{
			search(arr, i);
		}
	}
}