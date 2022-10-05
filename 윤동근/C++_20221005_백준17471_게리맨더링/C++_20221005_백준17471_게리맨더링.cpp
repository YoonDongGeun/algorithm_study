#include <iostream>
void check(int i, int visited[], int M[][11], int Q[], int cnt, int N)       //섬 체크
{
	int start = 0, end = 1, now;
	Q[start] = i, visited[i] = cnt;
	while (start != end)
	{
		now = Q[start];
		for (int j = 1; j <= N; j++)
		{
			if (M[now][j] && !visited[j])
			{
				visited[j] = cnt;
				Q[end] = j;
				end++;
			}
		}
		start++;
	}
}

void check2(int *area, int M[][11], int N, int ch, int Q[], int P[])     // 하나의 구역 체크  
{
	int start = 0, end = 1, now;
	while (start != end)
	{
		now = Q[start];
		for (int i = 1; i <= N; i++)
		{
			if (ch&(1 << i) && M[now][i])
			{
				*area += P[i];
				ch &= ~(1 << i);
				Q[end] = i;
				end++;
			}
		}
		start++;
	}
}


void comb(int M[][11], int half, int st, int recur, int N, int ch, int Q[], int P[], int *min, int *sum)
{
	if (recur <= half)
	{
		if (1 <= recur)
		{
			int area1 = 0, area2 = 0;
			for (int i = 1; i <= N; i++)
			{
				if (ch & 1 << i)
				{
					Q[0] = i;
					area1 += P[i];
					check2(&area1, M, N, ch&~(1 << i), Q, P);       // 한쪽 집합
					break;
				}
			}
			for (int i = 1; i <= N; i++)
			{
				if (~ch &(1 << i))
				{
					Q[0] = i;
					area2 += P[i];
					check2(&area2, M, N, ~ch&~(1 << i), Q, P);     // 다른 쪽 집합
					break;
				}
			}

			if (*sum == area1 + area2)
			{
				int sub = abs(area1 - area2);
				if (*min > sub)
				{
					*min = sub;
				}
			}
		}
		for (int j = st; j <= N; j++)                                        // 집합 생성기
		{
			comb(M, half, j + 1, recur + 1, N, ch | 1 << j, Q, P, min, sum);
		}
	}
}


int main(void) {
	int N, i, j, temp, con, sum = 0 , cnt, sum1, sum2, ans, min;
	int M[11][11], P[11], visited[11], Q[11];
	std::cin >> N;

	for (i = 1; i <= N; i++)          //visited 초기화
	{
		for (j = 1; j <= N; j++)
		{
			M[i][j] = 0;
		}
		visited[i] = 0;
	}
	for (i = 1; i <= N; i++)          // 인구수 입력
	{
		std::cin >> P[i];
		sum += P[i];
	}
	cnt = 0;

	for (i = 1; i <= N; i++)         // 인접한것 입력.
	{
		std::cin >> temp;
		if(temp==0)
		{
			cnt++;
			visited[i] = cnt;
		}
		while (temp)
		{
			std::cin >> con;
			M[i][con] = 1;
			temp--;
		}

	}
	for (i = 1; i <= N; i++)          // 입력 받은것 토대로, 구역 개수 세어보기
	{
		for (j = 1; j <= N; j++)
		{
			if (M[i][j] == 1 && !visited[i]) //
			{
				cnt++;
				check(i, visited, M, Q, cnt, N);
			}
		}
	}
	ans = 0, min=1000, sum1 = 0; sum2 = 0;
	switch (cnt)                         // 구역 개수에 따라 시행
	{
	case 1:											  // 구역 1개면 최소값 찾기
		comb(M, N / 2, 1, 0, N, 0, Q, P, &min, &sum);  
		ans = min;
		break;
	case 2:											// 구역 2개면 두개 구역의 차이 반환
		for (i = 1; i <= N; i++)
		{
			if (visited[i] == 1)
			{
				sum1 += P[i];
			}
			else
			{
				sum2 += P[i];
			}
		}
		ans = abs(sum1 - sum2);
		break;
	default:									// 그 외에는 -1 출력
		ans = -1;
		break;
	}
	

	std::cout << ans << '\n';
	return 0;
}