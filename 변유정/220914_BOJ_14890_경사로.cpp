#include <iostream>
using namespace std;
// 'SWEA 활주로 건설'과 같은 문제

//  시뮬레이션 + 구현
//  구현할때 구체적으로 단계 설정하고 짜야한다
//  A형에서 구현문제가 주로 나오기 때문에 이런 문제를 자주 풀어봐야한다

// 구현 단계
// 1. 높이차 없이 일정할때
// 2. 높이차가 있으면 오른쪽방향으로 (높 > 낮) 반복문으로 경사로 확인
// 3. 오른쪽방향 문제 없으면 왼쪽방향으로 (높 > 낮) 반복문으로 경사로 확인
// 4. 문제 없으면 답에 1 더해주기

// 2-1. 높이차가 1로 일정해야함. 1 초과로 가면 flag 활용해서 멈추고 다음 줄로 넘어가기

int N, L;
int road[101][101];
int used_y[101][101] = {0,};
int used_x[101][101] = {0,};
int ans = 0;

// 1. 높이차가 없을 때
int same_y(int y)
{
	for (int i = 0; i < N-1; i++)
		if (road[y][i] != road[y][i + 1]) return 0;
	return 1;
}

int same_x(int x)
{
	for (int i = 0; i < N - 1; i++)
		if (road[i][x] != road[i + 1][x]) return 0;
	return 1;
}

// 2. 높이차가 있을 때
int diff_y(int y, int x, int k)
{
	for (int i = 1; i <= L; i++)
	{
		int a = x + i * k;
		if (a < 0 || a >= N) return 0; // 범위벗어나거나
		if ((road[y][x] - road[y][a]) != 1) return 0; // 높이차가 1 초과이거나
		if (used_y[y][a] == 1) return 0; // 이미 사용된 경사로면 0
		
		used_y[y][a] = 1; // 경사로 사용표시
	}
	return 1;
}

int diff_x(int y, int x, int k)
{
	for (int i = 1; i <= L; i++)
	{
		int a = y + i * k;
		if (a < 0 || a >= N) return 0; 
		if ((road[y][x] - road[a][x]) != 1) return 0;
		if (used_x[a][x] == 1) return 0;
		used_x[a][x] = 1;
	}
	return 1;
}

void fly()
{
	for (int y = 0; y < N; y++)
	{
		int flag = 2;
		if (same_y(y) == 1) ans += 1; // 1. 높이차가 없으면 +
		else // 2. 높이차가 있으면
		{
			for (int i = 0; i < N-1; i++) // 순방향(오른쪽 방향)으로 경사로 탐색
			{
				if (road[y][i] == road[y][i + 1] + 1)
				{
					flag = diff_y(y, i, 1); // 높이차에서 L만큼 높이가 계속되지 않으면 flag = 0
					if (flag == 0) break; // flag에서 높이차에 문제 발생하면 멈춤
				}
				else if (abs(road[y][i] - road[y][i + 1]) > 1)
				{
					flag = 0; break; // 높이차 그냥 2 이상 차이나면 멈춤
				}
			}
			if (flag == 0) continue; // flag에 문제 발생시 무시하고 계속 진행
			for (int i = N - 1; i >= 1; i--) // 문제 없으면 역방향 (왼쪽 방향)으로 경사로 탐색
			{
				if ((road[y][i] - road[y][i - 1]) == 1)
				{
					flag = diff_y(y, i, -1);
					if (flag == 0) break;
				}
				else if (abs(road[y][i] - road[y][i - 1]) > 1)
				{
					flag = 0; break;
				}
			}
		}
		if (flag == 1) ans++;
	}

	for (int x = 0; x < N; x++)
	{
		int flag = 2;
		if (same_x(x) == 1) ans += 1;
		else
		{
			for (int i = 0; i < N -1; i++)
			{
				if (road[i][x] - road[i + 1][x] == 1)
				{
					flag = diff_x(i, x, 1);
					if (flag == 0) break;
				}
				else if (abs(road[i][x] - road[i + 1][x]) > 1)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 0) continue;
			for (int i = N - 1; i >= 1; i--)
			{
				if ((road[i][x] - road[i - 1][x]) == 1)
				{
					flag = diff_x(i, x, -1);
					if (flag == 0) break;
				}
				else if (abs(road[i][x] - road[i - 1][x]) > 1)
				{
					flag = 0; break;
				}
			}
		}
		if (flag == 1) ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> road[y][x];
	fly();
	cout << ans;
	return 0;
}


//// 숏코딩 (남의것)
// 
// 구현 문제는 다양한 방법으로 가능
// 앞으로 불필요한 코드는 줄이려는 연습을 해야함
// 
//#include <cstdio>
//int main() {
//	int n, l, ans = 0, i, j, c;
//	short a[200][100];
//	scanf("%d %d", &n, &l);
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			scanf("%hd", &a[i][j]);
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			a[i + n][j] = a[j][i];
//	for (i = 0; i < n * 2; i++) {
//		c = 1;
//		for (j = 0; j < n - 1; j++) {
//			if (a[i][j] == a[i][j + 1]) c++;
//			else if (a[i][j] + 1 == a[i][j + 1] && c >= l) c = 1;
//			else if (a[i][j] - 1 == a[i][j + 1] && c >= 0) c = -l + 1;
//			else break;
//		}
//		if (j == n - 1 && c >= 0) ans++;
//	}
//	printf("%d", ans);
//	return 0;
//}
