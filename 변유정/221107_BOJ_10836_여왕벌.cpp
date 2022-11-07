#include <iostream>
using namespace std;

// 알고리즘 : 구현, 시뮬레이션

// 시간 줄이는 방법 : 반복하는 지점을 찾고 배열 크기를 줄여야 한다
// 배열 0열을 제외하고 나머지는 첫 행을 반복하고 있기 때문에 굳이 모든 배열의 값을 저장할 필요가 없다.

// 위 : 100점 / 아래 : 83점 (모든 배열 저장하고 사용)
int M, N, larva[1401] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int k = 0;
		while (a--)
		{
			k++;
		}
		while (b--)
		{
			larva[k++]++;
		}
		while (c--)
		{
			larva[k++] += 2;
		}
	}
	for (int s = M - 1; s >= 0; s--)
	{
		cout << larva[s] + 1 << ' ';
		for (int p = M; p < 2 * M - 1; p++)
			cout << larva[p] + 1 << ' ';
		cout << '\n';
	}
}

//int M, N, larva[701][701] = { 0, };
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> M >> N;
//	for (int y = 0; y < M; y++)
//		for (int x = 0; x < M; x++)
//			larva[y][x] = 1;
//	for (int i = 0; i < N; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		int y = M - 1;
//		int x = 0;
//		while (a--)
//		{
//			if (y == 0) x++;
//			else y--;
//		}
//		while (b--)
//		{
//			larva[y][x] += 1;
//			if (y == 0) x++;
//			else y--;
//		}
//		while (c--)
//		{
//			larva[y][x] += 2;
//			if (y == 0) x++;
//			else y--;
//		}
//	}
//	for (int p = 0; p < M; p++)
//	{
//		cout << larva[p][0] << ' ';
//		for (int t = 1; t < M; t++)
//			cout << larva[0][t] << ' ';
//		cout << '\n';
//	}
//}