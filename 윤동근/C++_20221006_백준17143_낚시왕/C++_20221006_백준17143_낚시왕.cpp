#include <iostream>
struct sh {
	int v;				// 상어 속도
	int d;				// 상어 방향     1=위, 2=아래, 3=오른쪽, 4=왼쪽
};


int main(void)
{
	int R, C, M, y, x, v, d, size, ch, sum_size, ch2, recur_X, recur_Y, dx, dy;
	sh shark[10001];
	int SH[101][101][2];
	std::cin >> R >> C >> M; // R y길이, C x길이, M 상어 수
	for (int i = 1; i <= C; i++)                   // 초기화
	{
		for (int j = 1; j <= R; j++)
		{
			SH[j][i][0] = 0;
			SH[j][i][1] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		std::cin >> y >> x >> v >> d >> size;         //y위치,x위치,속도,방향,크기
		SH[y][x][0] = size;
		shark[size] = { v,d };
	}


	ch = 0, sum_size = 0, recur_X = 2*(C-1), recur_Y = 2*(R-1);
	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)        //i는 1칸, 1초, 
		{
			if (SH[j][i][ch])
			{
				sum_size += SH[j][i][ch];    // 잡은 상어 크기만큼 더하기
				SH[j][i][ch] = 0;            // 잡은 상어 없애기
				break;                       // 잡으면 넘어가기
			}
		}
		if (i == C)                           // 맨 오른쪽 에서 잡았으면 그만 하기.
		{
			break;
		}

		ch2 = ch;                            // 차원 ch, ch2가 있는데, ch에는 움직인 후의 상어 위치가 갱신.
		ch = (++ch) % 2;
		for (int j = 1; j <= R; j++)             //y
		{
			for (int k = 1; k <= C; k++)         //x
			{
				if (size = SH[j][k][ch2])       // size 가 0 아니면 있는거
				{
					SH[j][k][ch2] = 0;         // 움직일 상어는 0으로 초기화하고 ch 차원에서 옮긴 위치 설정
					v = shark[size].v; 
					d = shark[size].d;
					if (d == 1)					// 위
					{
						v %= recur_Y;
						if (v < j - 1)                     //맨위로 가는방향
						{
							dy = j - v;
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
							}
						}
						else if (j - 1 <= v && v < j + R - 2)    // 맨 위에서 아래로 가는방향 1에서 R로
						{
							dy = 2 + v - j;
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
								shark[size].d = 2;
							}
						}
						else if (j + R - 2 <= v && v < j + R + R - 3)   // 맨 아래에서 위로 가는 방향 R에서 1로
						{
							dy = R + R - v + j - 2;
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
							}
						}										  //  1에서 제자리로
						else
						{
							dy = j - recur_Y + v;
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
								shark[size].d = 2;
							}
						}
					}
					else if (d == 2)			// 아래
					{
						v %= recur_Y;
						if (v < R-j)
						{
							dy = j + v;
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
							}
						}
						else if (R-j <= v && v < R+R-j-1)    // R 에서 1로
						{
							dy = R - (v - R + j);
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
								shark[size].d = 1;
							}
						}
						else if (R+R-j-1 <= v && v < R+R+R-j-2)   // 1 에서 R로
						{
							dy = v + 2 - R - R + j;
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
							}
						}										  //  R에서 제자리로
						else
						{
							dy = j + recur_Y - v;
							if (SH[dy][k][ch] < size)
							{
								SH[dy][k][ch] = size;
								shark[size].d = 1;
							}
						}
					}
					else if (d == 3)			// 오른쪽으로
					{
						v %= recur_X;
						if (v < C - k)
						{
							dx = k + v;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
							}
						}
						else if (C - k <= v && v < C + C - k - 1)    // C 에서 1로
						{
							dx = C + C - v - k;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
								shark[size].d = 4;
							}
						}
						else if (C + C - k - 1 <= v && v < C + C + C - k - 2)   // 1 에서 C로
						{
							dx = 2 + v + k - C - C;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
							}
						}										  //  C에서 제자리로
						else
						{
							dx = k + recur_X - v;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
								shark[size].d = 4;
							}
						}
					}
					else                        // 왼쪽
					{
						v %= recur_X;
						if (v < k - 1)                   // 처음자리에서 왼쪽
						{
							dx = k - v;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
							}
						}
						else if (k - 1 <= v && v < k + C - 2)   // x좌표 1에서 오른쪽
						{
							dx = 2 + v - k;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
								shark[size].d = 3;
							}
						}
						else if (k + C - 2 <= v && v< k + C + C - 3)  // x좌표 C에서 다시 왼쪽
						{
							dx = C + C - v + k - 2;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
							}
						}								
						else                                        // x좌표 1에서 다시 원래 위치로
						{
							dx = k - recur_X + v;
							if (SH[j][dx][ch] < size)
							{
								SH[j][dx][ch] = size;
								shark[size].d = 3;
							}
							
						}
					}
				}
			}
		}
	}
	std::cout << sum_size << '\n';
	return 0;
}