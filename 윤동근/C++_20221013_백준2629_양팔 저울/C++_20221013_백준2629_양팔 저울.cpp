#include <iostream>
int weight[31];
int visited[15001] = { 0, };
int P[30][15001] = { 0, };
int ball[7];	
int N, M, sum = 0;
void search(int *left, int *right, int now)
{
	int div = *left > *right ? *left - *right : *right - *left;
	if (!visited[div])
	{
		visited[div] = 1;
		
	}
	if (now == N+1)
	{
		return;
	}
	if (!P[now-1][div])
	{
		P[now - 1][div] = 1;                 // 중복 방지
		search(left, right, now + 1);        // 왼쪽
		*left += weight[now];
		search(left, right,  now+1);         // 오른쪽
		*left -= weight[now];
		*right += weight[now];
		search(left, right,  now+1);        // X
		*right -= weight[now];
	}
}

int main(void)
{
	std::cin >> N;
	for (int i = 1; i <= N; i++)
	{
		std::cin >> weight[i];
		sum += weight[i];
	}
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> ball[i];
	}
	int left = 0, right = 0;	
	search(&left, &right, 1);

	for(int i=0; i<M; i++)
	{
		if (ball[i] > sum)
		{
			std::cout << 'N' << ' ';
		}
		else
		{
			if (visited[ball[i]])
				std::cout << 'Y' << ' ';
			else
				std::cout << 'N' << ' ';
		}
		
	}

	return 0;
}