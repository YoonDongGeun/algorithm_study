#include <iostream>
using namespace std;


int main(void)
{
	int N, temp, max=0;
	int A[1001];
	int B[1001];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];  //n번쨰 수열까지 저장,
	}


	B[0] = 1; // 처음에 수열 길이 1로 시작. n번째 수열의 최대 길이 저장.
	for (int i = 0; i < N; i++)
	{
		temp = 1;
		for (int j = 0; j < i; j++) // n번쨰 수보다 왼쪽의 값중 작은 값들에서 가장 길이가 긴 것+1 저장.
		{
			if (A[j] < A[i])
			{
				if (temp < B[j] + 1)
				{
					temp = B[j] + 1;
				}
			}
		}
		if (max < temp)
		{
			max = temp;
		}
		B[i] = temp;
	}
	cout << max;

}