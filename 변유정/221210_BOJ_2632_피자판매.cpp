#include <iostream>
using namespace std;

// 알고리즘 : 누적합, 이분탐색
// 구현 방법 : 가능한 경우의 수를 미리 다 구하고 풀었음
// 아래 방법 : A를 우선 구해놓고, B의 조합을 구하면서 더해줌 (더 나은방법)

int custom, A, B,pizzaA[1001], pizzaB[1001];
// custom : 고객 원하는 피자 사이즈
// A : A피자 조각 개수, B: B피자 조각 개수
// pizzaA : A피자 조각 당 크기 , pizzaB : B피자 조각 당 크기
int pieceA[2000001] = { 0, }; // 피자 조각 조합 크기 별 개수
int pieceB[2000001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> custom;
	cin >> A >> B;
	for (int i = 0; i < A; i++)
		cin >> pizzaA[i];
	for (int i = 0; i < B; i++)
		cin >> pizzaB[i];
	
	// A피자 조각 조합 : 피자 조각 출발 순서를 다르게 해주기
	// 이어져 있어야 하기 때문에 순서대로 하나씩 더해주기
	for (int i = 0; i < A; i++)
	{
		int temp = pizzaA[i];
		pieceA[temp]++;
		for (int j = 1; j < A-1; j++)
		{
			temp += pizzaA[(i + j) % A];
			pieceA[temp]++;
		}
		if (i == 0) // 전체 A피자 조각 크기 합
		{
			temp += pizzaA[A - 1];
			pieceA[temp]++;
		}
	}
	// B피자 조각 조합
	for (int i = 0; i < B; i++)
	{
		int temp = pizzaB[i];
		pieceB[temp]++;
		for (int j = 1; j < B-1; j++)
		{
			temp += pizzaB[(i + j) % B];
			pieceB[temp]++;
		}
		if (i == 0)
		{
			temp += pizzaB[B-1];
			pieceB[temp]++;
		}
	}
	int cnt = 0;
	cnt += pieceA[custom] + pieceB[custom]; 
	// A조각 , B조각 조합에서 custom 크기가 있는 것 끼리 더해주기
	for (int i = 1; i < custom; i++)
		cnt += (pieceA[i] * pieceB[custom - i]);
		// 조합끼리 나올 수 있는 경우의 수 더해주기
	cout << cnt;
}

//int x[2001], y[2001];
//int s[2000001];
//int main()
//{
//	int n, a, b, i, j, cnt = 0, sum;
//	scanf("%d%d%d", &n, &a, &b);
//	for (i = 0; i < a; i++)
//		scanf("%d", &x[i]);
//	for (i = a; i < a * 2; i++)
//		x[i] = x[i - a];
//	for (i = 0; i < b; i++)
//		scanf("%d", &y[i]);
//	for (i = b; i < b * 2; i++)
//		y[i] = y[i - b];
//
//	for (i = 0; i < a; i++)
//	{
//		sum = 0;
//		for (j = i; j < i + a - 1; j++)
//		{
//			sum += x[j];
//			s[sum]++;
//		}
//	}
//	sum = 0;
//	for (i = 0; i < a; i++)
//		sum += x[i];
//	s[sum]++;
//	for (i = 0; i < b; i++)
//	{
//		sum = 0;
//		for (j = i; j < i + b - 1; j++)
//		{
//			sum += y[j];
//			if (sum <= n)
//				cnt += s[n - sum];
//			if (sum == n)
//				cnt++;
//		}
//	}
//	sum = 0;
//	for (i = 0; i < b; i++)
//		sum += y[i];
//	if (sum <= n)
//		cnt += s[n - sum];
//	if (sum == n)
//		cnt++;
//	printf("%d", cnt + s[n]);
//}