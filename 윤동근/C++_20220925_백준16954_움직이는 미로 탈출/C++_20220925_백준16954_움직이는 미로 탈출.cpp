#include <iostream>
struct way{
	int y;
	int x;
};
// 1. 움직이는 위치에 벽이 있는지 체크
// 2. 움직이는 위치의 위쪽에 벽이 있는지 체크
// 3. 밑에서 4번째 칸에 도착하면 완성

int main(void) {
	char M[8][9];
	int y, x, ny, nx, sol = 0, cnt = 0;
	int const save = 1 << 13;
	way pos[save] = { {7,0} };
	way move[9] = { {0,0},{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
	int pb = 0, pm = 0, pt = 1;


	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			std::cin >> M[i][j];
		}

	while (pt - pb)						// 큐의 시작점과 끝점이 만나면 break
	{
		pm = pt;
		while (pm - pb) {				// 큐의 시작점이 중간점까지 만나면 break;
			y = pos[pb].y;
			x = pos[pb].x;
			if (y == 3) {
				sol = 1;
				break;
			}
			
			for (int i = 0; i < 9; i++)	// 9가지 움직이는 방향 탐색
			{
				ny = y + move[i].y;
				nx = x + move[i].x;
				if (3 > ny || ny > 7 || 0 > nx || nx > 7)	// 범위 벗어나면 넘어가기
					continue;
				if (M[ny][nx] == '#' or M[ny - 1][nx] == '#')	// 벽이거나, 움직이는곳 위쪽에 벽이 있으면 넘어가기
					continue;
				pos[pt].y = ny;
				pos[pt].x = nx;
				pt++;
				pt &= ~save;
			}
			pb++;
			pb &= ~save;										// 큐 차면 초기화
		}
		if (sol)
			break;
		for (int i = 7; i > cnt; i--)
		{
			for(int j=0; j<8; j++)
				M[i][j] = M[i - 1][j];
		}
		for (int j = 0; j < 8; j++)
			M[cnt][j] = '.';
		cnt++;
	}
	std::cout << sol;
}