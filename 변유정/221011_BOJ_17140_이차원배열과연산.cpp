#include <iostream>
#include <cstring>
using namespace std;

// 구현 + 시뮬레이션
// 
// 1. r,c,k  - arr[r][c] == k 인지 확인 
// 2. 배열 인덱스 (R연산 || C연산 행하기
// 3. 반복 - 만약 최소시간이 100초를 넘어가게 되면 -1 출력
// 
// 배열 범위 - 행, 열 크기가 100을 넘어가게 되면 자르게 되어있기 때문에, 모두 100으로 맞추기

int r, c, k;
int arr[101][101];
int nr = 3; // 행
int nc = 3; // 열

void make_arr()
{
	int temp[101][101];
	memset(temp, 0, sizeof(temp));
	// R 연산 - 모든 행에 대해서 정렬 수행
	if (nr >= nc)
	{
		for (int y = 1; y <= nr; y++)
		{
			int num[101] = { 0, };
			int mx_num = -1;
			for (int x = 1; x <= nc; x++)
			{
				mx_num = max(mx_num, arr[y][x]);
				num[arr[y][x]]++;
			}
			int s_idx = 1;
			for (int i = 1; i <= nc; i++)
				for (int k = 1; k <= mx_num; k++)
				{
					if (num[k] == i)
					{
						temp[y][s_idx] = k;
						s_idx++;
						temp[y][s_idx] = i;
						s_idx++;
					}
				}
			s_idx--;
			nc = max(nc, s_idx);
		}
	}
	// C 연산 - 모든 열에 대해서 정렬 수행
	else
	{
		for (int x = 1; x <= nc; x++)
		{
			int num[101] = { 0, };
			int mx_num = -1;
			for (int y = 1; y <= nr; y++)
			{
				mx_num = max(mx_num, arr[y][x]);
				num[arr[y][x]]++;
			}
			int s_idx = 1;
			for (int i = 1; i <= nr; i++)
				for (int k = 1; k <= mx_num; k++)
				{
					if (num[k] == i)
					{
						temp[s_idx][x] = k;
						s_idx++;
						temp[s_idx][x] = i;
						s_idx++;
					}
				}
			s_idx--;
			nr = max(nr, s_idx);
		}
	}

	memset(arr, 0, sizeof(arr));
	for (int y = 1; y <= nr; y++)
		for (int x = 1; x <= nc; x++)
			arr[y][x] = temp[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> k;
	for (int y = 1; y <= 3; y++)
		for (int x = 1; x <= 3; x++)
			cin >> arr[y][x];
	int time = 0;
	while (time <= 100)
	{
		if (arr[r][c] == k) break;
		make_arr();
		time++;
	}
	if (time > 100) cout << -1;
	else cout << time;
}