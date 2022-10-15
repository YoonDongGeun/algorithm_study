#include <iostream>
struct QQ {
	int now;
	int con;
};

const int size = 1 << 15;
int DP[15][size];
int max = 0;
QQ Q[size];
int st, ed;
void search(int *N, int M[][15]);

int main(void)
{
	int N;
	char temporary[16];
	int M[15][15] = { 0, };
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> temporary;
		for (int j = 0; j < N; j++)
		{
			M[i][j] = temporary[j] - '0';
			if (i == j)
			{
				M[i][j] = 11;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			DP[i][j] = 10;
		}
	}
	//Q[0] = { 0, 1 }; //now, con
	DP[0][1] = 0;
	for (int i = 1; i < N; i++)
	{
		DP[i][1 | (1 << i)] = M[0][i];
		Q[i - 1] = { i, 1 | (1 << i) }; // 0~ N-2
	}
	st = 0;
	ed = N-1;
	search(&N, M);
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			if (DP[i][j] < 10)
			{
				int cnt = 0;
				for (int k = 0; k < N; k++)
				{
					if (j & 1 << k)
						cnt++;
				}
				if (max < cnt)
				{
					max = cnt;
				}
			}
		}
	}
	std::cout << max << '\n';
}

// DP[target][pos2] 를 구하기 위함. (갈 수 있으니 이 함수에 온것.

void search(int *N, int M[][15]) //1개째,
{
	int now ,con, tg;
	while (st != ed)
	{
		now = Q[st].con;             //현재 위치 처음에 0
		con = Q[st++].con;           //현재 상태 처음에 1<<0;
		st &= ~size;
		for (int i = 1; i < *N; i++)  // i로 가는것에 대해 조사
		{
			if (con & 1 << i)         // 이미 갔으면 넘어가고 안간 곳 가보기. 
			{
				continue;
			}
			tg = con | 1 << i;
			if (DP[i][tg] != 10) //이미 최소값 찾았으면 넘기기.
			{
				continue;
			}
			DP[i][tg] = 11; // DP[갈곳][컨디션에서 갈곳 더해주기];

			for (int j = 1; j < *N; j++)          //0에서 오는건 처음 경우만 있음. 0제외하자.
			{
				if (con & (1 << j)) // 가본적 있는 곳이면 조사한다. // 기존컨디션에서 j에서 온다고 가정.
				{
					if (DP[j][con] <= M[j][i]) // 가본적 있는곳에서 올때, DP값 가치보다 M[가본적][갈곳]이 더 커야함.
					{
						if (DP[i][tg] > M[j][i])
						{
							DP[i][tg] = M[j][i]; // DP에 갈곳을 저장.
						}
					}
				}
			}
			//탐색 끝나면 큐에 저장
			Q[ed].now = i;
			Q[ed++].con = tg;
			ed &= ~size;
		}
	}
}


// 1-2-3-4 경로로 최소 value로 도착하기 